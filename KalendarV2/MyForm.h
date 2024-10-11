#pragma once

namespace KalendarV2Namespace {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// ������ ��� MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: �������� ��� ������������
			//
		}

	protected:
		/// <summary>
		/// ���������� ��� ������������ �������.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ label_month;
	private: System::Windows::Forms::Label^ label_resualt;
	private: System::Windows::Forms::Label^ label_years;
	private: System::Windows::Forms::Button^ button_get_result;
	private: System::Windows::Forms::ComboBox^ input_month;
	private: System::Windows::Forms::TextBox^ TextBox_input_year;
	protected:




	protected:






	private:
		/// <summary>
		/// ������������ ���������� ������������.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// ��������� ����� ��� ��������� ������������ � �� ��������� 
		/// ���������� ����� ������ � ������� ��������� ����.
		/// </summary>
		void InitializeComponent(void)
		{
			this->label_month = (gcnew System::Windows::Forms::Label());
			this->label_resualt = (gcnew System::Windows::Forms::Label());
			this->label_years = (gcnew System::Windows::Forms::Label());
			this->button_get_result = (gcnew System::Windows::Forms::Button());
			this->input_month = (gcnew System::Windows::Forms::ComboBox());
			this->TextBox_input_year = (gcnew System::Windows::Forms::TextBox());
			this->SuspendLayout();
			// 
			// label_month
			// 
			this->label_month->AutoSize = true;
			this->label_month->Location = System::Drawing::Point(69, 46);
			this->label_month->Name = L"label_month";
			this->label_month->Size = System::Drawing::Size(92, 13);
			this->label_month->TabIndex = 0;
			this->label_month->Text = L"�������� �����";
			// 
			// label_resualt
			// 
			this->label_resualt->AutoSize = true;
			this->label_resualt->Location = System::Drawing::Point(309, 209);
			this->label_resualt->Name = L"label_resualt";
			this->label_resualt->Size = System::Drawing::Size(59, 13);
			this->label_resualt->TabIndex = 1;
			this->label_resualt->Text = L"���������";
			// 
			// label_years
			// 
			this->label_years->AutoSize = true;
			this->label_years->Location = System::Drawing::Point(513, 57);
			this->label_years->Name = L"label_years";
			this->label_years->Size = System::Drawing::Size(129, 13);
			this->label_years->TabIndex = 2;
			this->label_years->Text = L"������� ��� (1919-2069)";
			this->label_years->Click += gcnew System::EventHandler(this, &MyForm::label3_Click);
			// 
			// button_get_result
			// 
			this->button_get_result->Location = System::Drawing::Point(234, 140);
			this->button_get_result->Name = L"button_get_result";
			this->button_get_result->Size = System::Drawing::Size(186, 32);
			this->button_get_result->TabIndex = 3;
			this->button_get_result->Text = L"�������� ���������";
			this->button_get_result->UseVisualStyleBackColor = true;
			// 
			// input_month
			// 
			this->input_month->FormattingEnabled = true;
			this->input_month->Items->AddRange(gcnew cli::array< System::Object^  >(12) {
				L"1", L"2", L"3", L"4", L"5", L"6", L"7", L"8",
					L"9", L"10", L"11", L"12"
			});
			this->input_month->Location = System::Drawing::Point(72, 93);
			this->input_month->Name = L"input_month";
			this->input_month->Size = System::Drawing::Size(121, 21);
			this->input_month->TabIndex = 4;
			this->input_month->Text = L"1";
			// 
			// TextBox_input_year
			// 
			this->TextBox_input_year->Location = System::Drawing::Point(516, 93);
			this->TextBox_input_year->MaxLength = 4;
			this->TextBox_input_year->Name = L"TextBox_input_year";
			this->TextBox_input_year->Size = System::Drawing::Size(86, 20);
			this->TextBox_input_year->TabIndex = 6;
			this->TextBox_input_year->Text = L"1919";
			this->TextBox_input_year->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(820, 452);
			this->Controls->Add(this->TextBox_input_year);
			this->Controls->Add(this->input_month);
			this->Controls->Add(this->button_get_result);
			this->Controls->Add(this->label_years);
			this->Controls->Add(this->label_resualt);
			this->Controls->Add(this->label_month);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::SizableToolWindow;
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	
};
}
