#include <random>

using namespace System;
using namespace System::Collections::Generic;

ref class NetworkCore
{
private:
	UInt32 numInputs, numHidden, numOutputs;
	UInt32 numEpochs = 0;
	UInt32 countEpochs = 0;
	UInt32 dataLength = 0;
	UInt32 dataLengthScore = 0;
	Double LR_H1 = 0.01;
	Double LR_HO = 0.05;
	Double alfa = 0.5;
	Char Fun_H0 = 'e';
	Char Fun_H1 = 't';
	Double error_H0;
	Double mse;
	array<Double, 2>^ trainInputs;
	array<Double, 2>^ tempInputs;
	array<Double, 2>^ trainOutput;
	array<Double, 2>^ tempOutput;
	array<Double, 2>^ scoreInputs;
	array<Double>^ error;
	array<Double>^ mseEpo;
	array<Double>^ pattern;
    array<Double>^ layerH2;
	array<Double>^ layerH1;
	array<Double>^ layerH0;
	array<Double>^ biasH0;
	array<Double>^ biasH1;
	array<Double, 2>^ weightsH0;
	array<Double, 2>^ weightsH1;
	array<Double>^ biasH0b;
	array<Double>^ biasH1b;
	array<Double, 2>^ weightsH0b;
	array<Double, 2>^ weightsH1b;
	static Random^ rand = gcnew Random();

public:
	NetworkCore(UInt32 %numInputs, UInt32 %numHidden, UInt32 %numOutputs)
	{
		this->numInputs = numInputs;
		this->numHidden = numHidden;
		this->numOutputs = numOutputs;

		layerH2 = gcnew array<Double>(numInputs);
		layerH1 = gcnew array<Double>(numHidden);
		layerH0 = gcnew array<Double>(numOutputs);
		error = gcnew array<Double>(numOutputs);
		pattern = gcnew array<Double>(numOutputs);
		weightsH0 = gcnew array<Double, 2>(numOutputs, numHidden);
		biasH0 = gcnew array<Double>(numOutputs);
		weightsH1 = gcnew array<Double, 2>(numHidden, numInputs);
		biasH1 = gcnew array<Double>(numHidden);
		weightsH0b = gcnew array<Double, 2>(numOutputs, numHidden);
		biasH0b = gcnew array<Double>(numOutputs);
		weightsH1b = gcnew array<Double, 2>(numHidden, numInputs);
		biasH1b = gcnew array<Double>(numHidden);
		initWeights();

	}
	//************************************
	private: void initWeights() {
		UInt32 seed = rand->Next(1, 12345);
		std::mt19937 generator(seed);
		Double mean = 0.0;
		Double stddev = 1.0;
		std::normal_distribution<Double> normal(mean, stddev);

		Double d = 0;
		for (UInt32 i = 0; i<numOutputs; i++){
			d = normal(generator);
			biasH0[i] = d;
			biasH0b[i] = d;
			for (UInt32 j = 0; j<numHidden; j++){
				d = normal(generator);
				weightsH0[i, j] = d;
				weightsH0b[i, j] = d;
			}
		}
		for (UInt32 i = 0; i<numHidden; i++){
			d = normal(generator);
			biasH1[i] = d;
			biasH1b[i] = d;
			for (UInt32 j = 0; j<numInputs; j++){
				d = normal(generator);
				weightsH1[i, j] = d;
				weightsH1b[i, j] = d;
			}
		}

	}	

   //************************************

	public: void setEpochs(UInt32 %Epochs){
		this->numEpochs = Epochs;
		mseEpo = gcnew array<Double>(Epochs);
    }

	public: void setRLH0(Double %lr){
		this->LR_HO = lr;
    }

	public: void setRLH1(Double %lr){
		this->LR_H1 = lr;
    }

	public: void setAlfa(Double %al){
		this->alfa = al;
    }
	public: void setFunH0(Char %f){
		this->Fun_H0 = f;
	}
	public: void setFunH1(Char %f){
		this->Fun_H1 = f;
	}

    //************************************
	private: Double Neuron(UInt32 %w, array<Double>^ %arrInputs, array<Double>^ %arrWeights, Double %ba, Char %fun){
        Double sum = 0;
        for (UInt32 i=0; i<w; i++) {
            Double u = arrInputs[i] * arrWeights[i];
            sum = sum + u;
        }
        sum = sum + ba;
		
        Double out = 0;
        if (fun == 'e') out = Math::Exp(sum)/(1+Math::Exp(sum));
        if (fun == 't') out = Math::Tanh(sum);
		//System::Diagnostics::Debug::WriteLine(out);
        return out;

    }

    //************************************
	private: void calcNet(){
		for (UInt32 i = 0; i<numHidden; i++) {
			Double ba1 = biasH1[i];
			array<Double>^ wi1 = gcnew array<Double>(numInputs);
			for (UInt32 wj = 0; wj<numInputs; wj++) {
				wi1[wj] = weightsH1[i, wj];
			}
			layerH1[i] = Neuron(numInputs, layerH2, wi1, ba1, Fun_H1);
			
		}

		for (UInt32 i = 0; i<this->numOutputs; i++) {
			Double ba0 = biasH0[i];
			array<Double>^ wi0 = gcnew array<Double>(numHidden);
			for (UInt32 wj = 0; wj<numHidden; wj++) {
				wi0[wj] = weightsH0[i, wj];
			}
			layerH0[i] = Neuron(numHidden, layerH1, wi0, ba0, Fun_H0);
			
		}

	}
	//************************************
	private: void calcOverallError(){
		error_H0 = 0;
		mse = 0;
		  for (UInt32 i=0; i<numOutputs; i++) {
			  error[i] = pattern[i] - layerH0[i];
			  error_H0 = error_H0 + error[i];
			  mse = mse + Math::Pow(error[i],2);
		  }
	}

	private: void WeightChanges() {
		calcNet();
		calcOverallError();
		for(UInt32 i = 0;i<numOutputs;i++){
			for(UInt32 j = 0;j<numHidden;j++){
				Double wib = weightsH0[i, j];
				Double wi = weightsH0[i, j] + (LR_HO * error[i] * layerH1[j]) + alfa *(weightsH0[i, j]-weightsH0b[i, j]);
				weightsH0[i, j] = wi;
				weightsH0b[i, j] = wib;

			}
			Double bib = biasH0[i];
			Double bi = biasH0[i] + (LR_HO * error[i]) + alfa * (biasH0[i] - biasH0b[i]);
			biasH0[i]=bi;
			biasH0b[i]=bib;
		}	

		for(UInt32 i = 0;i<numHidden;i++){
			calcNet();
			calcOverallError();
			for(UInt32 j = 0;j<numInputs;j++){
				Double wib = weightsH1[i, j];
				Double wi = weightsH1[i, j] + (LR_H1 * error_H0 * layerH2[j]) + alfa *(weightsH1[i, j]-weightsH1b[i, j]);
				weightsH1[i, j] = wi;
				weightsH1b[i, j] = wib;
			}
			Double bib = biasH1[i];
			Double bi = biasH1[i] + (LR_H1 * error_H0) + alfa * (biasH1[i] - biasH1b[i]);
			biasH1[i]=bi;
			biasH1b[i]=bib;
		}
	}


	//************************************
	private: void permData(){

		Dictionary<Double, UInt32>^ index = gcnew Dictionary<Double, UInt32>;

		UInt32 a = 0;
		Double d = 0;
		while (a<dataLength) {
			d = rand->NextDouble();
			bool good = true;
			try
			{
				index->Add(d, a);
			}
			catch (ArgumentException^)
			{
				good = false;
			}
			if (good) a++;
		}
		SortedDictionary<Double, UInt32>^ dict = gcnew SortedDictionary<Double, UInt32>(index);

		array<UInt32>^ finlOrder = gcnew array<UInt32>(dataLength);
		UInt32 i = 0;

		for each (KeyValuePair<Double, UInt32>^ pair in index)
		{
			finlOrder[i] = pair->Value;
			i++;
		}

		for (UInt32 h = 0; h < dataLength; h++) {
			array<Double>^ vecIn = getInput(finlOrder[h], true);
			array<Double>^ vecTa = getTarget(finlOrder[h]);
			setInputTemp(h, vecIn);
			setTargetTemp(h, vecTa);
		}

		for (UInt32 h = 0; h < dataLength; h++) {
			CopyToOrginal(h);
		}

	}


	//************************************
	public: void Training(){
		countEpochs = 0;
		while (countEpochs < numEpochs) {
			Double mseSum = 0;
		  for (UInt32 h=0; h<dataLength; h++) {
			  array<Double>^ row1 = getInput(h, true);
			  array<Double>^ row2 = getTarget(h);
			  setInput(row1);
			  setPattern(row2);
			  WeightChanges();
			  calcNet();
			  calcOverallError();
			  mseSum = mseSum + mse;

		  }
		  permData();
		  mseEpo[countEpochs] = mseSum / Double(dataLength);
		  countEpochs++;
		 
		}
	}
	//************************************
	public: void MSE(array<Double>^ %mseTab){
		for (UInt32 h = 0; h < dataLength; h++) {
			mseTab[h] = mseEpo[h];
		}
	}

	//************************************
	
	public: void Scoring(array<Double, 2>^ %ScoringRes){
		  for (UInt32 h=0; h<dataLengthScore; h++) {
			  array<Double>^ row = getInput(h, false);
			  setInput(row);
			  calcNet();
			  array<Double>^ out = getOutput();
			  for (UInt32 i=0; i<numOutputs; i++) {
				  ScoringRes[h, i] = out[i];
				 
			  }

		  }
	}
	
	//************************************

	private: array<Double>^ getInput(UInt32 %j, bool train){
		array<Double>^ vec = gcnew array<Double>(numInputs);
		  for (UInt32 i=0; i<numInputs; i++) {
			  if (train) vec[i] = trainInputs[j, i];
			  else vec[i] = scoreInputs[j, i];
		  }
		return vec;
	}
	
	private: array<Double>^ getTarget(UInt32 %j){
		array<Double>^ vec = gcnew array<Double>(numOutputs);
		  for (UInt32 i=0; i<numOutputs; i++) {
			  vec[i] = trainOutput[j, i];
		  }
		return vec;
	}
	
	private: array<Double>^ getOutput(){
		array<Double>^ vec = gcnew array<Double>(numOutputs);
		  for (UInt32 i=0; i<numOutputs; i++) {
			  vec[i] = layerH0[i];
		  }
		return vec;
	}

	private: void CopyToOrginal(UInt32 %i){
		for (UInt32 j = 0; j<numInputs; j++) {
				trainInputs[i, j] = tempInputs[i, j];
		}
		for (UInt32 j = 0; j<numOutputs; j++) {
				trainOutput[i, j] = tempOutput[i, j];
		}
	}
	
	private: void setInput(array<Double>^ %input){
		  for (UInt32 i=0; i<numInputs; i++) {
			  layerH2[i] = input[i];
		  }
	}
	
	private: void setPattern(array<Double>^ %pa){
		  for (UInt32 i=0; i<numOutputs; i++) {
			  pattern[i] = pa[i];
		  }
	}
	
	private: void setInputTemp(UInt32 %j, array<Double>^ %input){
		  for (UInt32 i=0; i<numInputs; i++) {
			  tempInputs[j, i] = input[i];
		  }
	}
	
	private: void setTargetTemp(UInt32 %j, array<Double>^ %ta){
		  for (UInt32 i=0; i<numOutputs; i++) {
			  tempOutput[j, i] = ta[i];
		  }
	}

	//************************************
	public: void setData(UInt32 %l, array<Double, 2>^ %DataInput, array<Double, 2>^ %DataOutput){
		
			dataLength = l;
			trainInputs = gcnew array<Double, 2>(dataLength, numInputs);
			tempInputs = gcnew array<Double, 2>(dataLength, numInputs);

			 for (UInt32 i=0; i<dataLength; i++) {
			  for (UInt32 j=0; j<numInputs; j++) {
				  trainInputs[i, j] = DataInput[i, j];
			  }
			 }
			 
			 trainOutput = gcnew array<Double, 2>(dataLength, numOutputs);
			 tempOutput = gcnew array<Double, 2>(dataLength, numOutputs);
			 
			 for (UInt32 i=0; i<dataLength; i++) {
				  for (UInt32 j=0; j<numOutputs; j++) {
					  trainOutput[i, j] = DataOutput[i, j];
				  }
		  }
	}

	//************************************

	public: void setScoreData(UInt32 %l, array<Double, 2>^ %DataScoreInput){
		dataLengthScore = l;
			
			scoreInputs = gcnew array<Double, 2>(dataLengthScore, numInputs);

			for (UInt32 i = 0; i<dataLengthScore; i++) {
				for (UInt32 j = 0; j<numInputs; j++) {
					scoreInputs[i, j] = DataScoreInput[i, j];
				}
			}
	}

	//************************************

};