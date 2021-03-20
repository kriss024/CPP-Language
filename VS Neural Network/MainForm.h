#include "NetworkCoreObject.h"

#pragma once

namespace NeuralNetwork {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Threading;


	/// <summary>
	/// Summary for MainForm
	/// </summary>
	public ref class MainForm : public System::Windows::Forms::Form
	{
	private: Color aktKolor;

	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::TextBox^  textBox3;
	private: System::Windows::Forms::StatusStrip^  statusStrip1;
	private: System::Windows::Forms::Button^  btnZastosuj;
	private: System::Windows::Forms::Button^  btnUczenie;

	private: const static UInt32 column_in = 2;
	private: const static UInt32 column_out = 3;
	private: UInt32 hidden = 30;
	private: ArrayList^ pLista;
	private: UInt32 iteracje, MaxH, MaxW, LenPic;
	private: Double lr_h0, lr_h1, alfa;
	private: Boolean zastosuj = false;
	private: Boolean uczenie = false;
	private: Char Fun_H0 = 'e';
	private: Char Fun_H1 = 't';
	private: array<Double>^ MSEEpo;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::HScrollBar^  hScrollBar1;
	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::Label^  label6;
	private: System::Windows::Forms::TextBox^  alfa_textBox;
	private: System::Windows::Forms::Label^  label5;
	private: System::Windows::Forms::TextBox^  lrh1_textBox;
	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::TextBox^  lrh0_textBox;
	private: System::Windows::Forms::ComboBox^  h0_combo;

	private: System::Windows::Forms::Label^  label7;
	private: System::Windows::Forms::Label^  label8;
	private: System::Windows::Forms::DataVisualization::Charting::Chart^  chart1;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::ComboBox^  h1_combo;


	private: ref class PunktGraficzny{
	public:
		Point pozycja;
		Color kolor;
		UInt32 r, g, b;

		PunktGraficzny(UInt32 x, UInt32 y, Color k){
			this->pozycja.X = x;
			this->pozycja.Y = y;
			this->kolor = k;
			this->r = 0; 
			this->g = 0; 
			this->b = 0;
			if (k == Color::LightCoral) this->r = 1;
			if (k == Color::DarkSeaGreen) this->g = 1;
			if (k == Color::DeepSkyBlue) this->b = 1;
		
		}

		};

	public:
		MainForm(void)
		{
			InitializeComponent();
			pLista = gcnew ArrayList();
			aktKolor = Color::DeepSkyBlue;
			//System::Diagnostics::Debug::WriteLine(L" -- Object State or Tracing");

			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MainForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Panel^  drawingPanel;
	private: System::Windows::Forms::GroupBox^  groupBox1;
	private: System::Windows::Forms::GroupBox^  groupBox2;
	private: System::Windows::Forms::Button^  btnCzysc;
	private: System::Windows::Forms::RadioButton^  radioZielony;
	private: System::Windows::Forms::RadioButton^  radioNiebieski;
	private: System::Windows::Forms::RadioButton^  radioCzerwony;
	private: System::ComponentModel::IContainer^  components;


	protected:

	protected:

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			System::Windows::Forms::DataVisualization::Charting::ChartArea^  chartArea2 = (gcnew System::Windows::Forms::DataVisualization::Charting::ChartArea());
			System::Windows::Forms::DataVisualization::Charting::Series^  series2 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
			this->drawingPanel = (gcnew System::Windows::Forms::Panel());
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->chart1 = (gcnew System::Windows::Forms::DataVisualization::Charting::Chart());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->h1_combo = (gcnew System::Windows::Forms::ComboBox());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->h0_combo = (gcnew System::Windows::Forms::ComboBox());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->alfa_textBox = (gcnew System::Windows::Forms::TextBox());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->lrh1_textBox = (gcnew System::Windows::Forms::TextBox());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->lrh0_textBox = (gcnew System::Windows::Forms::TextBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->hScrollBar1 = (gcnew System::Windows::Forms::HScrollBar());
			this->btnZastosuj = (gcnew System::Windows::Forms::Button());
			this->btnUczenie = (gcnew System::Windows::Forms::Button());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->textBox3 = (gcnew System::Windows::Forms::TextBox());
			this->groupBox2 = (gcnew System::Windows::Forms::GroupBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->radioZielony = (gcnew System::Windows::Forms::RadioButton());
			this->radioNiebieski = (gcnew System::Windows::Forms::RadioButton());
			this->radioCzerwony = (gcnew System::Windows::Forms::RadioButton());
			this->btnCzysc = (gcnew System::Windows::Forms::Button());
			this->statusStrip1 = (gcnew System::Windows::Forms::StatusStrip());
			this->groupBox1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chart1))->BeginInit();
			this->groupBox2->SuspendLayout();
			this->SuspendLayout();
			// 
			// drawingPanel
			// 
			this->drawingPanel->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->drawingPanel->BackColor = System::Drawing::SystemColors::Control;
			this->drawingPanel->Location = System::Drawing::Point(12, 12);
			this->drawingPanel->Name = L"drawingPanel";
			this->drawingPanel->Size = System::Drawing::Size(670, 676);
			this->drawingPanel->TabIndex = 0;
			this->drawingPanel->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &MainForm::panelPaint);
			this->drawingPanel->MouseClick += gcnew System::Windows::Forms::MouseEventHandler(this, &MainForm::MouseClick);
			// 
			// groupBox1
			// 
			this->groupBox1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Right));
			this->groupBox1->Controls->Add(this->label1);
			this->groupBox1->Controls->Add(this->chart1);
			this->groupBox1->Controls->Add(this->label8);
			this->groupBox1->Controls->Add(this->h1_combo);
			this->groupBox1->Controls->Add(this->label7);
			this->groupBox1->Controls->Add(this->h0_combo);
			this->groupBox1->Controls->Add(this->label6);
			this->groupBox1->Controls->Add(this->alfa_textBox);
			this->groupBox1->Controls->Add(this->label5);
			this->groupBox1->Controls->Add(this->lrh1_textBox);
			this->groupBox1->Controls->Add(this->label4);
			this->groupBox1->Controls->Add(this->lrh0_textBox);
			this->groupBox1->Controls->Add(this->label2);
			this->groupBox1->Controls->Add(this->hScrollBar1);
			this->groupBox1->Controls->Add(this->btnZastosuj);
			this->groupBox1->Controls->Add(this->btnUczenie);
			this->groupBox1->Controls->Add(this->label3);
			this->groupBox1->Controls->Add(this->textBox3);
			this->groupBox1->Location = System::Drawing::Point(688, 12);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(241, 501);
			this->groupBox1->TabIndex = 1;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"Ustawienia sieci";
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(6, 286);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(160, 17);
			this->label1->TabIndex = 21;
			this->label1->Text = L"B³¹d œredniokwadratowy";
			// 
			// chart1
			// 
			this->chart1->BackColor = System::Drawing::Color::Transparent;
			chartArea2->Name = L"ChartArea1";
			this->chart1->ChartAreas->Add(chartArea2);
			this->chart1->Location = System::Drawing::Point(6, 306);
			this->chart1->Name = L"chart1";
			this->chart1->Palette = System::Windows::Forms::DataVisualization::Charting::ChartColorPalette::Pastel;
			series2->BackGradientStyle = System::Windows::Forms::DataVisualization::Charting::GradientStyle::LeftRight;
			series2->ChartArea = L"ChartArea1";
			series2->ChartType = System::Windows::Forms::DataVisualization::Charting::SeriesChartType::Line;
			series2->Name = L"MSE";
			series2->Palette = System::Windows::Forms::DataVisualization::Charting::ChartColorPalette::Berry;
			this->chart1->Series->Add(series2);
			this->chart1->Size = System::Drawing::Size(220, 119);
			this->chart1->TabIndex = 20;
			this->chart1->Text = L"chart1";
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->Location = System::Drawing::Point(6, 168);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(102, 17);
			this->label8->TabIndex = 19;
			this->label8->Text = L"F. aktywacji H1";
			// 
			// h1_combo
			// 
			this->h1_combo->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->h1_combo->FormattingEnabled = true;
			this->h1_combo->Items->AddRange(gcnew cli::array< System::Object^  >(2) { L"Exp", L"Tanh" });
			this->h1_combo->Location = System::Drawing::Point(133, 165);
			this->h1_combo->Name = L"h1_combo";
			this->h1_combo->Size = System::Drawing::Size(93, 24);
			this->h1_combo->TabIndex = 18;
			this->h1_combo->SelectedIndex = 1;
			this->h1_combo->SelectedIndexChanged += gcnew System::EventHandler(this, &MainForm::SelectedIndexChanged);
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Location = System::Drawing::Point(6, 138);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(102, 17);
			this->label7->TabIndex = 17;
			this->label7->Text = L"F. aktywacji H0";
			// 
			// h0_combo
			// 
			this->h0_combo->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->h0_combo->Enabled = false;
			this->h0_combo->FormattingEnabled = true;
			this->h0_combo->Items->AddRange(gcnew cli::array< System::Object^  >(2) { L"Exp", L"Tanh" });
			this->h0_combo->Location = System::Drawing::Point(133, 135);
			this->h0_combo->Name = L"h0_combo";
			this->h0_combo->Size = System::Drawing::Size(93, 24);
			this->h0_combo->SelectedIndex = 0;
			this->h0_combo->TabIndex = 16;
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(6, 254);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(32, 17);
			this->label6->TabIndex = 15;
			this->label6->Text = L"Alfa";
			// 
			// alfa_textBox
			// 
			this->alfa_textBox->Location = System::Drawing::Point(133, 251);
			this->alfa_textBox->Name = L"alfa_textBox";
			this->alfa_textBox->Size = System::Drawing::Size(93, 22);
			this->alfa_textBox->TabIndex = 14;
			this->alfa_textBox->Text = L"0,06";
			this->alfa_textBox->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(6, 226);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(115, 17);
			this->label5->TabIndex = 13;
			this->label5->Text = L"Learning rate H1";
			// 
			// lrh1_textBox
			// 
			this->lrh1_textBox->Location = System::Drawing::Point(133, 223);
			this->lrh1_textBox->Name = L"lrh1_textBox";
			this->lrh1_textBox->Size = System::Drawing::Size(93, 22);
			this->lrh1_textBox->TabIndex = 12;
			this->lrh1_textBox->Text = L"0,01";
			this->lrh1_textBox->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(6, 198);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(115, 17);
			this->label4->TabIndex = 11;
			this->label4->Text = L"Learning rate H0";
			// 
			// lrh0_textBox
			// 
			this->lrh0_textBox->Location = System::Drawing::Point(133, 195);
			this->lrh0_textBox->Name = L"lrh0_textBox";
			this->lrh0_textBox->Size = System::Drawing::Size(93, 22);
			this->lrh0_textBox->TabIndex = 10;
			this->lrh0_textBox->Text = L"0,05";
			this->lrh0_textBox->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(6, 56);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(172, 17);
			this->label2->TabIndex = 9;
			this->label2->Text = L"Liczba neuronów ukrytych";
			// 
			// hScrollBar1
			// 
			this->hScrollBar1->Location = System::Drawing::Point(9, 82);
			this->hScrollBar1->Maximum = 120;
			this->hScrollBar1->Minimum = 1;
			this->hScrollBar1->Name = L"hScrollBar1";
			this->hScrollBar1->Size = System::Drawing::Size(217, 28);
			this->hScrollBar1->TabIndex = 8;
			this->hScrollBar1->Value = 30;
			this->hScrollBar1->Scroll += gcnew System::Windows::Forms::ScrollEventHandler(this, &MainForm::Scroll);
			// 
			// btnZastosuj
			// 
			this->btnZastosuj->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Right));
			this->btnZastosuj->Location = System::Drawing::Point(123, 456);
			this->btnZastosuj->Name = L"btnZastosuj";
			this->btnZastosuj->Size = System::Drawing::Size(106, 39);
			this->btnZastosuj->TabIndex = 7;
			this->btnZastosuj->Text = L"Zastosuj";
			this->btnZastosuj->UseVisualStyleBackColor = true;
			this->btnZastosuj->Click += gcnew System::EventHandler(this, &MainForm::btnZastosuj_Click);
			// 
			// btnUczenie
			// 
			this->btnUczenie->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Right));
			this->btnUczenie->Location = System::Drawing::Point(9, 456);
			this->btnUczenie->Name = L"btnUczenie";
			this->btnUczenie->Size = System::Drawing::Size(106, 39);
			this->btnUczenie->TabIndex = 6;
			this->btnUczenie->Text = L"Uczenie";
			this->btnUczenie->UseVisualStyleBackColor = true;
			this->btnUczenie->Click += gcnew System::EventHandler(this, &MainForm::btnUczenie_Click);
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(6, 24);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(94, 17);
			this->label3->TabIndex = 5;
			this->label3->Text = L"Liczba iteracji";
			// 
			// textBox3
			// 
			this->textBox3->Location = System::Drawing::Point(133, 21);
			this->textBox3->Name = L"textBox3";
			this->textBox3->Size = System::Drawing::Size(93, 22);
			this->textBox3->TabIndex = 4;
			this->textBox3->Text = L"36";
			this->textBox3->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			// 
			// groupBox2
			// 
			this->groupBox2->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Right));
			this->groupBox2->Controls->Add(this->button1);
			this->groupBox2->Controls->Add(this->radioZielony);
			this->groupBox2->Controls->Add(this->radioNiebieski);
			this->groupBox2->Controls->Add(this->radioCzerwony);
			this->groupBox2->Controls->Add(this->btnCzysc);
			this->groupBox2->Location = System::Drawing::Point(688, 519);
			this->groupBox2->Name = L"groupBox2";
			this->groupBox2->Size = System::Drawing::Size(241, 160);
			this->groupBox2->TabIndex = 2;
			this->groupBox2->TabStop = false;
			this->groupBox2->Text = L"Ustawienia graficzne";
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(120, 30);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(106, 39);
			this->button1->TabIndex = 1;
			this->button1->Text = L"Poka¿ punkty";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MainForm::button1_Click);
			// 
			// radioZielony
			// 
			this->radioZielony->AutoSize = true;
			this->radioZielony->Location = System::Drawing::Point(6, 130);
			this->radioZielony->Name = L"radioZielony";
			this->radioZielony->Size = System::Drawing::Size(75, 21);
			this->radioZielony->TabIndex = 3;
			this->radioZielony->Text = L"Zielony";
			this->radioZielony->UseVisualStyleBackColor = true;
			this->radioZielony->CheckedChanged += gcnew System::EventHandler(this, &MainForm::chkZielony);
			// 
			// radioNiebieski
			// 
			this->radioNiebieski->AutoSize = true;
			this->radioNiebieski->Checked = true;
			this->radioNiebieski->Location = System::Drawing::Point(6, 103);
			this->radioNiebieski->Name = L"radioNiebieski";
			this->radioNiebieski->Size = System::Drawing::Size(86, 21);
			this->radioNiebieski->TabIndex = 2;
			this->radioNiebieski->TabStop = true;
			this->radioNiebieski->Text = L"Niebieski";
			this->radioNiebieski->UseVisualStyleBackColor = true;
			this->radioNiebieski->CheckedChanged += gcnew System::EventHandler(this, &MainForm::chkNiebieski);
			// 
			// radioCzerwony
			// 
			this->radioCzerwony->AutoSize = true;
			this->radioCzerwony->Location = System::Drawing::Point(7, 76);
			this->radioCzerwony->Name = L"radioCzerwony";
			this->radioCzerwony->Size = System::Drawing::Size(90, 21);
			this->radioCzerwony->TabIndex = 1;
			this->radioCzerwony->Text = L"Czerwony";
			this->radioCzerwony->UseVisualStyleBackColor = true;
			this->radioCzerwony->CheckedChanged += gcnew System::EventHandler(this, &MainForm::chkCzerwony);
			// 
			// btnCzysc
			// 
			this->btnCzysc->Location = System::Drawing::Point(6, 30);
			this->btnCzysc->Name = L"btnCzysc";
			this->btnCzysc->Size = System::Drawing::Size(106, 39);
			this->btnCzysc->TabIndex = 0;
			this->btnCzysc->Text = L"Czyœæ";
			this->btnCzysc->UseVisualStyleBackColor = true;
			this->btnCzysc->Click += gcnew System::EventHandler(this, &MainForm::btnCzysc_Click);
			// 
			// statusStrip1
			// 
			this->statusStrip1->ImageScalingSize = System::Drawing::Size(20, 20);
			this->statusStrip1->Location = System::Drawing::Point(0, 691);
			this->statusStrip1->Name = L"statusStrip1";
			this->statusStrip1->Size = System::Drawing::Size(938, 22);
			this->statusStrip1->TabIndex = 3;
			this->statusStrip1->Text = L"statusStrip1";
			// 
			// MainForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(938, 713);
			this->Controls->Add(this->statusStrip1);
			this->Controls->Add(this->groupBox2);
			this->Controls->Add(this->groupBox1);
			this->Controls->Add(this->drawingPanel);
			this->Name = L"MainForm";
			this->Text = L"Sieæ neuronowa";
			this->groupBox1->ResumeLayout(false);
			this->groupBox1->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chart1))->EndInit();
			this->groupBox2->ResumeLayout(false);
			this->groupBox2->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

private: ref class NetworkThread
{
private:
	UInt32 in, hid, out, iter, len, h, w;
	Double lr_h0, lr_h1, alfa;
	Char Fun_H0, Fun_H1;
	ArrayList^ lista;

public:
	NetworkCore^ network;
	array<Double, 2>^ inputTr;
	array<UInt32, 2>^ Loc;
	array<Double, 2>^ outputTr;
	array<Double, 2>^ inputSc;
	array<Double, 2>^ outputSc;

	NetworkThread(UInt32 in, UInt32 %hid, UInt32 out, UInt32 %iter, Double %lr_h0, Double %lr_h1, Double %alfa, Char %Fun_H0, Char %Fun_H1, ArrayList^ %ls){
		this->in = in;
		this->hid = hid;
		this->out = out;
		this->iter = iter;
		this->lista = ls;
		this->lr_h0 = lr_h0;
		this->lr_h1 = lr_h1;
		this->alfa = alfa;
		this->Fun_H0 = Fun_H0;
		this->Fun_H1 = Fun_H1;
		this->len = ls->Count;

	}

	void Training(){
			network = gcnew NetworkCore(in, hid, out);
			network->setEpochs(iter);
			network->setRLH0(lr_h0);
			network->setRLH0(lr_h1);
			network->setAlfa(alfa);
			network->setFunH0(Fun_H0);
			network->setFunH1(Fun_H1);
			inputTr = gcnew array<Double, 2>(len, in);
			outputTr = gcnew array<Double, 2>(len, out);
			UInt32 i = 0;
			for each(PunktGraficzny^ p in lista)
			{
				inputTr[i, 0] = Math::Log10(p->pozycja.X + 10) - 1.0;
				inputTr[i, 1] = Math::Log10(p->pozycja.Y + 10) - 1.0;
				outputTr[i, 0] = Double(p->r);
				outputTr[i, 1] = Double(p->g);
				outputTr[i, 2] = Double(p->b);
				i++;
			}
			network->setData(i, inputTr, outputTr);
			network->Training();
	}

	void SetHW(UInt32 h, UInt32 w) {
		this->h = h;
		this->w = w;
	}

	void Scoring(){

		UInt32 len = h * w;
		inputSc = gcnew array<Double, 2>(len, column_in);
		Loc = gcnew array<UInt32, 2>(len, column_in);
		outputSc = gcnew array<Double, 2>(len, column_out);
		UInt32 i = 0;
		for (UInt32 y = 0; y < h; y++){
			for (UInt32 x = 0; x < w; x++){
				Loc[i, 0] = x;
				Loc[i, 1] = y;
				inputSc[i, 0] = Math::Log10(x + 10) - 1.0;
				inputSc[i, 1] = Math::Log10(y + 10) - 1.0;
				i++;
			}

		}
		network->setScoreData(i, inputSc);
		network->Scoring(outputSc);

	}

	void MSE(array<Double>^ %mse){
		network->MSE(mse);

	}
};

private: NetworkThread^ networkTH;


private: System::Void MouseClick(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
		UInt32 x, y;
		x = e->X;
		y = e->Y;

		PunktGraficzny^ punkt = gcnew PunktGraficzny(x, y, aktKolor);

		pLista->Add(punkt);
		drawingPanel->Refresh();

	}

private: System::Void panelPaint(System::Object^  sender, System::Windows::Forms::PaintEventArgs^  pe) {

		Rectangle rect = drawingPanel->ClientRectangle;

		Bitmap^ bmp;
		if (zastosuj) { 
			bmp = gcnew Bitmap(MaxW, MaxH); 
		}
		else
		{
			bmp = gcnew Bitmap(rect.Width, rect.Height);
		}

		Graphics^ g = Graphics::FromImage(bmp);
		g->SmoothingMode = Drawing2D::SmoothingMode::HighQuality;

		if (zastosuj) {
			for (UInt32 i = 0; i < LenPic; i++){
				UInt32 x = networkTH->Loc[i, 0];
				UInt32 y = networkTH->Loc[i, 1];
				Byte r = Byte(networkTH->outputSc[i, 0] * Double(255));
				Byte g = Byte(networkTH->outputSc[i, 1] * Double(255));
				Byte b = Byte(networkTH->outputSc[i, 2] * Double(255));
				Color defColor = Color::FromArgb(r, g, b);
				bmp->SetPixel(x, y, defColor);
			}
		}

		for each(PunktGraficzny^ pPoint in pLista)
		{
			Pen^ pen = gcnew Pen(pPoint->kolor, 1.0);
			UInt32 X = pPoint->pozycja.X;
			UInt32 Y = pPoint->pozycja.Y;
			g->DrawEllipse(pen, X - 4, Y - 4, 8, 8); 
		}
		pe->Graphics->DrawImageUnscaled(bmp, 0, 0);

	}

private: System::Void btnCzysc_Click(System::Object^  sender, System::EventArgs^  e) {
	pLista->Clear();
	zastosuj = false;
	uczenie = false;
	drawingPanel->Refresh();
}
private: System::Void chkCzerwony(System::Object^  sender, System::EventArgs^  e) {
	this->aktKolor = Color::LightCoral;
}
private: System::Void chkNiebieski(System::Object^  sender, System::EventArgs^  e) {
	this->aktKolor = Color::DeepSkyBlue;
}
private: System::Void chkZielony(System::Object^  sender, System::EventArgs^  e) {
	this->aktKolor = Color::DarkSeaGreen;
}

private: System::Void btnUczenie_Click(System::Object^  sender, System::EventArgs^  e) {
		iteracje = Convert::ToInt32(textBox3->Text);
		lr_h0 = Convert::ToDouble(lrh0_textBox->Text);
		lr_h1 = Convert::ToDouble(lrh1_textBox->Text);
		alfa = Convert::ToDouble(alfa_textBox->Text);
		MSEEpo = gcnew array<Double>(iteracje);
		networkTH = gcnew NetworkThread(column_in, hidden, column_out, iteracje, lr_h0, lr_h1, alfa, Fun_H0, Fun_H1, pLista);
		ThreadStart^ mThread = gcnew  ThreadStart(networkTH, &NetworkThread::Training);
		Thread^ newThread = gcnew Thread(mThread);
		newThread->Start();
		newThread->Join();
		networkTH->MSE(MSEEpo);
		this->chart1->Series["MSE"]->Points->Clear();
		for (UInt32 h = 0; h < iteracje; h++) {
			this->chart1->Series["MSE"]->Points->Add(MSEEpo[h]);
		}
		uczenie = true;

}
private: System::Void btnZastosuj_Click(System::Object^  sender, System::EventArgs^  e) {
	if (uczenie) {
		Rectangle rect = drawingPanel->ClientRectangle;
		MaxH = rect.Height;
		MaxW = rect.Width;
		LenPic = MaxH * MaxW;
		networkTH->SetHW(MaxH, MaxW);
		ThreadStart^ mThread = gcnew  ThreadStart(networkTH, &NetworkThread::Scoring);
		Thread^ newThread = gcnew Thread(mThread);
		newThread->Start();
		newThread->Join();
		zastosuj = true;
		drawingPanel->Refresh();
	}

  }
private: System::Void Scroll(System::Object^  sender, System::Windows::Forms::ScrollEventArgs^  e) {
	hidden = hScrollBar1->Value;
	label2->Text = L"Liczba neuronów ukrytych "+Convert::ToString(this->hidden);
}
private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
	zastosuj = false;
	drawingPanel->Refresh();
}

private: System::Void SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
	Object^ selectedItem = h1_combo->SelectedItem;
	String ^ item = selectedItem->ToString();
	if (item == "Exp") Fun_H1 = 'e';
	if (item == "Tanh") Fun_H1 = 't';
}
};
}
