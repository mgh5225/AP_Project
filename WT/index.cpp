#include "index.h"
WApplication* app;
Json::Object person;
Json::Object apartment;
firstPage::firstPage()
{
	btn_login = new WPushButton("log in");
	btn_register = new WPushButton("Register");
	my_H_layout = new WHBoxLayout;
	my_H_layout->addWidget(unique_ptr<WPushButton>(btn_login), 0, AlignmentFlag::Left);
	my_H_layout->addWidget(unique_ptr<WPushButton>(btn_register), 1, AlignmentFlag::Left);

	my_G_layout = new WGridLayout;
	my_V_layout = new WVBoxLayout;
	my_V_layout->addLayout(unique_ptr<WHBoxLayout>(my_H_layout));
	my_V_layout->addLayout(unique_ptr<WGridLayout>(my_G_layout));

	btn_login->setStyleClass("btn");
	btn_register->setStyleClass("btn");

	btn_login->clicked().connect(this, &firstPage::on_btn_login_click);
	btn_register->clicked().connect(this, &firstPage::on_btn_register_click);

	this->setLayout(unique_ptr<WVBoxLayout>(my_V_layout));
}
void firstPage::on_btn_login_click()
{
	app->root()->clear();
	app->instance()->useStyleSheet("main.css");
	Login* l = new Login;
	app->root()->addWidget(unique_ptr<WContainerWidget>(l));
}
void firstPage::on_btn_register_click()
{
	app->root()->clear();
	app->instance()->useStyleSheet("main.css");
	Register* r = new Register;
	app->root()->addWidget(unique_ptr<WContainerWidget>(r));
}

index::index(const WEnvironment& env) :WApplication(env) {

	instance()->useStyleSheet("index.css");
	enableUpdates();

	firstPage* f = new firstPage;
	root()->addWidget(unique_ptr<WContainerWidget>(f));

	app = this;
}

Login::Login(){
	main_layout = new WVBoxLayout;
	login_label = new WLabel("LOG IN");
	le_userName = new WLineEdit;
	le_password = new WLineEdit;
	le_password->setEchoMode(EchoMode::Password);
	lbl_type = new WLabel("Log in as a:");
	radio_manager = new WRadioButton("Manager");
	radio_user = new WRadioButton("User");
	auto btn_group = std::make_shared<Wt::WButtonGroup>();
	btn_group->addButton(radio_manager);
	btn_group->addButton(radio_user);
	radio_user->setChecked(true);
	my_H_layout = new WHBoxLayout;
	btn_log_in = new WPushButton("log In");
	btn_log_in->setEnabled(false);

	main_layout->addWidget(unique_ptr<WLabel>(login_label));
	main_layout->addWidget(unique_ptr<WLineEdit>(le_userName));
	main_layout->addWidget(unique_ptr<WLineEdit>(le_password));
	main_layout->addLayout(unique_ptr<WHBoxLayout>(my_H_layout));
	main_layout->addWidget(unique_ptr<WPushButton>(btn_log_in));

	my_H_layout->addWidget(unique_ptr<WLabel>(lbl_type));
	my_H_layout->addWidget(unique_ptr<WRadioButton>(radio_user));
	my_H_layout->addWidget(unique_ptr<WRadioButton>(radio_manager));


	login_label->setStyleClass("login100-form-title p-b-51");
	le_userName->setStyleClass("wrap-input100 input100");
	le_password->setStyleClass("wrap-input100 input100");
	btn_log_in->setStyleClass("login100-form-btn");
	le_userName->setPlaceholderText("Username");
	le_password->setPlaceholderText("Password");
	lbl_type->setStyleClass("type-widget");
	radio_user->setStyleClass("type-widget");
	radio_manager->setStyleClass("type-widget");

	btn_log_in->clicked().connect(this, &Login::on_btn_login_click);
	le_userName->changed().connect(this, &Login::le_usrename_changed);
	le_password->changed().connect(this, &Login::le_password_changed);

	this->setLayout(unique_ptr<WVBoxLayout>(main_layout));
}
void Login::on_btn_login_click(){
	Json::Object data;
	data["req"] = "login";
	data["username"] = le_userName->text();
	data["password"] = le_password->text();
	if (radio_user->isChecked()) data["mode"] = "user";
	else if (radio_manager->isChecked()) data["mode"] = "manager";
	request newRequest(data);
	Json::Object answer = newRequest.answer();
	if (answer["code"].toBool()) {
		app->root()->clear();
		app->instance()->removeStyleSheet("main.css");
		app->instance()->removeStyleSheet("index.css");
		app->instance()->useStyleSheet("userPanel.css");
		person = answer["person"];
		if (answer["mode"].toString() == "user") {
			UserPanel* userPanel = new UserPanel;
			app->root()->addWidget(unique_ptr<WContainerWidget>(userPanel));
		}
		else if (answer["mode"].toString() == "manager") {
			ManagerPanel* managerPanel = new ManagerPanel;
			app->root()->addWidget(unique_ptr<WContainerWidget>(managerPanel));
		}
	}
	else {
		WDialog *msg=new WDialog;
		WVBoxLayout* lay = new WVBoxLayout;
		WLabel* lbl = new WLabel("Username Or Password Is Wrong");
		WPushButton* btn = new WPushButton("OK");
		lay->addWidget(unique_ptr<WLabel>(lbl));
		lay->addWidget(unique_ptr<WPushButton>(btn));
		btn->setStyleClass("btn");
		btn->clicked().connect([=] {msg->accept(); });
		msg->setStyleClass("msg");
		msg->contents()->setLayout(unique_ptr<WVBoxLayout>(lay));
		msg->show();
	}
}
void Login::le_usrename_changed(){
	if (le_userName->text() != "" && le_password->text() != "") btn_log_in->setEnabled(true);
	else btn_log_in->setEnabled(false);
}
void Login::le_password_changed(){
	if (le_userName->text() != "" && le_password->text() != "") btn_log_in->setEnabled(true);
	else btn_log_in->setEnabled(false);
}

Register::Register() {
	main_layout = new WVBoxLayout;
	login_label = new WLabel("Register");
	le_userName = new WLineEdit;
	le_password = new WLineEdit;
	le_password->setEchoMode(EchoMode::Password);
	le_fullName = new WLineEdit;
	le_birthdate = new WDateEdit;
	lbl_type = new WLabel("Log in as a:");
	radio_manager = new WRadioButton("Manager");
	radio_user = new WRadioButton("User");
	auto btn_group = std::make_shared<Wt::WButtonGroup>();
	btn_group->addButton(radio_manager);
	btn_group->addButton(radio_user);
	radio_user->setChecked(true);
	my_H_layout = new WHBoxLayout;
	btn_register = new WPushButton("Register");
	btn_register->setEnabled(false);

	main_layout->addWidget(unique_ptr<WLabel>(login_label));
	main_layout->addWidget(unique_ptr<WLineEdit>(le_userName));
	main_layout->addWidget(unique_ptr<WLineEdit>(le_password));
	main_layout->addWidget(unique_ptr<WLineEdit>(le_fullName));
	main_layout->addWidget(unique_ptr<WDateEdit>(le_birthdate));
	main_layout->addLayout(unique_ptr<WHBoxLayout>(my_H_layout));
	main_layout->addWidget(unique_ptr<WPushButton>(btn_register));

	my_H_layout->addWidget(unique_ptr<WLabel>(lbl_type));
	my_H_layout->addWidget(unique_ptr<WRadioButton>(radio_user));
	my_H_layout->addWidget(unique_ptr<WRadioButton>(radio_manager));


	login_label->setStyleClass("login100-form-title p-b-51");
	le_userName->setStyleClass("wrap-input100 input100");
	le_password->setStyleClass("wrap-input100 input100");
	le_fullName->setStyleClass("wrap-input100 input100");
	le_birthdate->setStyleClass("wrap-input100 input100");
	btn_register->setStyleClass("login100-form-btn");
	le_userName->setPlaceholderText("Username");
	le_password->setPlaceholderText("Password");
	le_fullName->setPlaceholderText("Fullname");
	le_birthdate->setPlaceholderText("Birthdate");
	lbl_type->setStyleClass("type-widget");
	radio_user->setStyleClass("type-widget");
	radio_manager->setStyleClass("type-widget");

	btn_register->clicked().connect(this, &Register::on_btn_register_click);
	le_userName->changed().connect(this, &Register::le_usrename_changed);
	le_password->changed().connect(this, &Register::le_password_changed);

	this->setLayout(unique_ptr<WVBoxLayout>(main_layout));
}
void Register::on_btn_register_click(){
	Json::Object data;
	data["req"] = "register";
	data["username"] = le_userName->text();
	data["password"] = le_password->text();
	data["full_name"] = le_fullName->text();
	data["birth_date"] = le_birthdate->text();
	if (radio_user->isChecked()) data["mode"] = "user";
	else if (radio_manager->isChecked()) data["mode"] = "manager";
	request newRequest(data);
	Json::Object answer = newRequest.answer();
	if (answer["code"].toBool()) {
		WDialog* msg = new WDialog;
		WVBoxLayout* lay = new WVBoxLayout;
		WLabel* lbl = new WLabel("Registered!");
		WPushButton* btn = new WPushButton("OK");
		lay->addWidget(unique_ptr<WLabel>(lbl));
		lay->addWidget(unique_ptr<WPushButton>(btn));
		btn->setStyleClass("btn");
		btn->clicked().connect([=] {msg->accept(); });
		msg->setStyleClass("msg");
		msg->contents()->setLayout(unique_ptr<WVBoxLayout>(lay));
		msg->show();
		app->root()->clear();
		app->instance()->removeStyleSheet("main.css");
		app->instance()->removeStyleSheet("userPanel.css");
		app->instance()->useStyleSheet("index.css");
		firstPage* f = new firstPage;
		app->root()->addWidget(unique_ptr<WContainerWidget>(f));

	}
	else {
		WDialog* msg = new WDialog;
		WVBoxLayout* lay = new WVBoxLayout;
		WLabel* lbl = new WLabel("Username Is Exists");
		WPushButton* btn = new WPushButton("OK");
		lay->addWidget(unique_ptr<WLabel>(lbl));
		lay->addWidget(unique_ptr<WPushButton>(btn));
		btn->setStyleClass("btn");
		btn->clicked().connect([=] {msg->accept(); });
		msg->setStyleClass("msg");
		msg->contents()->setLayout(unique_ptr<WVBoxLayout>(lay));
		msg->show();
	}
}
void Register::le_usrename_changed(){
	if (le_userName->text() != "" && le_password->text() != "") btn_register->setEnabled(true);
	else btn_register->setEnabled(false);
}
void Register::le_password_changed(){
	if (le_userName->text() != "" && le_password->text() != "") btn_register->setEnabled(true);
	else btn_register->setEnabled(false);
}

UserPanel::UserPanel() {

	btn_logout = new WPushButton("Log Out");
	btn_showBalance = new WPushButton("Show Balance");
	btn_explore = new WPushButton("Explore");
	btn_logs = new WPushButton("Logs");

	show_aptartments = new WPushButton("Show Apartment");
	show_n_villas = new WPushButton("Show North Villas");
	show_s_villas = new WPushButton("Show South Villas");
	show_all_buildigs = new WPushButton("Show All Building");

	explore_lay = new WVBoxLayout;
	explore_lay->addWidget(unique_ptr<WPushButton>(show_aptartments));
	explore_lay->addWidget(unique_ptr<WPushButton>(show_n_villas));
	explore_lay->addWidget(unique_ptr<WPushButton>(show_s_villas));
	explore_lay->addWidget(unique_ptr<WPushButton>(show_all_buildigs));
	explore_lay->setSpacing(0);
	explore_lay->setContentsMargins(0, 0, 0, 0);

	explore_group = new WGroupBox;
	explore_group->setLayout(unique_ptr<WVBoxLayout>(explore_lay));

	my_H_layout = new WHBoxLayout;
	my_H_layout->addWidget(unique_ptr<WPushButton>(btn_explore), 0, AlignmentFlag::Left);
	my_H_layout->addWidget(unique_ptr<WPushButton>(btn_showBalance), 0, AlignmentFlag::Left);
	my_H_layout->addWidget(unique_ptr<WPushButton>(btn_logs), 0, AlignmentFlag::Left);
	my_H_layout->addWidget(unique_ptr<WGroupBox>(explore_group), 1, AlignmentFlag::Left);
	my_H_layout->addWidget(unique_ptr<WPushButton>(btn_logout), 0, AlignmentFlag::Right);
	my_H_layout->setSpacing(0);
	my_H_layout->setContentsMargins(0, 0, 0, 0);

	WGroupBox* H_group = new WGroupBox;
	H_group->setLayout(unique_ptr<WHBoxLayout>(my_H_layout));


	my_V_layout = new WVBoxLayout;
	my_V_layout->addWidget(unique_ptr<WGroupBox>(H_group));
	my_V_layout->setSpacing(0);
	my_V_layout->setContentsMargins(0, 0, 0, 0);

	btn_logout->setStyleClass("btn");
	btn_showBalance->setStyleClass("btn");
	btn_explore->setStyleClass("btn");
	btn_logs->setStyleClass("btn");
	H_group->setStyleClass("box");
	show_aptartments->setStyleClass("btn");
	show_n_villas->setStyleClass("btn");
	show_s_villas->setStyleClass("btn");
	show_all_buildigs->setStyleClass("btn");
	explore_group->setStyleClass("menu");

	btn_explore->clicked().connect(this, &UserPanel::on_btn_explore_click);
	btn_logout->clicked().connect(this, &UserPanel::on_btn_logout_click);
	btn_showBalance->clicked().connect(this, &UserPanel::on_btn_showBalance_click);
	btn_logs->clicked().connect(this, &UserPanel::on_btn_logs_click);
	show_aptartments->clicked().connect(this, &UserPanel::on_show_aptartments_click);
	show_n_villas->clicked().connect(this, &UserPanel::on_show_n_villas_click);
	show_s_villas->clicked().connect(this, &UserPanel::on_show_s_villas_click);
	show_all_buildigs->clicked().connect(this, &UserPanel::on_show_all_buildigs_click);

	this->setLayout(unique_ptr<WVBoxLayout>(my_V_layout));
}
void UserPanel::read(const Json::Object& json) {
	if (!blds.empty()) blds.clear();
	WVBoxLayout* lay = new WVBoxLayout;
	for (auto j : json) {
		blds.push_back(new Building(j.second));
		lay->addWidget(unique_ptr<Building>(blds.back()));
	}
	WDialog* dialog = new WDialog;
	dialog->setStyleClass("msg");
	dialog->contents()->setLayout(unique_ptr<WVBoxLayout>(lay));
	WPushButton* btn = new WPushButton("OK");
	btn->setStyleClass("btn");
	lay->addWidget(unique_ptr<WPushButton>(btn));
	btn->clicked().connect([=] {dialog->accept(); });
	dialog->show();
}
void UserPanel::on_btn_explore_click() {
	if (explore_group->hasStyleClass("show-menu")) {
		explore_group->removeStyleClass("show-menu");
	}
	else {
		explore_group->addStyleClass("show-menu");
	}
}
void UserPanel::on_btn_logout_click() {
	Json::Object data;
	data["req"] = "logout";
	data["ID"] = person["ID"].toString();
	request newRequest(data);
	Json::Object answer = newRequest.answer();
	if (answer["code"].toBool()) {
		app->root()->clear();
		app->instance()->removeStyleSheet("main.css");
		app->instance()->removeStyleSheet("userPanel.css");
		app->instance()->useStyleSheet("index.css");
		person.clear();
		firstPage* f = new firstPage;
		app->root()->addWidget(unique_ptr<WContainerWidget>(f));
	}
}
void UserPanel::on_btn_showBalance_click() {
	WDialog* msg = new WDialog;
	WVBoxLayout* lay = new WVBoxLayout;
	WLabel* lbl = new WLabel(person["balance"].toString());
	WPushButton* btn = new WPushButton("OK");
	lay->addWidget(unique_ptr<WLabel>(lbl));
	lay->addWidget(unique_ptr<WPushButton>(btn));
	btn->setStyleClass("btn");
	btn->clicked().connect([=] {msg->accept(); });
	msg->setStyleClass("msg");
	msg->contents()->setLayout(unique_ptr<WVBoxLayout>(lay));
	msg->show();
}
void UserPanel::on_btn_logs_click(){
	Json::Object data;
	data["req"] = "logs";
	data["ID"] = person["ID"].toString();
	request newRequest(data);
	Json::Object answer = newRequest.answer();
	if (answer["code"].toBool()) {
		Json::Object logs = answer["logs"];
		WVBoxLayout* lay = new WVBoxLayout;
		for (auto l : logs) {
			Json::Object l_json= l.second;
			Json::Object time = l_json["IO_time"];
			bool status = l_json["status"].toBool();
			int year = time["year"].toNumber();
			int month = time["month"].toNumber();
			int day = time["day"].toNumber();
			int hour = time["hour"].toNumber();
			int min = time["minute"].toNumber();
			int sec = time["second"].toNumber();
			string str_time = to_string(year + 1900) + "/" + to_string(month + 1) + "/" + to_string(day) + " " + to_string(hour) + ":" + to_string(min) + ":" + to_string(sec);
			string str_status = status ? "IN" : "OUT";
			string str_lbl = str_time + " " + str_status;
			WLabel* lbl=new WLabel(WString(str_lbl));
			lay->addWidget(unique_ptr<WLabel>(lbl),0,AlignmentFlag::Center);
		}
		WDialog* dialog = new WDialog;
		dialog->setStyleClass("msg");
		dialog->contents()->setLayout(unique_ptr<WVBoxLayout>(lay));
		WPushButton* btn = new WPushButton("OK");
		btn->setStyleClass("btn");
		lay->addWidget(unique_ptr<WPushButton>(btn));
		btn->clicked().connect([=] {dialog->accept(); });
		dialog->show();
	}
}
void UserPanel::on_show_aptartments_click() {
	Json::Object data;
	data["req"] = "show_buildings";
	data["mode"] = "apartment";
	request newRequest(data);
	Json::Object answer = newRequest.answer();
	if (answer["code"].toBool()) {
		read(answer["buildings"]);
	}

}
void UserPanel::on_show_n_villas_click() {
	Json::Object data;
	data["req"] = "show_buildings";
	data["mode"] = "north_villa";
	request newRequest(data);
	Json::Object answer = newRequest.answer();
	if (answer["code"].toBool()) {
		read(answer["buildings"]);
	}
}
void UserPanel::on_show_s_villas_click() {
	Json::Object data;
	data["req"] = "show_buildings";
	data["mode"] = "south_villa";
	request newRequest(data);
	Json::Object answer = newRequest.answer();
	if (answer["code"].toBool()) {
		read(answer["buildings"]);
	}
}
void UserPanel::on_show_all_buildigs_click() {
	Json::Object data;
	data["req"] = "show_buildings";
	data["mode"] = "all";
	request newRequest(data);
	Json::Object answer = newRequest.answer();
	if (answer["code"].toBool()) {
		read(answer["buildings"]);
	}
}

ManagerPanel::ManagerPanel() {

	btn_logout = new WPushButton("Log Out");
	btn_showBalance = new WPushButton("Show Balance");
	btn_explore = new WPushButton("Explore");
	btn_logs = new WPushButton("Logs");
	btn_addFile = new WPushButton("Add File");

	show_aptartments = new WPushButton("Show Apartment");
	show_n_villas = new WPushButton("Show North Villas");
	show_s_villas = new WPushButton("Show South Villas");
	show_all_buildigs = new WPushButton("Show All Building");

	add_new_apartment = new WPushButton("Add New Apartment");
	add_new_flat = new WPushButton("Add New Flat");
	add_new_n_villa = new WPushButton("Add New North Villa");
	add_new_s_villa = new WPushButton("Add New South Villa");

	explore_lay = new WVBoxLayout;
	explore_lay->addWidget(unique_ptr<WPushButton>(show_aptartments));
	explore_lay->addWidget(unique_ptr<WPushButton>(show_n_villas));
	explore_lay->addWidget(unique_ptr<WPushButton>(show_s_villas));
	explore_lay->addWidget(unique_ptr<WPushButton>(show_all_buildigs));
	explore_lay->setSpacing(0);
	explore_lay->setContentsMargins(0, 0, 0, 0);

	explore_group = new WGroupBox;
	explore_group->setLayout(unique_ptr<WVBoxLayout>(explore_lay));

	addFile_lay = new WVBoxLayout;
	addFile_lay->addWidget(unique_ptr<WPushButton>(add_new_apartment));
	addFile_lay->addWidget(unique_ptr<WPushButton>(add_new_flat));
	addFile_lay->addWidget(unique_ptr<WPushButton>(add_new_s_villa));
	addFile_lay->addWidget(unique_ptr<WPushButton>(add_new_n_villa));
	addFile_lay->setSpacing(0);
	addFile_lay->setContentsMargins(0, 0, 0, 0);

	addFile_group = new WGroupBox;
	addFile_group->setLayout(unique_ptr<WVBoxLayout>(addFile_lay));

	my_H_layout = new WHBoxLayout;
	my_H_layout->addWidget(unique_ptr<WPushButton>(btn_explore), 0, AlignmentFlag::Left);
	my_H_layout->addWidget(unique_ptr<WPushButton>(btn_addFile), 0, AlignmentFlag::Left);
	my_H_layout->addWidget(unique_ptr<WPushButton>(btn_logs), 0, AlignmentFlag::Left);
	my_H_layout->addWidget(unique_ptr<WPushButton>(btn_showBalance), 0, AlignmentFlag::Left);
	my_H_layout->addWidget(unique_ptr<WGroupBox>(explore_group), 0, AlignmentFlag::Left);
	my_H_layout->addWidget(unique_ptr<WGroupBox>(addFile_group), 1, AlignmentFlag::Left);
	my_H_layout->addWidget(unique_ptr<WPushButton>(btn_logout), 0, AlignmentFlag::Right);
	my_H_layout->setSpacing(0);
	my_H_layout->setContentsMargins(0, 0, 0, 0);

	WGroupBox* H_group = new WGroupBox;
	H_group->setLayout(unique_ptr<WHBoxLayout>(my_H_layout));

	my_V_layout = new WVBoxLayout;
	my_V_layout->addWidget(unique_ptr<WGroupBox>(H_group));
	my_V_layout->setSpacing(0);
	my_V_layout->setContentsMargins(0, 0, 0, 0);

	btn_logout->setStyleClass("btn");
	btn_showBalance->setStyleClass("btn");
	btn_explore->setStyleClass("btn");
	btn_logs->setStyleClass("btn");
	btn_addFile->setStyleClass("btn");
	H_group->setStyleClass("box");
	show_aptartments->setStyleClass("btn");
	show_n_villas->setStyleClass("btn");
	show_s_villas->setStyleClass("btn");
	show_all_buildigs->setStyleClass("btn");
	add_new_apartment->setStyleClass("btn");
	add_new_flat->setStyleClass("btn");
	add_new_n_villa->setStyleClass("btn");
	add_new_s_villa->setStyleClass("btn");
	explore_group->setStyleClass("menu");
	addFile_group->setStyleClass("menu");

	btn_explore->clicked().connect(this, &ManagerPanel::on_btn_explore_click);
	btn_logs->clicked().connect(this, &ManagerPanel::on_btn_logs_click);
	btn_addFile->clicked().connect(this, &ManagerPanel::on_btn_addFile_click);
	btn_logout->clicked().connect(this, &ManagerPanel::on_btn_logout_click);
	btn_showBalance->clicked().connect(this, &ManagerPanel::on_btn_showBalance_click);
	show_aptartments->clicked().connect(this, &ManagerPanel::on_show_aptartments_click);
	show_n_villas->clicked().connect(this, &ManagerPanel::on_show_n_villas_click);
	show_s_villas->clicked().connect(this, &ManagerPanel::on_show_s_villas_click);
	show_all_buildigs->clicked().connect(this, &ManagerPanel::on_show_all_buildigs_click);
	add_new_apartment->clicked().connect(this, &ManagerPanel::on_add_new_apartment_click);
	add_new_flat->clicked().connect(this, &ManagerPanel::on_add_new_flat_click);
	add_new_s_villa->clicked().connect(this, &ManagerPanel::on_add_new_s_villa_click);
	add_new_n_villa->clicked().connect(this, &ManagerPanel::on_add_new_n_villa_click);

	this->setLayout(unique_ptr<WVBoxLayout>(my_V_layout));
}
void ManagerPanel::read(const Json::Object& json) {
	if (!blds.empty()) blds.clear();
	WVBoxLayout* lay = new WVBoxLayout;
	for (auto j : json) {
		blds.push_back(new Building(j.second));
		lay->addWidget(unique_ptr<Building>(blds.back()));
	}
	WDialog* dialog = new WDialog;
	dialog->setStyleClass("msg");
	dialog->contents()->setLayout(unique_ptr<WVBoxLayout>(lay));
	WPushButton* btn = new WPushButton("OK");
	btn->setStyleClass("btn");
	lay->addWidget(unique_ptr<WPushButton>(btn));
	btn->clicked().connect([=] {dialog->accept(); });
	
	dialog->show();
}
void ManagerPanel::on_btn_explore_click() {
	if (addFile_group->hasStyleClass("show-menu")) {
		addFile_group->removeStyleClass("show-menu");
	}
	if (explore_group->hasStyleClass("show-menu")) {
		explore_group->removeStyleClass("show-menu");
	}
	else {
		explore_group->addStyleClass("show-menu");
	}
}
void ManagerPanel::on_btn_logout_click() {
	Json::Object data;
	data["req"] = "logout";
	data["ID"] = person["ID"].toString();
	request newRequest(data);
	Json::Object answer = newRequest.answer();
	if (answer["code"].toBool()) {
		app->root()->clear();
		app->instance()->removeStyleSheet("main.css");
		app->instance()->removeStyleSheet("userPanel.css");
		app->instance()->useStyleSheet("index.css");
		person.clear();
		firstPage* f = new firstPage;
		app->root()->addWidget(unique_ptr<WContainerWidget>(f));
	}
}
void ManagerPanel::on_btn_addFile_click(){
	if (explore_group->hasStyleClass("show-menu")) {
		explore_group->removeStyleClass("show-menu");
	}
	if (addFile_group->hasStyleClass("show-menu")) {
		addFile_group->removeStyleClass("show-menu");
	}
	else {
		addFile_group->addStyleClass("show-menu");
	}
}
void ManagerPanel::on_btn_showBalance_click() {
	WDialog* msg = new WDialog;
	WVBoxLayout* lay = new WVBoxLayout;
	WLabel* lbl = new WLabel(person["balance"].toString());
	WPushButton* btn = new WPushButton("OK");
	lay->addWidget(unique_ptr<WLabel>(lbl));
	lay->addWidget(unique_ptr<WPushButton>(btn));
	btn->setStyleClass("btn");
	btn->clicked().connect([=] {msg->accept(); });
	msg->setStyleClass("msg");
	msg->contents()->setLayout(unique_ptr<WVBoxLayout>(lay));
	msg->show();
}
void ManagerPanel::on_btn_logs_click() {
	Json::Object data;
	data["req"] = "logs";
	data["ID"] = person["ID"].toString();
	request newRequest(data);
	Json::Object answer = newRequest.answer();
	if (answer["code"].toBool()) {
		Json::Object logs = answer["logs"];
		WVBoxLayout* lay = new WVBoxLayout;
		for (auto l : logs) {
			Json::Object l_json = l.second;
			Json::Object time = l_json["IO_time"];
			bool status = l_json["status"].toBool();
			int year = time["year"].toNumber();
			int month = time["month"].toNumber();
			int day = time["day"].toNumber();
			int hour = time["hour"].toNumber();
			int min = time["minute"].toNumber();
			int sec = time["second"].toNumber();
			string str_time = to_string(year + 1900) + "/" + to_string(month + 1) + "/" + to_string(day) + " " + to_string(hour) + ":" + to_string(min) + ":" + to_string(sec);
			string str_status = status ? "IN" : "OUT";
			string str_lbl = str_time + " " + str_status;
			WLabel * lbl = new WLabel(WString(str_lbl));
			lay->addWidget(unique_ptr<WLabel>(lbl), 0, AlignmentFlag::Center);
		}
		WDialog * dialog = new WDialog;
		dialog->setStyleClass("msg");
		dialog->contents()->setLayout(unique_ptr<WVBoxLayout>(lay));
		WPushButton * btn = new WPushButton("OK");
		btn->setStyleClass("btn");
		lay->addWidget(unique_ptr<WPushButton>(btn));
		btn->clicked().connect([=] {dialog->accept(); });
		dialog->show();
	}
}
void ManagerPanel::on_show_aptartments_click() {
	Json::Object data;
	data["req"] = "show_buildings";
	data["mode"] = "apartment";
	request newRequest(data);
	Json::Object answer = newRequest.answer();
	if (answer["code"].toBool()) {
		read(answer["buildings"]);
	}

}
void ManagerPanel::on_show_n_villas_click() {
	Json::Object data;
	data["req"] = "show_buildings";
	data["mode"] = "north_villa";
	request newRequest(data);
	Json::Object answer = newRequest.answer();
	if (answer["code"].toBool()) {
		read(answer["buildings"]);
	}
}
void ManagerPanel::on_show_s_villas_click() {
	Json::Object data;
	data["req"] = "show_buildings";
	data["mode"] = "south_villa";
	request newRequest(data);
	Json::Object answer = newRequest.answer();
	if (answer["code"].toBool()) {
		read(answer["buildings"]);
	}
}
void ManagerPanel::on_show_all_buildigs_click() {
	Json::Object data;
	data["req"] = "show_buildings";
	data["mode"] = "all";
	request newRequest(data);
	Json::Object answer = newRequest.answer();
	if (answer["code"].toBool()) {
		read(answer["buildings"]);
	}
}
void ManagerPanel::on_add_new_apartment_click() {
	app->root()->clear();
	app->instance()->removeStyleSheet("userpanel.css");
	app->instance()->useStyleSheet("main.css");
	app->instance()->useStyleSheet("index.css");
	AddNewApartment* a =new AddNewApartment;
	app->root()->addWidget(unique_ptr<WContainerWidget>(a));
}
void ManagerPanel::on_add_new_flat_click() {

}
void ManagerPanel::on_add_new_s_villa_click() {
	app->root()->clear();
	app->instance()->removeStyleSheet("userpanel.css");
	app->instance()->useStyleSheet("main.css");
	app->instance()->useStyleSheet("index.css");
	AddNewSVilla* a = new AddNewSVilla ;
	app->root()->addWidget(unique_ptr<WContainerWidget>(a));
}
void ManagerPanel::on_add_new_n_villa_click() {
	app->root()->clear();
	app->instance()->removeStyleSheet("userpanel.css");
	app->instance()->useStyleSheet("main.css");
	app->instance()->useStyleSheet("index.css");
	AddNewNVilla* a = new AddNewNVilla;
	app->root()->addWidget(unique_ptr<WContainerWidget>(a));
}

Building::Building(Json::Object& json){
	pic = new WImage(WLink(json["picture"].toString()));
	string str_1 = json["total_area"].toString();
	str_1 = "Total Area: " + str_1;
	total_area = new WLabel(str_1.c_str());
	string str_2 = json["address"].toString();
	str_2 = "Address: " + str_2;
	address = new WLabel(str_2.c_str());
	string str_3 = json["final_price"].toString();
	str_3 = "Final Price: " + str_3;
	final_price = new WLabel(str_3.c_str());

	pic->setStyleClass("pic");
	total_area->setStyleClass("total-area");
	address->setStyleClass("address");
	final_price->setStyleClass("final-price");

	lay = new WVBoxLayout;
	lay->addWidget(unique_ptr<WImage>(pic));
	lay->addWidget(unique_ptr<WLabel>(address));
	lay->addWidget(unique_ptr<WLabel>(total_area));
	lay->addWidget(unique_ptr<WLabel>(final_price));

	this->setStyleClass("building");
	this->setLayout(unique_ptr<WVBoxLayout>(lay));
}

AddNewApartment::AddNewApartment(){

	le_apartmentArea = new WLineEdit;
	le_apartmentArea->setPlaceholderText("Apartment Area");
	le_basePrice = new WLineEdit;
	le_basePrice->setPlaceholderText("Base Price");
	le_numberOfFloors = new WLineEdit;
	le_numberOfFloors->setPlaceholderText("Number Of Floors");
	le_address = new WLineEdit;
	le_address->setPlaceholderText("Address");
	le_numberOfUnits = new WLineEdit;
	le_numberOfUnits->setPlaceholderText("Number Of Units");

	lbl_dragAndDropArea = new WLabel("Please Drag And Drop your Image\nOr\nClick here for explore!");

	radio_normal = new WRadioButton("Normal");
	radio_commercial = new WRadioButton("Commercial");
	radio_official = new WRadioButton("official");
	auto btn_group = std::make_shared<Wt::WButtonGroup>();
	btn_group->addButton(radio_normal);
	btn_group->addButton(radio_commercial);
	btn_group->addButton(radio_official);
	radio_normal->setChecked(true);

	radio_lay = new WHBoxLayout;
	radio_lay->addWidget(unique_ptr<WRadioButton>(radio_normal));
	radio_lay->addWidget(unique_ptr<WRadioButton>(radio_commercial));
	radio_lay->addWidget(unique_ptr<WRadioButton>(radio_official));

	btn_add = new WPushButton("Add");
	btn_cancel = new WPushButton("Cancel");

	my_H_layout = new WHBoxLayout;
	my_H_layout->addWidget(unique_ptr<WPushButton>(btn_add));
	my_H_layout->addWidget(unique_ptr<WPushButton>(btn_cancel));

	my_V_layout = new WVBoxLayout;
	my_V_layout->addWidget(unique_ptr<WLineEdit>(le_apartmentArea));
	my_V_layout->addWidget(unique_ptr<WLineEdit>(le_basePrice));
	my_V_layout->addWidget(unique_ptr<WLineEdit>(le_numberOfFloors));
	my_V_layout->addWidget(unique_ptr<WLineEdit>(le_address));
	my_V_layout->addWidget(unique_ptr<WLineEdit>(le_numberOfUnits));
	my_V_layout->addWidget(unique_ptr<WLabel>(lbl_dragAndDropArea));
	my_V_layout->addLayout(unique_ptr<WHBoxLayout>(radio_lay));
	my_V_layout->addLayout(unique_ptr<WHBoxLayout>(my_H_layout));

	le_apartmentArea->setStyleClass("wrap-input100 input100");
	le_basePrice->setStyleClass("wrap-input100 input100");
	le_numberOfFloors->setStyleClass("wrap-input100 input100");
	le_address->setStyleClass("wrap-input100 input100");
	le_numberOfUnits->setStyleClass("wrap-input100 input100");
	btn_add->setStyleClass("login100-form-btn");
	btn_cancel->setStyleClass("login100-form-btn");
	radio_normal->setStyleClass("type-widget");
	radio_commercial->setStyleClass("type-widget");
	radio_official->setStyleClass("type-widget");
	lbl_dragAndDropArea->setStyleClass("dragdrop-area");

	btn_add->clicked().connect(this, &AddNewApartment::on_btn_add_click);
	btn_cancel->clicked().connect(this, &AddNewApartment::on_btn_cancel_click);

	this->setLayout(unique_ptr<WVBoxLayout>(my_V_layout));
}
void AddNewApartment::on_btn_add_click(){
	Json::Object data;
	data["req"] = "add_building";
	data["mode"] = "apartment";
	data["apartment_area"] = le_apartmentArea->text();
	data["base_price"] = le_basePrice->text();
	data["floors"] = le_numberOfFloors->text();
	data["units"] = le_numberOfUnits->text();
	data["address"] = le_address->text();
	if (radio_normal->isChecked()) data["status"] = "normal";
	else if (radio_official->isChecked()) data["status"] = "official";
	else if (radio_commercial->isChecked()) data["status"] = "commercial";
	
	request newRequest(data);
	Json::Object answer = newRequest.answer();
	if (answer["code"].toBool()) {
		app->root()->clear();
		app->instance()->useStyleSheet("userPanel.css");
		app->instance()->removeStyleSheet("main.css");
		app->instance()->removeStyleSheet("index.css");
		ManagerPanel* managerPanel = new ManagerPanel;
		app->root()->addWidget(unique_ptr<WContainerWidget>(managerPanel));
	}
}
void AddNewApartment::on_btn_cancel_click(){
	app->root()->clear();
	app->instance()->useStyleSheet("userPanel.css");
	app->instance()->removeStyleSheet("main.css");
	app->instance()->removeStyleSheet("index.css");
	ManagerPanel* managerPanel = new ManagerPanel;
	app->root()->addWidget(unique_ptr<WContainerWidget>(managerPanel));
}

AddNewFlat::AddNewFlat(){

	le_whichUnit = new WComboBox;
	le_whichUnit->setPlaceholderText("Which Unit");
	le_haveElev = new WComboBox;
	le_haveElev->setPlaceholderText("Have Elevator");
	le_haveElev->addItem("Yes");
	le_haveElev->addItem("No");
	le_floorNum = new WComboBox;
	le_floorNum->setPlaceholderText("Floor Number");
	le_flatArea = new WLineEdit;
	le_flatArea->setPlaceholderText("Flat Area");
	le_numberOfRooms = new WLineEdit;
	le_numberOfRooms->setPlaceholderText("Number Of Rooms");

	lbl_dragAndDropArea = new WLabel("Please Drag And Drop your Image\nOr\nClick here for explore!");

	radio_rent = new WRadioButton("Rent");
	radio_sale = new WRadioButton("Sale");
	radio_both = new WRadioButton("Both");
	auto btn_group = std::make_shared<Wt::WButtonGroup>();
	btn_group->addButton(radio_rent);
	btn_group->addButton(radio_sale);
	btn_group->addButton(radio_both);
	radio_rent->setChecked(true);

	radio_lay = new WHBoxLayout;
	radio_lay->addWidget(unique_ptr<WRadioButton>(radio_rent));
	radio_lay->addWidget(unique_ptr<WRadioButton>(radio_sale));
	radio_lay->addWidget(unique_ptr<WRadioButton>(radio_both));

	btn_add = new WPushButton("Add");
	btn_cancel = new WPushButton("Cancel");

	my_H_layout = new WHBoxLayout;
	my_H_layout->addWidget(unique_ptr<WPushButton>(btn_add));
	my_H_layout->addWidget(unique_ptr<WPushButton>(btn_cancel));

	WLabel* lbl_1 = new WLabel("Which Unit");
	WLabel* lbl_2 = new WLabel("Have Elevator");
	WLabel* lbl_3 = new WLabel("Floor Number");

	my_V_layout = new WVBoxLayout;
	my_V_layout->addWidget(unique_ptr<WLabel>(lbl_1));
	my_V_layout->addWidget(unique_ptr<WComboBox>(le_whichUnit));
	my_V_layout->addWidget(unique_ptr<WLabel>(lbl_2));
	my_V_layout->addWidget(unique_ptr<WComboBox>(le_haveElev));
	my_V_layout->addWidget(unique_ptr<WLabel>(lbl_3));
	my_V_layout->addWidget(unique_ptr<WComboBox>(le_floorNum));
	my_V_layout->addWidget(unique_ptr<WLineEdit>(le_flatArea));
	my_V_layout->addWidget(unique_ptr<WLineEdit>(le_numberOfRooms));
	my_V_layout->addWidget(unique_ptr<WLabel>(lbl_dragAndDropArea));
	my_V_layout->addLayout(unique_ptr<WHBoxLayout>(radio_lay));
	my_V_layout->addLayout(unique_ptr<WHBoxLayout>(my_H_layout));

	le_whichUnit->setStyleClass("wrap-input100 input100");
	le_haveElev->setStyleClass("wrap-input100 input100");
	le_floorNum->setStyleClass("wrap-input100 input100");
	le_flatArea->setStyleClass("wrap-input100 input100");
	le_numberOfRooms->setStyleClass("wrap-input100 input100");
	btn_add->setStyleClass("login100-form-btn");
	btn_cancel->setStyleClass("login100-form-btn");
	radio_rent->setStyleClass("type-widget");
	radio_sale->setStyleClass("type-widget");
	radio_both->setStyleClass("type-widget");
	lbl_dragAndDropArea->setStyleClass("dragdrop-area");

	btn_add->clicked().connect(this, &AddNewFlat::on_btn_add_click);
	btn_cancel->clicked().connect(this, &AddNewFlat::on_btn_cancel_click);

	this->setLayout(unique_ptr<WVBoxLayout>(my_V_layout));
}
void AddNewFlat::on_btn_add_click() {
}
void AddNewFlat::on_btn_cancel_click() {
	app->root()->clear();
	app->instance()->useStyleSheet("userPanel.css");
	app->instance()->removeStyleSheet("main.css");
	app->instance()->removeStyleSheet("index.css");
	ManagerPanel* managerPanel = new ManagerPanel;
	app->root()->addWidget(unique_ptr<WContainerWidget>(managerPanel));
}

AddNewNVilla::AddNewNVilla() {

	le_buildArea = new WLineEdit;
	le_buildArea->setPlaceholderText("Build Area");
	le_frontYardArea = new WLineEdit;
	le_frontYardArea->setPlaceholderText("Front Yard Area");
	le_backYardArea = new WLineEdit;
	le_backYardArea->setPlaceholderText("Back Yard Area");
	le_fullArea = new WLineEdit;
	le_fullArea->setPlaceholderText("Full Area");
	le_numberOfRooms = new WLineEdit;
	le_numberOfRooms->setPlaceholderText("Number Of Rooms");
	le_basePrice = new WLineEdit;
	le_basePrice->setPlaceholderText("Base Price");
	le_address = new WLineEdit;
	le_address->setPlaceholderText("Address");

	lbl_dragAndDropArea = new WLabel("Please Drag And Drop your Image\nOr\nClick here for explore!");

	radio_rent = new WRadioButton("Rent");
	radio_sale = new WRadioButton("Sale");
	radio_both = new WRadioButton("Both");
	auto btn_group = std::make_shared<Wt::WButtonGroup>();
	btn_group->addButton(radio_rent);
	btn_group->addButton(radio_sale);
	btn_group->addButton(radio_both);
	radio_rent->setChecked(true);

	radio_lay = new WHBoxLayout;
	radio_lay->addWidget(unique_ptr<WRadioButton>(radio_rent));
	radio_lay->addWidget(unique_ptr<WRadioButton>(radio_sale));
	radio_lay->addWidget(unique_ptr<WRadioButton>(radio_both));

	btn_add = new WPushButton("Add");
	btn_cancel = new WPushButton("Cancel");

	my_H_layout = new WHBoxLayout;
	my_H_layout->addWidget(unique_ptr<WPushButton>(btn_add));
	my_H_layout->addWidget(unique_ptr<WPushButton>(btn_cancel));

	my_V_layout = new WVBoxLayout;
	my_V_layout->addWidget(unique_ptr<WLineEdit>(le_buildArea));
	my_V_layout->addWidget(unique_ptr<WLineEdit>(le_frontYardArea));
	my_V_layout->addWidget(unique_ptr<WLineEdit>(le_backYardArea));
	my_V_layout->addWidget(unique_ptr<WLineEdit>(le_fullArea));
	my_V_layout->addWidget(unique_ptr<WLineEdit>(le_numberOfRooms));
	my_V_layout->addWidget(unique_ptr<WLineEdit>(le_basePrice));
	my_V_layout->addWidget(unique_ptr<WLineEdit>(le_address));
	my_V_layout->addWidget(unique_ptr<WLabel>(lbl_dragAndDropArea));
	my_V_layout->addLayout(unique_ptr<WHBoxLayout>(radio_lay));
	my_V_layout->addLayout(unique_ptr<WHBoxLayout>(my_H_layout));

	le_buildArea->setStyleClass("wrap-input100 input100");
	le_frontYardArea->setStyleClass("wrap-input100 input100");
	le_backYardArea->setStyleClass("wrap-input100 input100");
	le_fullArea->setStyleClass("wrap-input100 input100");
	le_numberOfRooms->setStyleClass("wrap-input100 input100");
	le_basePrice->setStyleClass("wrap-input100 input100");
	le_address->setStyleClass("wrap-input100 input100");
	btn_add->setStyleClass("login100-form-btn");
	btn_cancel->setStyleClass("login100-form-btn");
	radio_rent->setStyleClass("type-widget");
	radio_sale->setStyleClass("type-widget");
	radio_both->setStyleClass("type-widget");
	lbl_dragAndDropArea->setStyleClass("dragdrop-area");

	btn_add->clicked().connect(this, &AddNewNVilla::on_btn_add_click);
	btn_cancel->clicked().connect(this, &AddNewNVilla::on_btn_cancel_click);

	this->setLayout(unique_ptr<WVBoxLayout>(my_V_layout));
}
void AddNewNVilla::on_btn_add_click() {
	Json::Object data;
	data["req"] = "add_building";
	data["mode"] = "nvilla";
	data["ID"] = person["ID"].toString();
	data["front_yard_area"] = le_frontYardArea->text();
	data["back_yard_area"] = le_backYardArea->text();
	data["full_area"] = le_fullArea->text();
	data["base_price"] = le_basePrice->text();
	data["build_arae"] = le_buildArea->text();
	data["rooms"] = le_numberOfRooms->text();
	data["address"] = le_address->text();
	if (radio_sale->isChecked()) data["status"] = "sale";
	else if (radio_rent->isChecked()) data["status"] = "rent";
	else if (radio_both->isChecked()) data["status"] = "both";
	request newRequest(data);
	Json::Object answer = newRequest.answer();
	if (answer["code"].toBool()) {
		app->root()->clear();
		app->instance()->useStyleSheet("userPanel.css");
		app->instance()->removeStyleSheet("main.css");
		app->instance()->removeStyleSheet("index.css");
		ManagerPanel* managerPanel = new ManagerPanel;
		app->root()->addWidget(unique_ptr<WContainerWidget>(managerPanel));
	}
}
void AddNewNVilla::on_btn_cancel_click() {
	app->root()->clear();
	app->instance()->useStyleSheet("userPanel.css");
	app->instance()->removeStyleSheet("main.css");
	app->instance()->removeStyleSheet("index.css");
	ManagerPanel* managerPanel = new ManagerPanel;
	app->root()->addWidget(unique_ptr<WContainerWidget>(managerPanel));
}

AddNewSVilla::AddNewSVilla() {

	le_buildArea = new WLineEdit;
	le_buildArea->setPlaceholderText("Build Area");
	le_YardArea = new WLineEdit;
	le_YardArea->setPlaceholderText("Yard Area");
	le_parkingArea = new WLineEdit;
	le_parkingArea->setPlaceholderText("Parking Area");
	le_fullArea = new WLineEdit;
	le_fullArea->setPlaceholderText("Full Area");
	le_numberOfRooms = new WLineEdit;
	le_numberOfRooms->setPlaceholderText("Number Of Rooms");
	le_basePrice = new WLineEdit;
	le_basePrice->setPlaceholderText("Base Price");
	le_address = new WLineEdit;
	le_address->setPlaceholderText("Address");

	lbl_dragAndDropArea = new WLabel("Please Drag And Drop your Image\nOr\nClick here for explore!");

	radio_rent = new WRadioButton("Rent");
	radio_sale = new WRadioButton("Sale");
	radio_both = new WRadioButton("Both");
	auto btn_group = std::make_shared<Wt::WButtonGroup>();
	btn_group->addButton(radio_rent);
	btn_group->addButton(radio_sale);
	btn_group->addButton(radio_both);
	radio_rent->setChecked(true);

	radio_lay = new WHBoxLayout;
	radio_lay->addWidget(unique_ptr<WRadioButton>(radio_rent));
	radio_lay->addWidget(unique_ptr<WRadioButton>(radio_sale));
	radio_lay->addWidget(unique_ptr<WRadioButton>(radio_both));

	btn_add = new WPushButton("Add");
	btn_cancel = new WPushButton("Cancel");

	my_H_layout = new WHBoxLayout;
	my_H_layout->addWidget(unique_ptr<WPushButton>(btn_add));
	my_H_layout->addWidget(unique_ptr<WPushButton>(btn_cancel));

	my_V_layout = new WVBoxLayout;
	my_V_layout->addWidget(unique_ptr<WLineEdit>(le_buildArea));
	my_V_layout->addWidget(unique_ptr<WLineEdit>(le_YardArea));
	my_V_layout->addWidget(unique_ptr<WLineEdit>(le_parkingArea));
	my_V_layout->addWidget(unique_ptr<WLineEdit>(le_fullArea));
	my_V_layout->addWidget(unique_ptr<WLineEdit>(le_numberOfRooms));
	my_V_layout->addWidget(unique_ptr<WLineEdit>(le_basePrice));
	my_V_layout->addWidget(unique_ptr<WLineEdit>(le_address));
	my_V_layout->addWidget(unique_ptr<WLabel>(lbl_dragAndDropArea));
	my_V_layout->addLayout(unique_ptr<WHBoxLayout>(radio_lay));
	my_V_layout->addLayout(unique_ptr<WHBoxLayout>(my_H_layout));

	le_buildArea->setStyleClass("wrap-input100 input100");
	le_YardArea->setStyleClass("wrap-input100 input100");
	le_parkingArea->setStyleClass("wrap-input100 input100");
	le_fullArea->setStyleClass("wrap-input100 input100");
	le_numberOfRooms->setStyleClass("wrap-input100 input100");
	le_basePrice->setStyleClass("wrap-input100 input100");
	le_address->setStyleClass("wrap-input100 input100");
	btn_add->setStyleClass("login100-form-btn");
	btn_cancel->setStyleClass("login100-form-btn");
	radio_rent->setStyleClass("type-widget");
	radio_sale->setStyleClass("type-widget");
	radio_both->setStyleClass("type-widget");
	lbl_dragAndDropArea->setStyleClass("dragdrop-area");

	btn_add->clicked().connect(this, &AddNewSVilla::on_btn_add_click);
	btn_cancel->clicked().connect(this, &AddNewSVilla::on_btn_cancel_click);

	this->setLayout(unique_ptr<WVBoxLayout>(my_V_layout));
}
void AddNewSVilla::on_btn_add_click() {
	Json::Object data;
	data["req"] = "add_building";
	data["mode"] = "svilla";
	data["ID"] = person["ID"].toString();
	data["yard_area"] = le_YardArea->text();
	data["parking_area"] = le_parkingArea->text();
	data["full_area"] = le_fullArea->text();
	data["base_price"] = le_basePrice->text();
	data["build_arae"] = le_buildArea->text();
	data["rooms"] = le_numberOfRooms->text();
	data["address"] = le_address->text();
	if (radio_sale->isChecked()) data["status"] = "sale";
	else if (radio_rent->isChecked()) data["status"] = "rent";
	else if (radio_both->isChecked()) data["status"] = "both";
	request newRequest(data);
	Json::Object answer = newRequest.answer();
	if (answer["code"].toBool()) {
		app->root()->clear();
		app->instance()->useStyleSheet("userPanel.css");
		app->instance()->removeStyleSheet("main.css");
		app->instance()->removeStyleSheet("index.css");
		ManagerPanel* managerPanel = new ManagerPanel;
		app->root()->addWidget(unique_ptr<WContainerWidget>(managerPanel));
	}
}
void AddNewSVilla::on_btn_cancel_click() {
	app->root()->clear();
	app->instance()->useStyleSheet("userPanel.css");
	app->instance()->removeStyleSheet("main.css");
	app->instance()->removeStyleSheet("index.css");
	ManagerPanel* managerPanel = new ManagerPanel;
	app->root()->addWidget(unique_ptr<WContainerWidget>(managerPanel));
}

ApartmentDetails::ApartmentDetails(Json::Object& json)
{
	pic = new WImage(WLink(json["picture"]));
	le_address=new WLineEdit(json["address"]);
	le_basePrice= new WLineEdit(json["base_price"]);
	le_apartmentArea= new WLineEdit(json["total_area"]);
	le_numberOfFloors= new WLineEdit(json["floors"]);
	le_fullPrice= new WLineEdit(json["full_price"]);
	le_numberOfUnits= new WLineEdit(json["units"]);

	le_layout = new WVBoxLayout;
	le_layout->addWidget(unique_ptr<WLineEdit>(le_address));
	le_layout->addWidget(unique_ptr<WLineEdit>(le_basePrice));
	le_layout->addWidget(unique_ptr<WLineEdit>(le_apartmentArea));
	le_layout->addWidget(unique_ptr<WLineEdit>(le_numberOfFloors));
	le_layout->addWidget(unique_ptr<WLineEdit>(le_numberOfUnits));
	le_layout->addWidget(unique_ptr<WLineEdit>(le_fullPrice));

	le_address->setEnabled(false);
	le_basePrice->setEnabled(false);
	le_apartmentArea->setEnabled(false);
	le_numberOfFloors->setEnabled(false);
	le_numberOfUnits->setEnabled(false);
	le_fullPrice->setEnabled(false);

	pic_layout = new WVBoxLayout;
	pic_layout->addWidget(unique_ptr<WImage>(pic));
	pic_layout->addWidget(unique_ptr<WPushButton>(btn_edit));
	pic_layout->addWidget(unique_ptr<WPushButton>(btn_save));

	btn_edit->hide();
	btn_save->hide();

	my_H_layout = new WHBoxLayout;
	my_H_layout->addLayout(unique_ptr<WVBoxLayout>(pic_layout));
	my_H_layout->addLayout(unique_ptr<WVBoxLayout>(le_layout));

	btn_edit->clicked().connect(this, &ApartmentDetails::on_btn_edit_click);
	btn_save->clicked().connect(this, &ApartmentDetails::on_btn_save_click);

	this->setLayout(unique_ptr<WHBoxLayout>(my_H_layout));
}
void ApartmentDetails::managerMode(){
	btn_edit->show();
}
void ApartmentDetails::on_btn_edit_click(){
	le_address->setEnabled(true);
	le_basePrice->setEnabled(true);
	le_apartmentArea->setEnabled(true);
	le_numberOfFloors->setEnabled(true);
	le_numberOfUnits->setEnabled(true);
	le_fullPrice->setEnabled(true);
	btn_edit->hide();
	btn_save->show();
}
void ApartmentDetails::on_btn_save_click(){
	le_address->setEnabled(false);
	le_basePrice->setEnabled(false);
	le_apartmentArea->setEnabled(false);
	le_numberOfFloors->setEnabled(false);
	le_numberOfUnits->setEnabled(false);
	le_fullPrice->setEnabled(false);
	btn_edit->show();
	btn_save->hide();
}


