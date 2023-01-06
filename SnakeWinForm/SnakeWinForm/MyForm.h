#pragma once
#include"MyForm1.h"
#include"MyForm2.h"
int t=0;
int NumOfForm = 0;
int NumOfForm2 = 0;
MySettings Copy;
namespace SnakeWinForm {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// —водка дл€ MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
		}

	protected:
		/// <summary>
		/// ќсвободить все используемые ресурсы.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::TableLayoutPanel^ tableLayoutPanel1;
	private: System::Windows::Forms::Button^ START;
	private: System::Windows::Forms::Button^ SETTINGS;
	private: System::Windows::Forms::Button^ OUT1;

	private: System::Windows::Forms::Timer^ timer1;
	private: System::ComponentModel::IContainer^ components;

	protected:

	private:
		/// <summary>
		/// ќб€зательна€ переменна€ конструктора.
		/// </summary>
		System::Windows::Media::MediaPlayer^ Effect=gcnew System::Windows::Media::MediaPlayer();

#pragma region Windows Form Designer generated code
		/// <summary>
		/// “ребуемый метод дл€ поддержки конструктора Ч не измен€йте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(MyForm::typeid));
			this->tableLayoutPanel1 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->START = (gcnew System::Windows::Forms::Button());
			this->SETTINGS = (gcnew System::Windows::Forms::Button());
			this->OUT1 = (gcnew System::Windows::Forms::Button());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->tableLayoutPanel1->SuspendLayout();
			this->SuspendLayout();
			// 
			// tableLayoutPanel1
			// 
			this->tableLayoutPanel1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->tableLayoutPanel1->ColumnCount = 1;
			this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				100)));
			this->tableLayoutPanel1->Controls->Add(this->START, 0, 0);
			this->tableLayoutPanel1->Controls->Add(this->SETTINGS, 0, 1);
			this->tableLayoutPanel1->Controls->Add(this->OUT1, 0, 2);
			this->tableLayoutPanel1->Location = System::Drawing::Point(12, 12);
			this->tableLayoutPanel1->Name = L"tableLayoutPanel1";
			this->tableLayoutPanel1->RowCount = 3;
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 33.33333F)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 33.33333F)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 33.33333F)));
			this->tableLayoutPanel1->Size = System::Drawing::Size(458, 533);
			this->tableLayoutPanel1->TabIndex = 0;
			this->tableLayoutPanel1->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &MyForm::tableLayoutPanel1_Paint);
			// 
			// START
			// 
			this->START->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->START->BackColor = System::Drawing::Color::DarkSlateBlue;
			this->START->Font = (gcnew System::Drawing::Font(L"Broadway", 19.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->START->ForeColor = System::Drawing::SystemColors::ControlText;
			this->START->Location = System::Drawing::Point(3, 3);
			this->START->Name = L"START";
			this->START->Size = System::Drawing::Size(452, 171);
			this->START->TabIndex = 0;
			this->START->Text = L"START";
			this->START->UseVisualStyleBackColor = false;
			this->START->Click += gcnew System::EventHandler(this, &MyForm::START_Click);
			// 
			// SETTINGS
			// 
			this->SETTINGS->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->SETTINGS->BackColor = System::Drawing::Color::MediumSlateBlue;
			this->SETTINGS->Font = (gcnew System::Drawing::Font(L"Broadway", 19.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->SETTINGS->Location = System::Drawing::Point(3, 180);
			this->SETTINGS->Name = L"SETTINGS";
			this->SETTINGS->Size = System::Drawing::Size(452, 171);
			this->SETTINGS->TabIndex = 1;
			this->SETTINGS->Text = L"SETTINGS";
			this->SETTINGS->UseVisualStyleBackColor = false;
			this->SETTINGS->Click += gcnew System::EventHandler(this, &MyForm::SETTINGS_Click);
			// 
			// OUT1
			// 
			this->OUT1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->OUT1->BackColor = System::Drawing::Color::MediumPurple;
			this->OUT1->Font = (gcnew System::Drawing::Font(L"Broadway", 19.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->OUT1->Location = System::Drawing::Point(3, 357);
			this->OUT1->Name = L"OUT1";
			this->OUT1->Size = System::Drawing::Size(452, 173);
			this->OUT1->TabIndex = 2;
			this->OUT1->Text = L"OUT";
			this->OUT1->UseVisualStyleBackColor = false;
			this->OUT1->Click += gcnew System::EventHandler(this, &MyForm::OUT_Click);
			// 
			// timer1
			// 
			this->timer1->Enabled = true;
			this->timer1->Tick += gcnew System::EventHandler(this, &MyForm::OnTick1);
			// 
			// MyForm
			// 
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::None;
			this->AutoSize = true;
			this->AutoSizeMode = System::Windows::Forms::AutoSizeMode::GrowAndShrink;
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
			this->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Center;
			this->ClientSize = System::Drawing::Size(484, 549);
			this->Controls->Add(this->tableLayoutPanel1);
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->MaximizeBox = false;
			this->MaximumSize = System::Drawing::Size(500, 600);
			this->MinimumSize = System::Drawing::Size(500, 473);
			this->Name = L"MyForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"SnakeSlayer";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			this->tableLayoutPanel1->ResumeLayout(false);
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void OnTick1(System::Object^ sender, System::EventArgs^ e) {
		t++;
		t %= 1000;
	}
	private: System::Void tableLayoutPanel1_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
	}
	private: System::Void MyForm_Load(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void START_Click(System::Object^ sender, System::EventArgs^ e) {
		if (NumOfForm == 0 && NumOfForm2 == 0) {
			SnakeWinForm::MyForm1^ GameForm = gcnew SnakeWinForm::MyForm1;
			GameForm->Show();
			NumOfForm++;
		}
	}
	private: System::Void SETTINGS_Click(System::Object^ sender, System::EventArgs^ e) {
		if (NumOfForm2 == 0 && NumOfForm == 0) {
			SnakeWinForm::MyForm2^ SettingsForm = gcnew SnakeWinForm::MyForm2;
			SettingsForm->Show();
			NumOfForm2++;
		}
	}
	private: System::Void OUT_Click(System::Object^ sender, System::EventArgs^ e) {
		this->Close();
	}
};
}