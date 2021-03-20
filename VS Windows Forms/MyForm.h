#pragma once

namespace TestDrawing {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Drawing::Drawing2D;

	/// <summary>
	/// Summary for MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Panel^  panel1;
	private: System::Windows::Forms::FlowLayoutPanel^  flowLayoutPanel1;
	private: System::Windows::Forms::Button^  button1;


	protected:

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->flowLayoutPanel1 = (gcnew System::Windows::Forms::FlowLayoutPanel());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->flowLayoutPanel1->SuspendLayout();
			this->SuspendLayout();
			// 
			// panel1
			// 
			this->panel1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->panel1->BackColor = System::Drawing::Color::Cornsilk;
			this->panel1->Location = System::Drawing::Point(12, 12);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(406, 270);
			this->panel1->TabIndex = 0;
			this->panel1->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &MyForm::Paint);
			// 
			// flowLayoutPanel1
			// 
			this->flowLayoutPanel1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Right));
			this->flowLayoutPanel1->Controls->Add(this->button1);
			this->flowLayoutPanel1->Location = System::Drawing::Point(424, 12);
			this->flowLayoutPanel1->Name = L"flowLayoutPanel1";
			this->flowLayoutPanel1->Size = System::Drawing::Size(166, 270);
			this->flowLayoutPanel1->TabIndex = 1;
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(3, 3);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(163, 68);
			this->button1->TabIndex = 0;
			this->button1->Text = L"button1";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(602, 294);
			this->Controls->Add(this->flowLayoutPanel1);
			this->Controls->Add(this->panel1);
			this->DoubleBuffered = true;
			this->Name = L"MyForm";
			this->ShowIcon = false;
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"MyForm";
			this->flowLayoutPanel1->ResumeLayout(false);
			this->ResumeLayout(false);

		}
#pragma endregion


	private: System::Void Paint(System::Object^  sender, System::Windows::Forms::PaintEventArgs^  e) {
		Graphics^ g = e->Graphics;
		//make the image become High Quality
		g->SmoothingMode = Drawing2D::SmoothingMode::AntiAlias;
		g->FillEllipse(Brushes::White, 10, 10, 75, 50);
		g->DrawEllipse(Pens::Black, 10, 10, 75, 50);
		g->FillEllipse(Brushes::Yellow, 90, 10, 75, 75);
		g->DrawEllipse(Pens::Red, 90, 10, 75, 75);
		g->FillRectangle(Brushes::Pink, 170, 10, 75, 75);
		g->DrawRectangle(Pens::Blue, 170, 10, 75, 75);
	}
	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
		// Get a Graphics object
		Graphics^ pg = panel1->CreateGraphics();
		pg->Clear(Color::Cornsilk);
		// Draw a styled line
		Pen^ pen2 = gcnew Pen(Color::Blue, 3.0);
		pen2->DashStyle = DashStyle::DashDotDot;
		pg->DrawLine(pen2, 10, 120, 250, 60);

		// Draw a filled rectangle
		SolidBrush^ sb1 = gcnew SolidBrush(Color::Red);
		pg->FillRectangle(sb1, 60, 30, 40, 40);

		// Draw a filled and outlined rectangle
		Pen^ pen1 = gcnew Pen(Color::Red);
		SolidBrush^ sb2 = gcnew SolidBrush(Color::Yellow);
		pg->FillRectangle(sb2, 90, 40, 45, 45);
		pg->DrawRectangle(pen1, 90, 40, 45, 45);

		// Draw a filled ellipse
		SolidBrush^ sb3 = gcnew SolidBrush(Color::Green);
		pg->FillEllipse(sb3, 30, 100, 65, 50);
		delete pg;

	}
};
}
