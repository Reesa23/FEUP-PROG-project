#include "Menus.h"


unsigned mainMenu(Agency agency){
	
	bool end = false;

	while (!end) {
		int n;
		cout << "\n\n\n:::::::::::::::::::::::\n";
		cout << "\n     NICE HOLIDAYS     \n";
		cout << "\n:::::::::::::::::::::::\n\n";
		cout << "Select the pretended option: \n \n" << "[1] - add client; \n[2] - change client; \n[3] - remove client; \n[4] - create travel pack; \n[5] - change travel pack; \n[6] - remove travel pack; \n[7] - specific client data; \n[8] - all clients data; \n[9] - travel packs data; \n[10] - purchase travel pack; \n[11] - save changes and exit;\n\n";
		cin >> n;
	
		/*switch (n) {
		case 1:
			Agency_struct.client_list.push_back(novocliente());
			break;
		/*case 2:
			agency.chanageclient();
			break;
		case 3:
			removercliente(Agency_struct);
			break;
		case 4:
			Agency_struct.travelpack_list.push_back(novotp());
			break;
		case 5:
			alterartp(Agency_struct);
			break;
		case 6:
			removertp(Agency_struct);
			break;
		case 7:
			dadoscliente(Agency_struct);
			break;
		case 8:
			dadostodosclientes(Agency_struct);
			break;
		case 9:
			//dadostp(Agency_struct);
			menutpdata(Agency_struct);
			break;
		case 10:
			comprarpacote(Agency_struct);
			break;

		case 11:

			//client update

			info2.close();
			ofstream info2(agency_info[4]);
			info2.clear();

			int sizevariable = Agency_struct.client_list.size() - 1;

			for (int i = 0; i < sizevariable; i++)
			{
				info2 << Agency_struct.client_list[i].client_name << endl << Agency_struct.client_list[i].client_nif << endl << Agency_struct.client_list[i].family_members << endl << Agency_struct.client_list[i].client_address.street << "/" << Agency_struct.client_list[i].client_address.door << "/" << Agency_struct.client_list[i].client_address.floor << "/" << Agency_struct.client_list[i].client_address.postal_code << "/" << Agency_struct.client_list[i].client_address.locality << endl;

				int sizevariable2 = Agency_struct.client_list[i].n_bought_travelpacks.size();

				for (int j = 0; j < sizevariable2; j++)
				{
					info2 << Agency_struct.client_list[i].n_bought_travelpacks[j] << " ";
				}

				info2 << endl << Agency_struct.client_list[i].total_packs_purchased << endl << "::::::::::" << endl;

			}

			//last one

			int i = Agency_struct.client_list.size() - 1;

			info2 << Agency_struct.client_list[i].client_name << endl << Agency_struct.client_list[i].client_nif << endl << Agency_struct.client_list[i].family_members << endl << Agency_struct.client_list[i].client_address.street << "/" << Agency_struct.client_list[i].client_address.door << "/" << Agency_struct.client_list[i].client_address.floor << "/" << Agency_struct.client_list[i].client_address.postal_code << "/" << Agency_struct.client_list[i].client_address.locality << endl;

			int sizevariable2 = Agency_struct.client_list[i].n_bought_travelpacks.size();

			for (int j = 0; j < sizevariable2; j++)
			{
				info2 << Agency_struct.client_list[i].n_bought_travelpacks[j] << " ";
			}

			info2 << endl << Agency_struct.client_list[i].total_packs_purchased << endl;


			//end = true;


			//travel pack update

			info3.close();
			ofstream info3(agency_info[5]);
			info3.clear();

			sizevariable2 = Agency_struct.travelpack_list.size() - 1;

			info3 << lastcreated << endl;

			for (int i = 0; i < sizevariable2; i++)
			{
				info3 << Agency_struct.travelpack_list[i].identifier << endl << Agency_struct.travelpack_list[i].places << endl << Agency_struct.travelpack_list[i].departure.day << "/" << Agency_struct.travelpack_list[i].departure.month << "/" << Agency_struct.travelpack_list[i].departure.year << endl << Agency_struct.travelpack_list[i].arrival.day << "/" << Agency_struct.travelpack_list[i].arrival.month << "/" << Agency_struct.travelpack_list[i].arrival.year << endl << Agency_struct.travelpack_list[i].price_per_person << endl << Agency_struct.travelpack_list[i].max_number_of_ppl << endl << Agency_struct.travelpack_list[i].n_sold << endl << "::::::::::" << endl;

			}

			//last one

			i = Agency_struct.client_list.size() - 1;

			info3 << Agency_struct.travelpack_list[i].identifier << endl << Agency_struct.travelpack_list[i].places << endl << Agency_struct.travelpack_list[i].departure.day << "/" << Agency_struct.travelpack_list[i].departure.month << "/" << Agency_struct.travelpack_list[i].departure.year << endl << Agency_struct.travelpack_list[i].arrival.day << "/" << Agency_struct.travelpack_list[i].arrival.month << "/" << Agency_struct.travelpack_list[i].arrival.year << endl << Agency_struct.travelpack_list[i].price_per_person << endl << Agency_struct.travelpack_list[i].max_number_of_ppl << endl << Agency_struct.travelpack_list[i].n_sold << endl;

			end = true;

			break;
		}
*/
	}
  
  return 0;
}
    
