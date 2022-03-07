# IUT_AdvancedProgrammingProject

As our final project in the Advanced Programming course, we implemented a graphical application for real estate managers to manage their rental and sales lists. Users could also buy or rent houses with this application. 

# Team Members

+ [Nami Naziri](https://github.com/NamiNaziri)

+ [Arian Hadi](https://github.com/arianpotter)

+ [Mohammad Ghazanfari](https://github.com/mgh5225)


# Project Objectives

## Accounts
#### This program has two types of users. the first type are the real estate manager and the second one are the normal users

Common properties among users
- first name and last name
- Date of birth
- User status (Active - Dismissed)
- user name
- password
- Inventory
- Login and logout time

 In addition to the above features, the real estate manager has the following data
 
- List of housing
- List of sales or rental files

Normal users also have a list of their own sales and leases.

## Housing

#### North villa housing:
- Construction area
- Front yard area
- Rear yard area
- total area
- Number of rooms
- Photo of housing
- Base price (price per square meter)
- Address

#### South villa housing:
- Construction area
- Yard area
- Parking area
- Photo of housing
- total area
- Number of rooms
- Base price (price per square meter)
- Address

#### Apartment housing:
- total area
- Base price (price per square meter)
- Does it have an elevator or not?
- Number of floors
- Apartment photos
- Address
- Units in the apartment
- Each unit on each floor has the following features:
  - Features of each unit:
    - Floor number
    - Photo of the house
    - Number of rooms
    - Construction area



## Rent and Sale


#### Rental file:
- The type of housing (villa or apartment)
- For the apartment, the ID of that apartment
- The amount of commission (determined by a default value)
- The amount of the mortgage
- The amount of rent
- Rental period

#### Sales record:
- Type of housing (villa or apartment)
- For the apartment, the ID of that apartment
- The amount of commission(determined by a default value)
- Payment information (cash or bank check)


# General system scenario

1. To begin, the user needs to register or log in.
2. Depending on the type of user (manager of the enterprise or ordinary user) a panel is displayed. the manager of the real estate has the ability to add housing, edit housing, manage sales and rent records (that include Renting and selling a home), view housing information and list of sales or rental applications and All other logical capabilities. Normal users have the ability to view the housing as well as access to a search engine where they can filter the houses according to their own preferences. After selecting a preferred house to purchase or rent, a request will be sent to the manager. The manager can accept or reject the request. Every user has a financial balance from which he or she can buy a house or rent one. As soon as the transaction is completed, the expense will be added to the property manager's account.
3. If a house is sold or rented, its status changes to sold or rented and it will not appear on the housing list.
