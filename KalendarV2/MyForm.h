#pragma once

namespace KalendarV2Namespace {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();

		}

	protected:

		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ label_month;
	private: System::Windows::Forms::Label^ label_result;

	private: System::Windows::Forms::Label^ label_years;
	private: System::Windows::Forms::Button^ button_get_result;
	private: System::Windows::Forms::ComboBox^ input_month;
	private: System::Windows::Forms::TextBox^ input_year;
	private: System::Windows::Forms::Label^ label_days_in_month;
	private: System::Windows::Forms::Label^ label_if_year_is_leap;
	private: System::Windows::Forms::Label^ label_first_month_day;
	private: System::Windows::Forms::Button^ button_clear_input_year;
	private: System::Windows::Forms::Label^ label_current_month;




	private: String^ result = "";

	private: bool isLeapYear(int year) {
		return (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0));
	};

	private: int daysInMonth(int month, int year) {
		return month == 2 ? (isLeapYear(year) ? 29 : 28) : 31 - (month - 1) % 7 % 2;
	};

	private:int calculateFirstDayOfMonth(int month, int year) {
		int totalDays = 0;
		for (int y = 1919; y < year; ++y)
			totalDays += isLeapYear(y) ? 366 : 365;
		for (int m = 1; m < month; ++m)
			totalDays += daysInMonth(m, year);
		return (totalDays + 2) % 7;
	}
	private: String^ to_string(int arg) {
		return System::Convert::ToString(arg);
	}

	private: String^ getTextFormatIsYearLeap(int arg) {
		return isLeapYear(arg) ? "да" : "нет";
	}

	private: String^ getTextFormatMonth(int m) {
		array<String^>^ months = { "яЌ¬ј–№", "‘≈¬–јЋ№", "ћј–“", "јѕ–≈Ћ№", "ћј…", "»ёЌ№", "»ёЋ№", "ј¬√”—“", "—≈Ќ“яЅ–№", "ќ “яЅ–№", "ЌќяЅ–№", "ƒ≈ јЅ–№" };
		return (months[m - 1])->ToLower();
	}

	private: String^ getTextFormatDay(int d) {
		array<String^>^ days = { "понедельник", "вторник", "среда", "четверг", "п€тница", "суббота", "воскресенье" };
		return days[d - 1];
	}

	private: String^ myStew(int num) {
		String^ nums = System::Convert::ToString(num);
		String^ res;
		return nums->Length == 1 ? "  " + nums + "  " : nums + "  ";
	}

	private: void printCalendar(int month, int year) {
		array<String^>^ months = { "яЌ¬ј–№", "‘≈¬–јЋ№", "ћј–“", "јѕ–≈Ћ№", "ћј…", "»ёЌ№", "»ёЋ№", "ј¬√”—“", "—≈Ќ“яЅ–№", "ќ “яЅ–№", "ЌќяЅ–№", "ƒ≈ јЅ–№" };
		result += months[month - 1] + " " + year + "\n\n";
		array<String^>^ days = { "ѕЌ", "¬“", "—–", "„“", "ѕ“", "—Ѕ", "¬—" };
		for (int day = 0; day < (days->Length); day++) {
			result += days[day] + " ";
		}
		result += "\n";
		//
		int firstDay = calculateFirstDayOfMonth(month, year);
		for (int i = 0; i < firstDay; ++i) result += "      ";
		for (int day = 1; day <= daysInMonth(month, year); ++day) {
			result += myStew(day);
			if ((firstDay + day) % 7 == 0) {
				result += "\n";
			};
		}
		result += "\n";
	}

	protected:


	protected:


	private:

		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code

		void InitializeComponent(void)
		{
			this->label_month = (gcnew System::Windows::Forms::Label());
			this->label_result = (gcnew System::Windows::Forms::Label());
			this->label_years = (gcnew System::Windows::Forms::Label());
			this->button_get_result = (gcnew System::Windows::Forms::Button());
			this->input_month = (gcnew System::Windows::Forms::ComboBox());
			this->input_year = (gcnew System::Windows::Forms::TextBox());
			this->label_days_in_month = (gcnew System::Windows::Forms::Label());
			this->label_if_year_is_leap = (gcnew System::Windows::Forms::Label());
			this->label_first_month_day = (gcnew System::Windows::Forms::Label());
			this->button_clear_input_year = (gcnew System::Windows::Forms::Button());
			this->label_current_month = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// label_month
			// 
			this->label_month->AutoSize = true;
			this->label_month->Location = System::Drawing::Point(54, 45);
			this->label_month->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label_month->Name = L"label_month";
			this->label_month->Size = System::Drawing::Size(135, 20);
			this->label_month->TabIndex = 0;
			this->label_month->Text = L"¬ыберите мес€ц";
			// 
			// label_result
			// 
			this->label_result->AutoSize = true;
			this->label_result->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8));
			this->label_result->Location = System::Drawing::Point(179, 377);
			this->label_result->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label_result->Name = L"label_result";
			this->label_result->Size = System::Drawing::Size(89, 20);
			this->label_result->TabIndex = 1;
			this->label_result->Text = L"–езультат";
			this->label_result->Visible = false;
			// 
			// label_years
			// 
			this->label_years->AutoSize = true;
			this->label_years->Location = System::Drawing::Point(314, 47);
			this->label_years->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label_years->Name = L"label_years";
			this->label_years->Size = System::Drawing::Size(198, 20);
			this->label_years->TabIndex = 2;
			this->label_years->Text = L"¬ведите год (1919-2069)";
			// 
			// button_get_result
			// 
			this->button_get_result->Location = System::Drawing::Point(139, 136);
			this->button_get_result->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->button_get_result->Name = L"button_get_result";
			this->button_get_result->Size = System::Drawing::Size(279, 49);
			this->button_get_result->TabIndex = 3;
			this->button_get_result->Text = L"ѕолучить календарь";
			this->button_get_result->UseVisualStyleBackColor = true;
			this->button_get_result->Click += gcnew System::EventHandler(this, &MyForm::button_get_result_Click);
			// 
			// input_month
			// 
			this->input_month->FormattingEnabled = true;
			this->input_month->Items->AddRange(gcnew cli::array< System::Object^  >(12) {
				L"1", L"2", L"3", L"4", L"5", L"6", L"7", L"8",
					L"9", L"10", L"11", L"12"
			});
			this->input_month->Location = System::Drawing::Point(58, 70);
			this->input_month->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->input_month->Name = L"input_month";
			this->input_month->Size = System::Drawing::Size(194, 28);
			this->input_month->TabIndex = 4;
			this->input_month->Text = L"1";
			this->input_month->SelectedIndexChanged += gcnew System::EventHandler(this, &MyForm::input_month_SelectedIndexChanged);
			// 
			// input_year
			// 
			this->input_year->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->input_year->Location = System::Drawing::Point(318, 72);
			this->input_year->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->input_year->MaxLength = 4;
			this->input_year->Name = L"input_year";
			this->input_year->Size = System::Drawing::Size(194, 26);
			this->input_year->TabIndex = 6;
			this->input_year->Text = L"1919";
			this->input_year->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			this->input_year->TextChanged += gcnew System::EventHandler(this, &MyForm::input_year_TextChanged);
			this->input_year->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &MyForm::input_year_KeyPress);
			// 
			// label_days_in_month
			// 
			this->label_days_in_month->AutoSize = true;
			this->label_days_in_month->Location = System::Drawing::Point(39, 270);
			this->label_days_in_month->Name = L"label_days_in_month";
			this->label_days_in_month->Size = System::Drawing::Size(132, 20);
			this->label_days_in_month->TabIndex = 7;
			this->label_days_in_month->Text = L"ƒней в мес€це:  ";
			this->label_days_in_month->Visible = false;
			// 
			// label_if_year_is_leap
			// 
			this->label_if_year_is_leap->AutoSize = true;
			this->label_if_year_is_leap->Location = System::Drawing::Point(296, 270);
			this->label_if_year_is_leap->Name = L"label_if_year_is_leap";
			this->label_if_year_is_leap->Size = System::Drawing::Size(139, 20);
			this->label_if_year_is_leap->TabIndex = 8;
			this->label_if_year_is_leap->Text = L"√од високосный: ";
			this->label_if_year_is_leap->Visible = false;
			// 
			// label_first_month_day
			// 
			this->label_first_month_day->AutoSize = true;
			this->label_first_month_day->Location = System::Drawing::Point(296, 219);
			this->label_first_month_day->Name = L"label_first_month_day";
			this->label_first_month_day->Size = System::Drawing::Size(177, 20);
			this->label_first_month_day->TabIndex = 9;
			this->label_first_month_day->Text = L"ѕервый день мес€ца: ";
			this->label_first_month_day->Visible = false;
			// 
			// button_clear_input_year
			// 
			this->button_clear_input_year->Location = System::Drawing::Point(519, 72);
			this->button_clear_input_year->Name = L"button_clear_input_year";
			this->button_clear_input_year->Size = System::Drawing::Size(25, 29);
			this->button_clear_input_year->TabIndex = 10;
			this->button_clear_input_year->Text = L"X";
			this->button_clear_input_year->UseVisualStyleBackColor = true;
			this->button_clear_input_year->Click += gcnew System::EventHandler(this, &MyForm::button_clear_input_year_Click);
			// 
			// label_current_month
			// 
			this->label_current_month->AutoSize = true;
			this->label_current_month->Location = System::Drawing::Point(39, 219);
			this->label_current_month->Name = L"label_current_month";
			this->label_current_month->Size = System::Drawing::Size(154, 20);
			this->label_current_month->TabIndex = 11;
			this->label_current_month->Text = L"¬ыбранный мес€ц: ";
			this->label_current_month->Visible = false;
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(9, 20);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(645, 695);
			this->Controls->Add(this->label_current_month);
			this->Controls->Add(this->button_clear_input_year);
			this->Controls->Add(this->label_first_month_day);
			this->Controls->Add(this->label_if_year_is_leap);
			this->Controls->Add(this->label_days_in_month);
			this->Controls->Add(this->input_year);
			this->Controls->Add(this->input_month);
			this->Controls->Add(this->button_get_result);
			this->Controls->Add(this->label_years);
			this->Controls->Add(this->label_result);
			this->Controls->Add(this->label_month);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::SizableToolWindow;
			this->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->Name = L"MyForm";
			this->Text = L" алендарь";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

	private: System::Void input_month_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void input_year_TextChanged(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void button_get_result_Click(System::Object^ sender, System::EventArgs^ e) {
		String^ pickedYear = input_year->Text;
		String^ pickedMonth = input_month->Text;

		int pickedYearConverted = System::Convert::ToInt32(pickedYear);
		int pickedMonthConverted = System::Convert::ToInt32(pickedMonth);

		if ((Int32::Parse(pickedYear) > 2069) || (Int32::Parse(pickedYear) < 1919)) {
			MessageBox::Show("¬веди год в указанном диапазоне!");
			this->label_result->Text = "ќшибка";
		}
		else {
			result = "";

			this->label_days_in_month->Text = "ƒней в мес€це: " + to_string(daysInMonth(pickedYearConverted, pickedMonthConverted));
			this->label_first_month_day->Text = "ѕервый день мес€ца: " + getTextFormatDay(calculateFirstDayOfMonth(pickedMonthConverted, pickedYearConverted) + 1);
			this->label_if_year_is_leap->Text = "√од високосный: " + getTextFormatIsYearLeap(pickedYearConverted);
			this->label_current_month->Text = "¬ыбранный мес€ц: " + getTextFormatMonth(pickedMonthConverted);

			this->label_days_in_month->Visible = true;
			this->label_first_month_day->Visible = true;
			this->label_if_year_is_leap->Visible = true;
			this->label_result->Visible = true;
			this->label_current_month->Visible = true;

			printCalendar(pickedMonthConverted, pickedYearConverted);

			this->label_result->Text = result;
		}

	}

	private: System::Void input_year_KeyPress(System::Object^ sender, System::Windows::Forms::KeyPressEventArgs^ e) {
		if ((e->KeyChar >= '0') && (e->KeyChar <= '9'))
			return;
		e->Handled = true;
	}
	private: System::Void button_clear_input_year_Click(System::Object^ sender, System::EventArgs^ e) {
		this->input_year->Text = "";
	}

	};
}
