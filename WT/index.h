#pragma once
#include <Wt/WApplication.h>
#include <Wt/WVBoxLayout.h>
#include <Wt/WHBoxLayout.h>
#include<Wt/WPushButton.h>
#include<Wt/WLabel.h>
#include<Wt/WLineEdit.h>
#include<Wt/WVBoxLayout.h>
#include<Wt/WContainerWidget.h>
#include<Wt/WRadioButton.h>
#include<Wt/WGridLayout.h>
#include<Wt/WPushButton.h>
#include<Wt/WGroupBox.h>
#include<Wt/Json/Object.h>
#include<Wt/WDateEdit.h>
#include<Wt/WButtonGroup.h>
#include<Wt/WComboBox.h>
#include<Wt/WImage.h>
#include<Wt/WLink.h>
#include<Wt/WDialog.h>
#include<vector>
#include<thread>
#include"request.h"
using namespace Wt;
using namespace std;

class Building :public WContainerWidget {
	WImage* pic;
	WLabel* total_area;
	WLabel* address;
	WLabel* final_price;
	WVBoxLayout* lay;
public:
	Building(Json::Object& json);
};
class ApartmentDetails:public WContainerWidget {

	WImage* pic;
	WLineEdit* le_address;
	WLineEdit* le_basePrice;
	WLineEdit* le_apartmentArea;
	WLineEdit* le_numberOfFloors;
	WLineEdit* le_fullPrice;
	WLineEdit* le_numberOfUnits;

	WHBoxLayout* my_H_layout;
	WVBoxLayout* le_layout;
	WVBoxLayout* pic_layout;

	WPushButton* btn_edit;
	WPushButton* btn_save;
	void on_btn_edit_click();
	void on_btn_save_click();
public:
	ApartmentDetails(Json::Object& aprtment);
	void managerMode();
};
class AddNewApartment:public WContainerWidget {
	WLineEdit* le_apartmentArea;
	WLineEdit* le_basePrice;
	WLineEdit* le_numberOfFloors;
	WLineEdit* le_address;
	WLineEdit* le_numberOfUnits;

	WLabel* lbl_dragAndDropArea;

	WHBoxLayout* radio_lay;
	WRadioButton* radio_commercial;
	WRadioButton* radio_official;
	WRadioButton* radio_normal;

	WPushButton* btn_add;
	WPushButton* btn_cancel;

	WVBoxLayout* my_V_layout;
	WHBoxLayout* my_H_layout;

	void on_btn_add_click();
	void on_btn_cancel_click();
public:
	AddNewApartment();
};
class AddNewFlat:public WContainerWidget {
	WComboBox* le_whichUnit;
	WComboBox* le_haveElev;
	WComboBox* le_floorNum;

	WLineEdit* le_flatArea;
	WLineEdit* le_numberOfRooms;

	WLabel* lbl_dragAndDropArea;

	WHBoxLayout* radio_lay;
	WRadioButton* radio_sale;
	WRadioButton* radio_rent;
	WRadioButton* radio_both;

	WPushButton* btn_add;
	WPushButton* btn_cancel;

	WVBoxLayout* my_V_layout;
	WHBoxLayout* my_H_layout;


	void on_btn_add_click();
	void on_btn_cancel_click();

public:
	AddNewFlat();
};
class AddNewNVilla:public WContainerWidget {
	WLineEdit* le_buildArea;
	WLineEdit* le_frontYardArea;
	WLineEdit* le_backYardArea;
	WLineEdit* le_fullArea;
	WLineEdit* le_numberOfRooms;
	WLineEdit* le_basePrice;
	WLineEdit* le_address;

	WLabel* lbl_dragAndDropArea;

	WHBoxLayout* radio_lay;
	WRadioButton* radio_sale;
	WRadioButton* radio_rent;
	WRadioButton* radio_both;

	WPushButton* btn_add;
	WPushButton* btn_cancel;

	WVBoxLayout* my_V_layout;
	WHBoxLayout* my_H_layout;

	void on_btn_add_click();
	void on_btn_cancel_click();
public:
	AddNewNVilla();
};
class AddNewSVilla :public WContainerWidget {
	WLineEdit* le_buildArea;
	WLineEdit* le_YardArea;
	WLineEdit* le_parkingArea;
	WLineEdit* le_fullArea;
	WLineEdit* le_numberOfRooms;
	WLineEdit* le_basePrice;
	WLineEdit* le_address;

	WLabel* lbl_dragAndDropArea;

	WHBoxLayout* radio_lay;
	WRadioButton* radio_sale;
	WRadioButton* radio_rent;
	WRadioButton* radio_both;

	WPushButton* btn_add;
	WPushButton* btn_cancel;

	WVBoxLayout* my_V_layout;
	WHBoxLayout* my_H_layout;


	void on_btn_add_click();
	void on_btn_cancel_click();
public:
	AddNewSVilla();
};
class Login:public WContainerWidget {
	WPushButton* btn_log_in;
	WLineEdit* le_userName;
	WLineEdit* le_password;
	WVBoxLayout* main_layout;
	WLabel* login_label;
	WLabel* lbl_type;
	WRadioButton* radio_user;
	WRadioButton* radio_manager;
	WHBoxLayout* my_H_layout;

	void on_btn_login_click();
	void le_usrename_changed();
	void le_password_changed();
public:
	Login();
};
class Register:public WContainerWidget {
	WPushButton* btn_register;
	WLineEdit* le_userName;
	WLineEdit* le_password;
	WLineEdit* le_fullName;
	WDateEdit* le_birthdate;
	WVBoxLayout* main_layout;
	WLabel* login_label;
	WLabel* lbl_type;
	WRadioButton* radio_user;
	WRadioButton* radio_manager;
	WHBoxLayout* my_H_layout;
	
	void on_btn_register_click();
	void le_usrename_changed();
	void le_password_changed();
public:
	Register();
};
class UserPanel :public WContainerWidget{
	WHBoxLayout* my_H_layout;
	WVBoxLayout* my_V_layout;

	WPushButton* btn_showBalance;
	WPushButton* btn_explore;
	WPushButton* btn_logs;
	WPushButton* btn_logout;

	WVBoxLayout* explore_lay;
	WGroupBox* explore_group;
	WPushButton* show_aptartments;
	WPushButton* show_n_villas;
	WPushButton* show_s_villas;
	WPushButton* show_all_buildigs;

	vector<Building*> blds;


	void on_btn_explore_click();
	void on_btn_showBalance_click();
	void on_btn_logs_click();
	void on_btn_logout_click();
	void on_show_aptartments_click();
	void on_show_n_villas_click();
	void on_show_s_villas_click();
	void on_show_all_buildigs_click();

public:
	UserPanel();
	void read(const Json::Object& json);
};
class ManagerPanel :public WContainerWidget {
	WHBoxLayout* my_H_layout;
	WVBoxLayout* my_V_layout;

	WPushButton* btn_showBalance;
	WPushButton* btn_explore;
	WPushButton* btn_logs;
	WPushButton* btn_logout;
	WPushButton* btn_addFile;

	WVBoxLayout* explore_lay;
	WGroupBox* explore_group;
	WPushButton* show_aptartments;
	WPushButton* show_n_villas;
	WPushButton* show_s_villas;
	WPushButton* show_all_buildigs;

	WVBoxLayout* addFile_lay;
	WGroupBox* addFile_group;
	WPushButton* add_new_apartment;
	WPushButton* add_new_flat;
	WPushButton* add_new_n_villa;
	WPushButton* add_new_s_villa;

	vector<Building*> blds;

	void on_btn_explore_click();
	void on_btn_showBalance_click();
	void on_btn_logs_click();
	void on_btn_logout_click();
	void on_btn_addFile_click();

	void on_show_aptartments_click();
	void on_show_n_villas_click();
	void on_show_s_villas_click();
	void on_show_all_buildigs_click();

	void on_add_new_apartment_click();
	void on_add_new_flat_click();
	void on_add_new_n_villa_click();
	void on_add_new_s_villa_click();

public:
	ManagerPanel();
	void read(const Json::Object& json);
};
class firstPage :public WContainerWidget {
	void on_btn_login_click();
	void on_btn_register_click();
	WPushButton* btn_login;
	WPushButton* btn_register;
	WHBoxLayout* my_H_layout;
	WVBoxLayout* my_V_layout;
	WGridLayout* my_G_layout;
public:
	firstPage();
};
class index:public WApplication
{
public:
	index(const WEnvironment& env);

};