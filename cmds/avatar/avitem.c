//A new - menu driven - avatar item maker command - that will, hopefully,
//be much easier to update - will also add the ability to save your
//current object when it's not yet finished - by adding whatever
//you set into a mapping or a couple of them and then
//saving those - and will also look much much better
//Coded by Saide@Shadowgate - May, 2008
#include <std.h>
#include "items.h"
#include <move.h>
#include <langs.h>
#include <money.h>
#include <valid_bonuses.h>
#include "types.h"
#include "valid_armors.h"
#include <security.h>

inherit OBJECT;

#include "valid_weapons.h"

nosave string DIR, cur_menu;
nosave string PAD = "%^BOLD%^%^GREEN%^>>%^RESET%^ ";
nosave string cur_type;
nosave int menu_place = 0;
void finish();
void display_menu();
void update_this_menu();

//Description = Short, Obvious Short, Long
//Read = Text, Language
//Lore = Text, Difficulty
//Value = Currency Type, Amount
//
void do_response(string msg, string msg_type);

mapping ObjectInfo = (["File Name" : "NIL", "Object Type" : "NIL", "Item Name" : "NIL",
"IDS" : "NIL", "Description" : ({"NIL", "NIL", "NIL"}), "Read" : ({"NIL", "common"}),
"Lore" : ({"NIL", "NIL"}), "Value" : ({"gold", 10}), "Weight" : "NIL", "Size" : "NIL",
"Armor Class" : 0, "Enchantment" : "NIL", "Prof" : "NIL", "Damage" : ({"NIL", "NIL", "NIL"}),
"Weapon Type" : "NIL", "Armor Type" : "NIL", "Limbs" : "NIL", "Encumbrance" : "NIL"]);

mixed Bonuses = ([]);

mixed Specials = ([]);

mixed HeartBeat = ([]);

mixed WieldOrWear = (["wield" : ({"NIL", "NIL"}), "wear" : ({"NIL", "NIL"}),]);

mixed UnwieldOrRemove = (["unwield" : ({"NIL", "NIL"}), "remove" : ({"NIL", "NIL"}),]);

nosave string ThisMenu = ({});

string repeat_string(string rep, int amt);

nosave string HeartBeatMenu = ({});

nosave string SpecialsMenu = ({});

nosave string BonusMenu = VALID_BONUSES + ({"str", "int", "wis", "cha", "dex", "con"});

nosave string WieldUnwieldMenu = ({"Wield Message", "Room Wield Message",
						"Unwield Message", "Room Unwield Message"});

nosave string WearRemoveMenu = ({"Wear Message", "Room Wear Message",
					   "Remove Message", "Room Remove Message"});

nosave string menu_header = repeat_string("%^BOLD%^%^CYAN%^--%^RESET%^", 33);

nosave string *OTMenu = ({"Armor", "Object", "Weapon", "PocketArmor"});

nosave string *CurrencyMenu = HARD_CURRENCIES + ({"Enter Amount"});

nosave string *WeaponTypeMenu = keys(VALID_WP_TYPES);

nosave string *ArmorTypeMenu = keys(VALID_AR_TYPES);

nosave string *ArmorProfsMenu = ({"Light", "Medium", "Heavy"});

nosave string *WeaponProfsMenu = ({"Common", "Exotic", "Martial"});

nosave string SizeMenu = ({"Small", "Medium", "Large", "Giant"});

nosave string LoreMenu = ({"Enter Lore", "Lore Difficulty"});

nosave string *ReadMenu = ALL_LANGS + ({"Enter Writing"});

nosave string *DescriptionMenu = ({"Long", "Short", "Obvious Short"});

nosave string AllSubMenus = ({"Back"});

nosave string DamageMenu = ({"Normal Damage", "Large Damage"}) + WEAPON_TYPES;

nosave string AllMenus = ({"Clear All", "Finish", "Exit"});

nosave string *MainMenu = ({"File Name", "Object Type", "Item Name",
"Item Identities", "Description",
"Writing on Object", "Lore", "Weight", "Value", "Heart Beat", "Bonuses"});

nosave string *MainMenuWANA = ({"Enchantment", "Armor Class", "Size", "Specials", "Prof"});

nosave string *MainMenuWeapon = ({"Weapon Type", "Damage", "Wield/Unwield"});

nosave string *MainMenuArmor = ({"Armor Type", "Wear/Remove", "Limbs"});

nosave string *MainMenuPArmor = ({"Encumbrance"});

nosave string MyRestoredFileName;

int save_me(string file)
{
	return 1;
}

string strip_colors(string sh)
{
    	string output = "", *list = ({});
    	string *words = ({});
      int i;
	if(!sh)
	{
		return output;
	}
	words = explode(sh, "%^");

	list +=({"RED", "YELLOW", "BLUE",
	"GREEN", "MAGENTA", "ORANGE", "CYAN", "BLACK", "WHITE"});

	list += ({ "B_RED", "B_YELLOW", "B_BLUE", "B_GREEN",
	"B_MAGENTA", "B_ORANGE", "B_CYAN", "B_BLACK", "B_WHITE"});

	list += ({"BOLD", "FLASH", "RESET"});

    	for(i = 0;i < sizeof(list);i++)
	{
		words = words - ({ list[i] });
	}
	output = implode(words,"");
	return output;
}

string repeat_string(string rep, int amt)
{
	string tmp = "";
	if(!stringp(rep)) return "";
	amt = to_int(amt);
	if(!intp(amt)) return "";
	while(amt > 0)
	{
		amt--;
		tmp += rep;
	}
	return tmp;
}

void exit()
{
	string TFD, AD, *tf;
	int num = 1;

	if(ObjectInfo["File Name"] == "NIL")
	{
		remove();
		return;
	}

	AD = "/d/avatars/"+TPQN+"/";
	TFD = AD + "tmp_files/";
	seteuid(UID_ROOT);
	if(!sizeof(get_dir(AD)))
	{
		mkdir(AD);
	}
	tell_object(TP, "Saving temp file for later completion...");
	tf = get_dir(TFD);
	if(!sizeof(tf))
	{
		mkdir(TFD);
		save_object(TFD + ObjectInfo["File Name"]);
	}
	if(sizeof(tf))
	{
		if(member_array(ObjectInfo["File Name"]+".o", tf) == -1)
		{
			save_object(TFD + ObjectInfo["File Name"]);
		}
		else
		{
			while(member_array(ObjectInfo["File Name"]+"_"+num+".o", tf) != -1)
			{
				num++;
			}
			save_object(TFD + ObjectInfo["File Name"] + "_"+num);
		}
	}
	seteuid(getuid());

	remove();
}

//Function to update certain item properties based on the
//inherit for weapon type/armor type in /d/common/obj/armour
//and /d/common/obj/weapon - Saide
void update_object(string input, int size)
{
	object MyOb;
	int MyObWeight, MyObValue, MyObWcNum, MyObWcDice, MyObLwcNum, MyObLwcDice, MyObAc;
	int MyObSize;
	string MyObFile, MyObCoinType, MyObDamType, MyObProf, *MyObLimbs;

	if(!cur_menu) return;
	if(member_array(input, keys(VALID_AR_TYPES)) != -1)
	{
		MyObFile = VALID_AR_TYPES[input];
	}
	if(member_array(input, keys(VALID_WP_TYPES)) != -1)
	{
		if(size)
		{
			if(VALID_WP_SUBTYPES[input])
			{
				MyObFile = VALID_WP_SUBTYPES[input][size];
			}
			else return;
		}
		if(MyObFile)
		{
			if(!file_exists(MyObFile +".c"))
			{
				MyObFile = VALID_WP_TYPES[input];
			}
		}
		else
		{
			MyObFile = VALID_WP_TYPES[input];
		}
	}
	//tell_object(TP, "MyObFile ="+MyObFile);
	if(!file_exists(MyObFile +".c")) return;
	MyOb = new(MyObFile);
	if(!objectp(MyOb))
	{
		//tell_object(TP, "MyOb is an invalid object");
		return;
	}
	MyObWeight = (int)MyOb->query_weight();
	if(MyObWeight) ObjectInfo["Weight"] = MyObWeight;
	MyObCoinType = (string)MyOb->query_cointype();
	if(MyObCoinType) ObjectInfo["Value"][0] = MyObCoinType;
	MyObValue = (int)MyOb->query_value();
	if(MyObValue) ObjectInfo["Value"][1] = MyObValue;
	MyObWcNum = (int)MyOb->query_wc_num();
	MyObWcDice = (int)MyOb->query_wc_dice();
	if(MyObWcNum && MyObWcDice) ObjectInfo["Damage"][0] = MyObWcNum +"d"+MyObWcDice;
	MyObLwcNum = (int)MyOb->query_large_wc_num();
	MyObLwcDice = (int)MyOb->query_large_wc_dice();
	if(MyObLwcNum && MyObLwcNum) ObjectInfo["Damage"][1] = MyObLwcNum +"d"+MyObLwcDice;
	MyObDamType = (string)MyOb->query_type();
	if(MyObDamType) ObjectInfo["Damage"][2] = MyObDamType;
	MyObAc = (int)MyOb->query_ac();
	if(MyObAc) ObjectInfo["Armor Class"] = MyObAc;
	if(MyOb->is_armour())
	{
		MyObProf = (string)MyOb->query_armor_prof();
	}
	if(MyOb->is_weapon())
	{
		MyObProf = (string)MyOb->query_weapon_prof();
	}
	if(MyObProf) ObjectInfo["Prof"] = MyObProf;
	MyObLimbs = (string*)MyOb->query_limbs();
	if(sizeof(MyObLimbs)) ObjectInfo["Limbs"] = MyObLimbs;
	MyObSize = (int)MyOb->query_size();
	if(MyObSize) ObjectInfo["Size"] = MyObSize;
	if(objectp(MyOb))
	{
		//tell_object(TP, "MyOb is a Valid Object Still");
		MyOb->remove();
	}
	return;
}

//End of Item Properties Update Function

void set_directory(string str) { DIR = str; }
void init()
{
      ::init();
	cur_menu = "main";
	update_this_menu();
      display_menu();
      input_to("pick_menu_item");
}

string CheckStatus(string which)
{
	string op = "%^YELLOW%^(%^RESET%^";
	string cl = "%^YELLOW%^)%^RESET%^";
	//Color for Needed
	string nc = "%^BOLD%^%^WHITE%^";
	//Reset
	string rs = "%^RESET%^";
	//Color for something that's set
	string sc = "%^BOLD%^%^GREEN%^";
	//Color for something that's set to Default
	string de = "%^BOLD%^%^RED%^";
	//Color for something that's not set, but also not
	//required
	string tmp;
	string unc = "%^BOLD%^%^CYAN%^";
	string selected_str = op + unc + "Selected" + cl;
	string needed_str = op + nc + "Needed" + cl;
	string set_str = op + sc + "Set" + cl;
	string unset_str = op + unc + "Unset"+ cl;
	string default_str = op + de + "Default" + cl;
	if(which == "File Name")
	{
		if(ObjectInfo["File Name"] == "NIL" || ObjectInfo["File Name"] == "")
		{
			return needed_str;
		}
		else { return op + sc + ObjectInfo["File Name"] + cl; }
	}
	if(which == "Restore Temp File")
	{
		tmp = op + sc + sizeof(get_dir("/d/avatars/"+TPQN+"/tmp_files/*.o"));
		tmp += " available" + cl;
		return tmp;
	}
	if(which == "Object Type")
	{
		if(ObjectInfo["Object Type"] == "NIL" || ObjectInfo["Object Type"] == "")
		{
			return needed_str;
		}
		else { return op + sc + ObjectInfo["Object Type"] + cl; }
	}
	if(which == "Item Name")
	{
		if(ObjectInfo["Item Name"] == "NIL")
		{
			return needed_str;
		}
		else { return op + sc + ObjectInfo["Item Name"] + cl; }
	}
	if(which == "Item Identities")
	{
		if(ObjectInfo["IDS"] == "NIL" || ObjectInfo["IDS"] == "")
		{
			return needed_str;
		}
		else { return set_str; }
	}
	if(which == "Description")
	{
		if(ObjectInfo["Description"][0] == "NIL" || ObjectInfo["Description"][1] == "NIL")
		{
			return needed_str;
		}
		if(ObjectInfo["Description"][2] == "NIL")
		{
			return unset_str;
		}
		else { return set_str; }
	}
	if(which == "Writing on Object")
	{
		if(ObjectInfo["Read"][0] == "NIL" || ObjectInfo["Read"][1] == "NIL")
		{
			return unset_str;
		}
		if(ObjectInfo["Read"][1] == "common")
		{
			return default_str;
		}
		else { return set_str; }
	}
	if(which == "Lore")
	{
		if(ObjectInfo["Lore"][0] == "NIL" || ObjectInfo["Lore"][1] == "NIL")
		{
			return unset_str;
		}
		else { return set_str; }
	}
	if(which == "Value")
	{
		if(ObjectInfo["Value"][0] == "NIL" || ObjectInfo["Value"][1] == "NIL")
		{
			return unset_str;
		}
		else
		{
			return op + sc + ObjectInfo["Value"][1] + " " + ObjectInfo["Value"][0]+cl;
		}
		/*if(ObjectInfo["Value"][0] == "gold" || ObjectInfo["Value"][1] == 10)
		{
			return default_str;
		}
		else { return set_str; }*/
	}
	if(which == "Weight")
	{
		if(ObjectInfo["Weight"] == "NIL")
		{
			return needed_str;
		}
		else
		{
			return op + sc + ObjectInfo["Weight"] + cl;
		}
	}
	if(which == "Bonuses")
	{
		if(!sizeof(Bonuses))
		{
			return unset_str;
		}
		else { return set_str; }
	}
	if(which == "Heart Beat")
	{
		if(!sizeof(HeartBeat))
		{
			return unset_str;
		}
		else { return set_str; }
	}
	if(which == "Wear/Remove" || which == "Wield/Unwield")
	{
		if(cur_type == "Armor" || cur_type == "PocketArmor")
		{
			if(WieldOrWear["wear"][0] == "NIL" ||
			WieldOrWear["wear"][1] == "NIL" ||
			UnwieldOrRemove["remove"][0] == "NIL" ||
			UnwieldOrRemove["remove"][1] == "NIL")
			{
				return unset_str;
			}
			else { return set_str; }
		}
		if(cur_type == "Weapon")
		{
			if(WieldOrWear["wield"][0] == "NIL" ||
			WieldOrWear["wield"][1] == "NIL" ||
			UnwieldOrRemove["unwield"][0] == "NIL" ||
			UnwieldOrRemove["unwield"][1] == "NIL")
			{
				return unset_str;
			}
			else { return set_str; }
		}
		else { return set_str; }
	}
	if(which == "Specials")
	{
		if(!sizeof(Specials))
		{
			return unset_str;
		}
		else { return set_str; }
	}
	if(which == "Limbs")
	{
		if(ObjectInfo["Limbs"] == "NIL")
		{
			return needed_str;
		}
		else
		{
			if(sizeof(ObjectInfo["Limbs"]))
			{
				tmp = implode(ObjectInfo["Limbs"], ", ");
			}
			return op + sc + tmp + cl;
		}
	}
	if(which == "Size")
	{
		if(ObjectInfo["Size"] == "NIL")
		{
			return needed_str;
		}
		else { return op + sc + SizeMenu[ObjectInfo["Size"]-1] + cl; }
	}
	if(which == "Armor Class")
	{
		if(ObjectInfo["Armor Class"] == "NIL")
		{
			if(ObjectInfo["Object Type"] == "Armor")
			{
				return needed_str;
			}
			else { return op + sc + ObjectInfo["Armor Class"] + cl; }
		}
		else { return op + sc + ObjectInfo["Armor Class"] + cl; }
	}
	if(which == "Enchantment")
	{
		if(ObjectInfo["Enchantment"] == "NIL")
		{
			return unset_str;
		}
		else { return op + sc + ObjectInfo["Enchantment"] + cl; }
	}
	if(which == "Prof")
	{
		if(ObjectInfo["Prof"] == "NIL")
		{
			return needed_str;
		}
		else { return op + sc + ObjectInfo["Prof"] + cl; }
	}
	if(which == "Damage")
	{
		if(ObjectInfo["Damage"][0] == "NIL" ||
		ObjectInfo["Damage"][1] == "NIL" ||
		ObjectInfo["Damage"][2] == "NIL")
		{
			return needed_str;
		}
		else
		{
			tmp = op + sc + implode(ObjectInfo["Damage"], ", ");
			tmp += cl;
			return tmp;
		}
	}
	if(which == "Weapon Type")
	{
		if(ObjectInfo["Weapon Type"] == "NIL")
		{
			return unset_str;
		}
		else { return op + sc + ObjectInfo["Weapon Type"] + cl; }
	}
	if(which == "Armor Type")
	{
		if(ObjectInfo["Armor Type"] == "NIL")
		{
			return unset_str;
		}
		else { return op + sc + ObjectInfo["Armor Type"] + cl; }
	}
	if(which == "Encumbrance")
	{
		if(ObjectInfo["Encumbrance"] == "NIL")
		{
			return needed_str;
		}
		else { return set_str; }
	}
	if(cur_menu == "ObjectTypes")
	{
		if(which == cur_type)
		{
			return selected_str;
		}
	}
	if(cur_menu == "Prof")
	{
		if(which == ObjectInfo["Prof"])
		{
			return selected_str;
		}
	}
	if(cur_menu == "BonusMenu")
	{
		if(Bonuses[which])
		{
			if(sizeof(Bonuses[which]))
			{
				return op + sc + implode(Bonuses[which], ", ") + cl;
			}
		}
		if(member_array(which, BonusMenu) != -1)
		{
			return unset_str;
		}
	}
	if(cur_menu == "WieldUnwieldMenu")
	{
		if(which == "Wield Message")
		{
			if(WieldOrWear["wield"][0] == "NIL")
			{
				return unset_str;
			}
			else { return set_str; }
		}
		if(which == "Room Wield Message")
		{
			if(WieldOrWear["wield"][1] == "NIL")
			{
				return unset_str;
			}
			else { return set_str; }
		}
		if(which == "Unwield Message")
		{
			if(UnwieldOrRemove["unwield"][0] == "NIL")
			{
				return unset_str;
			}
			else { return set_str; }
		}
		if(which == "Room Unwield Message")
		{
			if(UnwieldOrRemove["unwield"][1] == "NIL")
			{
				return unset_str;
			}
			else { return set_str; }
		}
	}
	if(cur_menu == "WearRemoveMenu")
	{
		if(which == "Wear Message")
		{
			if(WieldOrWear["wear"][0] == "NIL")
			{
				return unset_str;
			}
			else { return set_str; }
		}
		if(which == "Room Wear Message")
		{
			if(WieldOrWear["wear"][1] == "NIL")
			{
				return unset_str;
			}
			else { return set_str; }
		}
		if(which == "Remove Message")
		{
			if(UnwieldOrRemove["remove"][0] == "NIL")
			{
				return unset_str;
			}
			else { return set_str; }
		}
		if(which == "Room Remove Message")
		{
			if(UnwieldOrRemove["remove"][1] == "NIL")
			{
				return unset_str;
			}
			else { return set_str; }
		}
	}
	if(cur_menu == "DamageMenu")
	{
		if(which == "Normal Damage")
		{
			if(ObjectInfo["Damage"][0] != "NIL")
			{
				return op + sc + ObjectInfo["Damage"][0] + cl;
			}
			return needed_str;
		}
		if(which == "Large Damage")
		{
			if(ObjectInfo["Damage"][1] != "NIL")
			{
				return op + sc + ObjectInfo["Damage"][1] + cl;
			}
			return needed_str;
		}
		if(which == ObjectInfo["Damage"][2])
		{
			return selected_str;
		}
	}

	if(cur_menu == "SizeMenu")
	{
		if(ObjectInfo["Size"] != "NIL")
		{
			if(which == SizeMenu[ObjectInfo["Size"]-1])
			{
				return selected_str;
			}
		}
	}
	if(cur_menu == "ArmorType")
	{
		if(which == ObjectInfo["Armor Type"])
		{
			return selected_str;
		}
	}
	if(cur_menu == "WeaponType")
	{
		if(which == ObjectInfo["Weapon Type"])
		{
			return selected_str;
		}
	}
	if(cur_menu == "Currency")
	{
		if(which == ObjectInfo["Value"][0])
		{
			return selected_str;
		}
		if(which == "Enter Amount")
		{
			if(ObjectInfo["Value"][1] == "NIL")
			{
				return unset_str;
			}
			return op + sc + ObjectInfo["Value"][1] + cl;
		}
	}
	if(cur_menu == "Description")
	{
		if(which == "Long")
		{
			if(ObjectInfo["Description"][0] == "NIL")
			{
				return needed_str;
			}
			return set_str;
		}
		if(which == "Short")
		{
			if(ObjectInfo["Description"][1] == "NIL")
			{
				return needed_str;
			}
			return set_str;
		}
		if(which == "Obvious Short")
		{
			if(ObjectInfo["Description"][2] == "NIL")
			{
				return unset_str;
			}
			return set_str;
		}
	}
	if(cur_menu == "Read")
	{
		if(which == "Enter Writing")
		{
			if(ObjectInfo["Read"][0] == "NIL")
			{
				return unset_str;
			}
			return set_str;
		}
		if(which == ObjectInfo["Read"][1])
		{
			return selected_str;
		}
	}
	if(cur_menu == "Lore")
	{
		if(which == "Enter Lore")
		{
			if(ObjectInfo["Lore"][0] == "NIL")
			{
				return unset_str;
			}
			return set_str;
		}
		if(which == "Lore Difficulty")
		{
			if(ObjectInfo["Lore"][1] == "NIL")
			{
				return unset_str;
			}
			return op + sc + ObjectInfo["Lore"][1] + cl;
		}
	}
	if(cur_menu == "RestoreTempFile")
	{
		if(MyRestoredFileName == which)
		{
			return op + sc + "Restored" + cl;
		}
	}
	return "";
}

void update_this_menu()
{
	cur_type = ObjectInfo["Object Type"];
	ThisMenu = ({});
	if(cur_menu == "main")
	{
		ThisMenu += MainMenu;
		if(cur_type == "Weapon" || cur_type == "Armor" || cur_type == "PocketArmor")
		{
			ThisMenu += MainMenuWANA;
		}
		if(cur_type == "Weapon")
		{
			ThisMenu += MainMenuWeapon;
		}
		if(cur_type == "Armor" || cur_type == "PocketArmor")
		{
			ThisMenu += MainMenuArmor;
		}
		if(cur_type == "PocketArmor")
		{
			ThisMenu += MainMenuPArmor;
		}
	}
	if(cur_menu == "ObjectTypes")
	{
		ThisMenu += OTMenu;
	}
	if(cur_menu == "Currency")
	{
		ThisMenu += CurrencyMenu;
	}
	if(cur_menu == "Description")
	{
		ThisMenu += DescriptionMenu;
	}
	if(cur_menu == "Read")
	{
		ThisMenu += ReadMenu;
	}
	if(cur_menu == "Lore")
	{
		ThisMenu += LoreMenu;
	}
	if(cur_menu == "Prof")
	{
		if(cur_type == "Armor" || cur_type == "PocketArmor")
		{
			ThisMenu += ArmorProfsMenu;
		}
		if(cur_type == "Weapon")
		{
			ThisMenu += WeaponProfsMenu;
		}
	}
	if(cur_menu == "RestoreTempFile")
	{
		ThisMenu += get_dir("/d/avatars/"+TPQN+"/tmp_files/*.o");
	}
	if(cur_menu == "WeaponType")
	{
		ThisMenu += WeaponTypeMenu;
	}
	if(cur_menu == "ArmorType")
	{
		ThisMenu += ArmorTypeMenu;
	}
	if(cur_menu == "SizeMenu")
	{
		ThisMenu += SizeMenu;
	}
	if(cur_menu == "DamageMenu")
	{
		ThisMenu += DamageMenu;
	}
	if(cur_menu == "WearRemoveMenu")
	{
		ThisMenu += WearRemoveMenu;
	}
	if(cur_menu == "WieldUnwieldMenu")
	{
		ThisMenu += WieldUnwieldMenu;
	}
	if(cur_menu == "BonusMenu")
	{
		ThisMenu += BonusMenu;
	}
	if(sizeof(ThisMenu) > 18)
	{
		if(menu_place == 0)
		{
			ThisMenu = ThisMenu[0..18];
			ThisMenu += ({"Next"});
		}
		if(menu_place == 1)
		{
			ThisMenu = ThisMenu[19..(sizeof(ThisMenu)-1)];
			ThisMenu += ({"Previous"});
		}
	}
	else { menu_place = 0; }
	if(cur_menu == "main")
	{
		if(sizeof(get_dir("/d/avatars/"+TPQN+"/tmp_files/*.o")))
		{
			ThisMenu += ({"Restore Temp File"});
		}
	}
	if(cur_menu != "main")
	{
		ThisMenu += AllSubMenus;
	}
	ThisMenu += AllMenus;
}

void display_menu()
{
	int x;
	int count = 0;
	string tmp_str = "";
	string sdec = "%^BOLD%^%^CYAN%^|%^RESET%^";
	string tmp_display = menu_header + "\n\t\tAvatar Item Maker\n"+menu_header+"\n"+sdec;
	string num = "";
	cur_type = ObjectInfo["Object Type"];
	for(x = 0;x < sizeof(ThisMenu);x++)
	{
		count++;
		if(x < 9) { num = " " + count + " "; }
		else { num = count + " "; }
		tmp_str = "\t" + num + PAD + capitalize(ThisMenu[x]) + " ";
		tmp_str += repeat_string(" ", (30 - strlen(strip_colors(tmp_str))));
		tmp_str += CheckStatus(ThisMenu[x]+"");
		tmp_str += repeat_string(" ", (58 - strlen(strip_colors(tmp_str)))) + sdec;
		tmp_display += tmp_str + "\n";
		if(x != (sizeof(ThisMenu) - 1))
		{
			tmp_display += sdec;
		}
	}
	tmp_display += menu_header + "\nPlease Select One of The Above Options.\n"+
	"Input ** At any time to exit.\n" + menu_header;
      //TP->more(explode(tmp_display, "\n"));
	tell_object(TP, tmp_display);
}

//Function for formating a response in hopefully a nice pretty method - Saide

void do_response(string msg, string msg_type)
{
	string error_header = repeat_string("%^BOLD%^%^RED%^--%^RESET%^", 35);
	string msg_header = repeat_string("%^BOLD%^%^YELLOW%^--%^RESET%^", 35);
	string rdec = "%^BOLD%^%^YELLOW%^|%^RESET%^";
	string edec = "%^BOLD%^%^RED%^|%^RESET%^";
	string tmp_string;
	if(msg_type == "error" || msg_type == "warning")
	{
		tmp_string = edec+"\t\t\t\t"+capitalize(msg_type);
		tmp_string += repeat_string(" ", 42 - strlen(strip_colors(tmp_string))) + edec;
		tmp_string = error_header + "\n" + tmp_string +"\n" + error_header +"\n" + msg + "\n";
	}
	if(msg_type == "msg")
	{
		tmp_string = rdec+"\t\t\t\tResponse";
		tmp_string += repeat_string(" ", (42 - strlen(strip_colors(tmp_string)))) + rdec;
		tmp_string = msg_header + "\n" + tmp_string + "\n" + msg_header + "\n" + msg + "\n";
	}
	write(tmp_string);
}

//End of response formating function


//Function to hightlight a specific word - Saide

void hl(string str)
{
	return "%^BOLD%^%^CYAN%^"+str+"%^RESET%^";
}

void ResetAll(string otype)
{
	ObjectInfo = (["File Name" : "NIL", "Object Type" : "NIL", "Item Name" : "NIL",
	"IDS" : "NIL", "Description" : ({"NIL", "NIL", "NIL"}), "Read" : ({"NIL", "common"}),
	"Lore" : ({"NIL", "NIL"}), "Value" : ({"gold", 10}), "Weight" : "NIL", "Size" : "NIL",
	"Armor Class" : 0, "Enchantment" : "NIL", "Prof" : "NIL",
	"Damage" : ({"NIL","NIL","NIL"}),
	"Weapon Type" : "NIL", "Armor Type" : "NIL", "Limbs" : "NIL", "Encumbrance" : "NIL"]);
	if(otype != "NIL")
	{
		ObjectInfo["Object Type"] = otype;
	}
	Bonuses = ([]);
	Specials = ([]);
	HeartBeat = ([]);
	WieldOrWear = (["wield" : ({"NIL", "NIL"}), "wear" : ({"NIL", "NIL"}),]);
	UnwieldOrRemove = (["unwield" : ({"NIL", "NIL"}), "remove" : ({"NIL", "NIL"}),]);
	cur_menu = "main";
	MyRestoredFileName = "";
	update_this_menu();
	display_menu();
	input_to("pick_menu_item");
	return 1;
}

void show_category(string input)
{
	string tmp, tmp_msg;
	if(input == "Exit")
	{
		exit();
		return;
	}
	if(input == "Clear All")
	{
		do_response("Are you sure you wish to "+hl(input)+"?\n"+
		"You will lose "+hl("ALL")+" entered data.\n"+
		"Proceed, y/n?", "warning");
		input_to("check_clear_all");
		return 1;
	}
	if(input == "Next")
	{
		menu_place++;
		update_this_menu();
		display_menu();
		input_to("pick_menu_item");
		return 1;
	}
	if(input == "Previous")
	{
		menu_place--;
		update_this_menu();
		display_menu();
		input_to("pick_menu_item");
		return 1;
	}

	if(cur_menu == "main")
	{
		if(input == "Object Type")
		{
			cur_menu = "ObjectTypes";
			update_this_menu();
			display_menu();
			input_to("pick_menu_item");
			return 1;
		}
		if(input == "Value")
		{
			cur_menu = "Currency";
			update_this_menu();
			display_menu();
			input_to("pick_menu_item");
			return 1;
		}
		if(input == "Writing on Object")
		{
			cur_menu = "Read";
			update_this_menu();
			display_menu();
			input_to("pick_menu_item");
			return 1;
		}
		if(input == "Lore")
		{
			cur_menu = "Lore";
			update_this_menu();
			display_menu();
			input_to("pick_menu_item");
			return 1;
		}
		if(input == "Limbs")
		{
			if(ObjectInfo["Limbs"] == "NIL")
			{
				do_response("Please input which limbs you want "+
				"this armor to be worn on.  Use commas to seperate "+
				"each limb.  Do not use spaces after the commas. \n"+
				"Example : left hand,right hand.", "msg");
				input_to("set_item_limbs");
				return 1;
			}
			else
			{
				do_response("This armor has already been set to be "+
				"worn on the following limbs : \n"+
				hl(identify(ObjectInfo["Limbs"])) +"\n"+
				"Do you wish to change this, y/n?", "warning");
				input_to("change_item_limbs");
				return 1;
			}
		}
		if(input == "Bonuses")
		{
			cur_menu = "BonusMenu";
			update_this_menu();
			display_menu();
			input_to("pick_menu_item");
			return 1;
		}
		if(input == "Prof")
		{
			cur_menu = "Prof";
			update_this_menu();
			display_menu();
			input_to("pick_menu_item");
			return 1;
		}
		if(input == "Armor Type")
		{
			cur_menu = "ArmorType";
			update_this_menu();
			display_menu();
			input_to("pick_menu_item");
			return 1;
		}
		if(input == "Restore Temp File")
		{
			cur_menu = "RestoreTempFile";
			update_this_menu();
			display_menu();
			input_to("pick_menu_item");
			return 1;
		}
		if(input == "Damage")
		{
			cur_menu = "DamageMenu";
			update_this_menu();
			display_menu();
			input_to("pick_menu_item");
			return 1;
		}
		if(input == "Weapon Type")
		{
			cur_menu = "WeaponType";
			update_this_menu();
			display_menu();
			input_to("pick_menu_item");
			return 1;
		}
		if(input == "Wear/Remove")
		{
			cur_menu = "WearRemoveMenu";
			update_this_menu();
			display_menu();
			input_to("pick_menu_item");
			return 1;
		}
		if(input == "Wield/Unwield")
		{
			cur_menu = "WieldUnwieldMenu";
			update_this_menu();
			display_menu();
			input_to("pick_menu_item");
			return 1;
		}
		if(input == "File Name")
		{
			if(ObjectInfo["File Name"] == "NIL")
			{
				do_response("Please enter the file name you wish to save this "+
				"object as.", "msg");
				input_to("set_file_name");
				return 1;
			}
			else
			{
				do_response("The file name of this object has already been set to "+
				hl(ObjectInfo["File Name"])+".\n"
				"Do you wish to change it, y/n?", "warning");
				input_to("check_change_file_name");
				return 1;
			}
		}
		if(input == "Armor Class")
		{
			if(ObjectInfo["Armor Class"] == 0)
			{
				do_response("Please enter the armor class that this item will "+
				"give.  You may set armor class on weapons and you may use a "+
				"negative number, but please do so sparingly.", "msg");
				input_to("set_armor_class");
				return 1;
			}
			else
			{
				do_response("The armor class on this item has already been set to "+
				hl(ObjectInfo["Armor Class"]) +".\n"+
				"Do you wish to change it, y/n?", "warning");
				input_to("check_change_armor_class");
				return 1;
			}
		}
		if(input == "Enchantment")
		{
			if(ObjectInfo["Enchantment"] == "NIL")
			{
				do_response("Please enter the enchantment you want this item to have.  "+
				"You can do from -6 to +6.  Please only use +6/-6 sparingly.", "msg");
				input_to("set_enchantment");
				return 1;
			}
			else
			{
				do_response("The enchantment for this item has already been set to "+
				hl(ObjectInfo["Enchantment"]) +".\n"+
				"Do you wish to change it, y/n?", "warning");
				input_to("check_change_enchantment");
				return 1;
			}
		}
		if(input == "Weight")
		{
			if(ObjectInfo["Weight"] == "NIL")
			{
				do_response("Please enter the weight of this object.", "msg");
				input_to("set_item_weight");
				return 1;
			}
			else
			{
				do_response("The weight for this item has already been set to "+
				hl(ObjectInfo["Weight"])+ "\n"+
				"Do you wish to change it, y/n?", "warning");
				input_to("check_change_item_weight");
				return 1;
			}
		}
		if(input == "Item Name")
		{
			if(ObjectInfo["Item Name"] == "NIL")
			{
				do_response("Please enter the name of this object.", "msg");
				input_to("set_item_name");
				return 1;
			}
			else
			{
				do_response("The Item Name of this object has already been set to "+
				hl(ObjectInfo["Item Name"]) + ".\n"
				"Do you wish to change it, y/n?", "warning");
				input_to("check_change_item_name");
				return 1;
			}
		}
		if(input == "Description")
		{
			cur_menu = "Description";
			update_this_menu();
			display_menu();
			input_to("pick_menu_item");
			return 1;
		}
		if(input == "Item Identities")
		{
			if(ObjectInfo["IDS"] == "NIL")
			{
				do_response("Please enter the ids for this object.\n"+
				"Seperate each item with a comma.\n"+
				"Example: test, test sword, sword ", "msg");
				input_to("set_item_ids");
				return 1;
			}
			else
			{
				do_response("The ids for this object are currently "+
				hl(identify(ObjectInfo["IDS"])) + ".\n"+
				"Do you wish to change them, y/n?", "warning");
				input_to("check_change_item_ids");
				return 1;
			}
		}
		if(input == "Size")
		{
			cur_menu = "SizeMenu";
			update_this_menu();
			display_menu();
			input_to("pick_menu_item");
			return 1;
		}

	}
	tmp_msg =   "$OB = the object name\n"+
			"$N = the name of the possessor\n"+
			"$P = his/her\n"+
			"$S = he/she\n"+
			"$O = him/her\n";

	if(cur_menu == "WearRemoveMenu")
	{
		if(input == "Wear Message")
		{
			if(WieldOrWear["wear"][0] == "NIL")
			{
				do_response("Please input what the wearer of this "+
				"armor will see when it's equipped.\n"+
				"$OB = the object name\n", "msg");
				input_to("choose_equip_message", "wear");
				return 1;
			}
			else
			{
				do_response(hl(WieldOrWear["wear"][0])+"\nThe above is "+
				"already set as the wear message on this object - do you wish "+
				"to change it, y/n?", "warning");
				input_to("change_equip_message", "wear");
				return 1;
			}
		}
		if(input == "Room Wear Message")
		{
			if(WieldOrWear["wear"][1] == "NIL")
			{
				do_response("Please input what the room around "+
				"the wearer of this armor will see when it's "+
				"equipped.\n"+
				tmp_msg, "msg");
				input_to("choose_equip_message", "room wear");
				return 1;
			}
			else
			{
				do_response(hl(WieldOrWear["wear"][1])+"\nThe above is "+
				"already set as what the room around the wearer of this "+
				"armor will see when its equipped - do you wish to change it, "+
				"y/n?", "warning");
				input_to("change_equip_message", "room wear");
			}
		}
		if(input == "Remove Message")
		{
			if(UnwieldOrRemove["remove"][0] == "NIL")
			{
				do_response("Please input what the wearer of this "+
				"armor will see when it's unequipped.\n"+
				"$OB = the object name\n", "msg");
				input_to("choose_equip_message", "remove");
				return 1;
			}
			else
			{
				do_response(hl(UnwieldOrRemove["remove"][0])+"\nThe above is "+
				"already set as the remove message on this object - do you wish "+
				"to change it, y/n?", "warning");
				input_to("change_equip_message", "remove");
				return 1;
			}
		}
		if(input == "Remove Room Message")
		{
			if(UnwieldOrRemove["remove"][1] == "NIL")
			{
				do_response("Please input what the room around "+
				"the wearer of this armor will see when it's "+
				"unequipped.\n"+
				tmp_msg, "msg");
				input_to("choose_equip_message", "room remove");
				return 1;

			}
			else
			{
				do_response(hl(UnwieldOrRemove["remove"][1])+"\nThe above is "+
				"already set as what the room around the wearer of "+
				"this armor will see when its removed - do you wish "+
				"to change it, y/n?", "warning");
				input_to("change_equip_message", "room remove");
				return 1;
			}
		}
	}

	if(cur_menu == "WieldUnwieldMenu")
	{
		if(input == "Wield Message")
		{
			if(WieldOrWear["wield"][0] == "NIL")
			{
				do_response("Please input what the wielder of this "+
				"weapon will see when it's equipped.\n"+
				"$OB = the object name\n", "msg");
				input_to("choose_equip_message", "wield");
				return 1;
			}
			else
			{
				do_response(hl(WieldOrWear["wield"][0])+"\nThe above is "+
				"already set as the wield message on this object - do you wish "+
				"to change it, y/n?", "warning");
				input_to("change_equip_message", "wield");
				return 1;
			}
		}
		if(input == "Room Wield Message")
		{
			if(WieldOrWear["wield"][1] == "NIL")
			{
				do_response("Please input what the room around "+
				"the wielder of this weapon will see when it's "+
				"equipped.\n"+
				tmp_msg, "msg");
				input_to("choose_equip_message", "room wield");
				return 1;
			}
			else
			{
				do_response(hl(WieldOrWear["wield"][1])+"\nThe above is "+
				"already set as what the room around the wielder of this "+
				"object will see when its equipped - do you wish to change it, "+
				"y/n?", "warning");
				input_to("change_equip_message", "room wield");
			}
		}
		if(input == "Unwield Message")
		{
			if(UnwieldOrRemove["unwield"][0] == "NIL")
			{
				do_response("Please input what the wielder of this "+
				"weapon will see when it's unequipped.\n"+
				"$OB = the object name\n", "msg");
				input_to("choose_equip_message", "unwield");
				return 1;
			}
			else
			{
				do_response(hl(UnwieldOrRemove["unwield"][0])+"\nThe above is "+
				"already set as the unwield message on this object - do you wish "+
				"to change it, y/n?", "warning");
				input_to("change_equip_message", "unwield");
				return 1;
			}
		}
		if(input == "Unwield Room Message")
		{
			if(UnwieldOrRemove["unwield"][1] == "NIL")
			{
				do_response("Please input what the room around "+
				"the wielder of this weapon will see when it's "+
				"unequipped.\n"+
				tmp_msg, "msg");
				input_to("choose_equip_message", "room unwield");
				return 1;

			}
			else
			{
				do_response(hl(UnwieldOrRemove["unwield"][1])+"\nThe above is "+
				"already set as what the room around the wielder of "+
				"this object will see when its unwielded - do you wish "+
				"to change it, y/n?", "warning");
				input_to("change_equip_message", "room unwield");
				return 1;
			}
		}
	}
	if(cur_menu == "SizeMenu")
	{
		//tell_object(TP, "SizeMenu input = "+input);
		if(member_array(input, SizeMenu) != -1)
		{
			ObjectInfo["Size"] = member_array(input, SizeMenu) + 1;
			if(ObjectInfo["Object Type"] == "Weapon" &&
			ObjectInfo["Weapon Type"] != "NIL")
			{
				update_object(ObjectInfo["Weapon Type"], ObjectInfo["Size"]);
			}
			display_menu();
			input_to("pick_menu_item");
			return 1;
		}
	}
	if(cur_menu == "DamageMenu")
	{
		if(input == "Normal Damage")
		{
			if(ObjectInfo["Damage"][0] == "NIL")
			{
				do_response("Please enter the normal damage that you "+
				"want this object to do in the form of #ddice - for "+
				"example - 3d4", "msg");
				input_to("set_item_normal_damage");
				return 1;
			}
			else
			{
				do_response("The normal damage for this item has "+
				"already been set to "+hl(ObjectInfo["Damage"][0])+".  "+
				"Do you wish to change it, y/n?", "warning");
				input_to("change_normal_item_damage");
				return 1;
			}
		}
		if(input == "Large Damage")
		{
			if(ObjectInfo["Damage"][1] == "NIL")
			{
				do_response("Please enter the large damage that you "+
				"want this object to do in the form of #ddice - for "+
				"example - 3d4", "msg");
				input_to("set_item_large_damage");
				return 1;
			}
			else
			{
				do_response("The large damage for this item has "+
				"already been set to "+hl(ObjectInfo["Damage"][1])+".  "+
				"Do you wish to change it, y/n?", "warning");
				input_to("change_large_item_damage");
				return 1;
			}
		}
		//tell_object(TP, "DamageMenu input = "+input);
		if(member_array(input, WEAPON_TYPES) != -1)
		{
			ObjectInfo["Damage"][2] = input;
			display_menu();
			input_to("pick_menu_item");
			return 1;
		}
	}

	if(cur_menu == "Lore")
	{
		if(input == "Enter Lore")
		{
			if(ObjectInfo["Lore"][0] == "NIL")
			{
				do_response("Please enter the Lore that will be on this "+
				"object.\nYou may use multiple lines.\nPlease input ** "+
				"when finished.\n", "msg");
				input_to("set_item_lore", "");
				return 1;
			}
			else
			{
				do_response("The lore for this item has already been set to \n"+
				hl(ObjectInfo["Lore"][0]) + "\n"+
				"Do you wish to change it, y/n?", "warning");
				input_to("change_item_lore");
				return 1;
			}
		}
		if(input == "Lore Difficulty")
		{
			if(ObjectInfo["Lore"][1] == "NIL")
			{
				do_response("Please input the lore difficulty.\n"+
				"Enter a number between " +hl("1 - 40")+ ".\nKeep in mind that "+
				"this is basically compared against how good "+
				"a players Academics and Spellcraft skills are.", "msg");
				input_to("set_item_lore_difficulty");
				return 1;
			}
			else
			{
				do_response("The lore difficulty for this item has already been "+
				"set to "+hl(ObjectInfo["Lore"][1]) + ".\n"+
				"Do you wish to change it, y/n?", "warning");
				input_to("change_item_lore_difficulty");
				return 1;
			}
		}
	}
	if(cur_menu == "ObjectTypes" && member_array(input, OTMenu) != -1)
	{
		if(cur_type == "NIL")
		{
			ObjectInfo["Object Type"] = input;
			display_menu();
			input_to("pick_menu_item");
			return 1;
		}
		if(input != cur_type)
		{
			do_response("You are trying to change the current "+
			"object type to "+hl(""+input+"") +" from "+hl(cur_type)+".\n"+
			"If you proceed, all data you've already entered "+
			"except for the Object Type will be lost.\n"+
			"Do you wish to proceed?  y/n?", "warning");
			input_to("change_type", input);
			return 1;
		}
	}
	if(cur_menu == "ArmorType")
	{
		if(cur_type == "NIL")
		{
			input = "Back";
		}
		else
		{
			if(member_array(input, ArmorTypeMenu) != -1)
			{
				ObjectInfo["Armor Type"] = input;
				update_object(input, 0);
				display_menu();
				input_to("pick_menu_item");
				return 1;
			}
		}
	}
	if(cur_menu == "WeaponType")
	{
		if(cur_type == "NIL")
		{
			input = "Back";
		}
		else
		{
			if(member_array(input, WeaponTypeMenu) != -1)
			{
				ObjectInfo["Weapon Type"] = input;
				update_object(input, 0);
				display_menu();
				input_to("pick_menu_item");
				return 1;
			}
		}
	}
	if(cur_menu == "RestoreTempFile")
	{
		//tell_object(TP, "Input = "+input);
		if(file_exists("/d/avatars/"+TPQN+"/tmp_files/"+input))
		{
			seteuid(UID_ROOT);
			MyRestoredFileName = input;
			tmp = replace_string(input, ".o", "");
			restore_object("/d/avatars/"+TPQN+"/tmp_files/"+tmp, 1);
			seteuid(getuid());
			if(ObjectInfo["File Name"] != tmp) ObjectInfo["File Name"] = tmp;
			display_menu();
			input_to("pick_menu_item");
			return 1;
		}
	}
	if(cur_menu == "Prof")
	{
		if(cur_type == "NIL")
		{
			input = "Back";
		}
		else
		{
			if(cur_type == "Armor" || cur_type == "PocketArmor")
			{
				if(member_array(input, ArmorProfsMenu) != -1)
				{
					ObjectInfo["Prof"] = input;
					display_menu();
					input_to("pick_menu_item");
					return 1;
				}
			}
			if(cur_type == "Weapon")
			{
				if(member_array(input, WeaponProfsMenu) != -1)
				{
					ObjectInfo["Prof"] = input;
					display_menu();
					input_to("pick_menu_item");
					return 1;
				}
			}
		}
	}
	if(cur_menu == "BonusMenu")
	{
		if(member_array(input, BonusMenu) != -1)
		{
			if(!Bonuses[input])
			{
				if(input == "skill bonus")
				{
					do_response("Please input the name of the "+
					"skill you want this item to give a bonus to.", "msg");
					input_to("pick_bonus_skill", input);
					return 1;
				}
				else
				{
					do_response("Please input how much "+
					"of a bonus this tem should give to "+
					hl(input)+".", "msg");
					input_to("pick_bonus", input, "");
					return 1;
				}
			}
			if(Bonuses[input])
			{
				if(input == "skill bonus")
				{
					do_response("This item already grants "+
					"a skill bonus - do you wish to change it?", "warning");
					input_to("change_bonus_skill", input);
					return 1;
				}
				else
				{
					do_response("This item already gives a "+
					"bonus to "+hl(input)+" do you wish to change it, "+
					"y/n?", "warning");
					input_to("change_bonus", input);
					return 1;
				}
			}
		}
	}


	if(cur_menu == "Currency")
	{
		if(member_array(input, HARD_CURRENCIES) != -1)
		{
			if(input != ObjectInfo["Value"][0])
			{
				ObjectInfo["Value"][0] = input;
			}
			display_menu();
			input_to("pick_menu_item");
			return 1;
		}
		if(input == "Enter Amount")
		{
			do_response("The current value of this object is set to "+
			hl(identify(ObjectInfo["Value"][1])) +".\n"
			"Do you wish to change this, y/n?", "warning");
			input_to("change_item_value");
			return 1;
		}
	}
	if(cur_menu == "Read")
	{
		if(member_array(input, ALL_LANGS) != -1)
		{
			if(input != ObjectInfo["Read"][1])
			{
				ObjectInfo["Read"][1] = input;
			}
			display_menu();
			input_to("pick_menu_item");
			return 1;
		}
		if(input == "Enter Writing")
		{
			if(ObjectInfo["Read"][0] == "NIL")
			{
				do_response("Please input what will be written on this "+
				"object.\nYou may use multiple lines.\nEnter ** when finished.", "msg");
				input_to("set_item_read", "");
				return 1;
			}
			else
			{
				do_response("The writing on this objectly is set to \n"+
				hl(ObjectInfo["Read"][0]) +"\n"+
				"Do you wish to change it, y/n?", "warning");
				input_to("check_change_item_read");
				return 1;
			}
		}
	}
	if(cur_menu == "Description")
	{
		if(input == "Long")
		{
			if(ObjectInfo["Description"][0] == "NIL")
			{
				do_response("Please input the long description of this item.\n"+
				"You may enter multiple lines, when finished enter **\n", "msg");
				input_to("set_long_description", "");
				return 1;
			}
			else
			{
				do_response("The current long description of this item "+
				"is set to \n"+hl(ObjectInfo["Description"][0]) + ".\n"+
				"Do you wish to change it, y/n?", "warning");
				input_to("check_change_long");
				return 1;
			}
		}
		if(input == "Short")
		{
			if(ObjectInfo["Description"][1] == "NIL")
			{
				do_response("Please input the short description of this "+
				"item.\n", "msg");
				input_to("set_short_description");
				return 1;
			}
			else
			{
				do_response("The current short description of this item "+
				"is \n"+hl(ObjectInfo["Description"][1]) + ".\n"+
				"Do you wish to change it, y/n?", "warning");
				input_to("check_change_short");
				return 1;
			}
		}
		if(input == "Obvious Short")
		{
			if(ObjectInfo["Description"][2] == "NIL")
			{
				do_response("Please input the obvious short description "+
				"of this item.\nThis is what a player sees when the "+
				"item is not identified.\n", "msg");
				input_to("set_obvious_short_description");
				return 1;
			}
			else
			{
				do_response("The obvious short description of this item "+
				"is "+hl(ObjectInfo["Description"][2]) +".\n"+
				"Do you wish to change it, y/n?", "warning");
				input_to("check_change_obvious_short");
				return 1;
			}
		}
	}

	if(input == "Back")
	{
		cur_menu = "main";
		update_this_menu();
		display_menu();
		input_to("pick_menu_item");
		return 1;
	}
}

//FUNCTION for picking a menu item and directing to the right
//submenu/request for input, etc;

void pick_menu_item(string str)
{
	int max, input;
	string true_input;
	if(str == "**") exit();
	max = sizeof(ThisMenu);
	input = to_int(str);
	if(input > max || input < 1)
	{
		do_response("You have entered "+hl(""+input+"")+".  Please input a number from "+
		hl("1 - "+max+"")+".", "error");
		input_to("pick_menu_item");
		return 1;
	}
	true_input = ThisMenu[input - 1];
	show_category(true_input);
	//input_to("pick_menu_item");
	return 1;
}

//END




//Function to pick a pick the amount of a bonus an item should give - Saide

void pick_bonus(string str, string input, string skill_name)
{
	int bnum;
	if(str == "**") return exit();
	sscanf(str, "%d", bnum);
	str = bnum;
	//tell_object(TP, "to_int(str) = "+to_int(str));
	//tell_object(TP, "input = "+input);
	if(!str || str == "" || !to_int(str))
	{
		if(skill_name == "")
		{
			do_response("Please input how much "+
			"of a bonus this item should give to "+
			hl(input)+".", "msg");
		}
		else
		{
			do_response("Please input how much "+
			"of a bonus this item should give to "+
			hl(skill_name)+".", "msg");
		}
		input_to("pick_bonus", input, skill_name);
		return 1;
	}
	if(!Bonuses[input]) Bonuses += ([input : ({})]);
	if(skill_name != "")
	{
		do_response("Adding "+hl(str)+" bonus to "+hl(skill_name)+"\n\n"+
		"Do you want this item to give a bonus to another skill, y/n?", "msg");
		Bonuses[input] += ({skill_name, ""+to_int(str)});
		input_to("add_another_skill_bonus", input);
		return 1;
	}
	do_response("Adding "+hl(str)+ " bonus to "+hl(input)+".", "msg");
	Bonuses[input] += ({""+to_int(str)});
	display_menu();
	input_to("pick_menu_item");
	return 1;
}

//End of function to pick the amount of a bonus

//Function to check if they want to add another skill bonus - Saide

void add_another_skill_bonus(string str, string input)
{
	if(lower_case(str[0..0]) == "y")
	{
		do_response("Please input the name of the "+
		"skill you want this item to give a bonus to.", "msg");
		input_to("pick_bonus_skill", input);
		return 1;
	}
	if(lower_case(str[0..0]) == "n")
	{
		do_response("Not adding another skill bonus.", "msg");
		display_menu();
		input_to("pick_menu_item");
		return 1;
	}
	do_response("Do you want this item to give a bonus to another skill, y/n?", "msg");
	input_to("add_another_skill", input);
	return 1;
}
//End of function to check if they want to add another skill bonus - Saide

//Function to check if they want to change the amount
//of an already present bonus - Saide

void change_bonus(string str, string input)
{
	if(str == "**") return exit();
	if(lower_case(str[0..0]) == "y")
	{
		do_response("Please input how much "+
		"of a bonus this item should give to "+
		hl(input)+".", "msg");
		input_to("pick_bonus", input, "");
		Bonuses[input] = ({});
		return 1;
	}
	if(lower_case(str[0..0]) == "n")
	{
		do_response("Bonus to "+hl(input)+" not changed.", "msg");
		display_menu();
		input_to("pick_menu_item");
		return 1;
	}
	do_response("This item already gives a "+
	"bonus to "+hl(input)+" do you wish to change it, "+
	"y/n?", "warning");
	input_to("change_bonus", input);
	return 1;
}

//End of function to check if they want to change the bonus an item is
//already giving - Saide

//Function to pick the skill they want an item to give a bonus to - Saide

void pick_bonus_skill(string str, string input)
{
	if(str == "**") return exit();
	if(!str || str == "" || !TP->is_valid_skill(str))
	{
		do_response("Please input the name of the "+
		"skill you want this item to give a bonus to.", "msg");
		input_to("pick_bonus_skill", input);
		return 1;
	}
	do_response("Please input how much "+
	"of a bonus this tem should give to "+
	hl(str)+".", "msg");
	input_to("pick_bonus", input, str);
	return 1;
}

//End of function to pick the skill they want an item to give a bonus to

//Function to see if they want to change the skill or skills that an item
//is already giving a bonus to - Saide
void change_bonus_skill(string str, string input)
{
	if(str == "**") return exit();
	if(lower_case(str[0..0]) == "y")
	{
		do_response("Please input the name of the "+
		"skill you want this item to give a bonus to.", "msg");
		input_to("pick_bonus_skill", input);
		Bonuses[input] = ({});
		return 1;
	}
	if(lower_case(str[0..0]) == "n")
	{
		do_response("Skill bonuses on this item not "+
		"changed.", "msg");
		display_menu();
		input_to("pick_menu_item");
		return 1;
	}
	do_response("This item already grants "+
	"a skill bonus - do you wish to change it, y/n?", "warning");
	input_to("change_bonus_skill", input);
	return 1;
}
//End of function to check if they want to change the current skill bonus set

//Function to clear what needs to be cleared
//if they change type and to make sure they
//really want to change type - Saide

void change_type(string str, string new_type)
{
	if(str == "**") return exit();
	if(lower_case(str[0..0]) == "y")
	{
		ResetAll(new_type);
		//display_menu();
		//input_to("pick_menu_item");
		return 1;
	}
	if(lower_case(str[0..0]) == "n")
	{
		display_menu();
		input_to("pick_menu_item");
		return 1;
	}
	do_response("You are trying to change the current "+
	"object type to "+hl(""+new_type+"") +" from "+hl(cur_type)+".\n"+
	"If you proceed, all data you've already entered "+
	"except for the Object Type will be lost.\n.  "+
	"Do you wish to proceed?  y/n?", "warning");
	input_to("change_type", new_type);
	return 1;
}

//END Of type change function - Saide

//Function to set the file name for an object -
//checks to make sure the file name doesn't already exist.

void set_file_name(string str)
{
	if(str == "**") return exit();
	if(str == "delete")
	{
		do_response(hl("Delete") +" is reserved and cannot be used for a "+
		"file name.  Try again.", "warning");
		input_to("set_file_name");
		return 1;
	}
	if(!str)
	{
		do_response("You must enter a valid name the file of "+
		"this object.", "warning");
		input_to("set_file_name");
		return 1;
	}
	if(file_exists(DIR+str+".c"))
	{
		do_response("A file already exists with the name "+hl(str)+"\n"+
		"Please try again.", "warning");
		input_to("set_file_name");
		return 1;
	}
	str = replace_string(str, " ", "_");
	do_response("File name set to "+hl(str)+".", "msg");
	ObjectInfo["File Name"] = str;
	display_menu();
	input_to("pick_menu_item");
	return 1;
}

//End of File Name Setting Function

//Function to see if they want to change an already set file name - Saide

void check_change_file_name(string str)
{
	if(str == "**") return exit();
	if(lower_case(str[0..0]) == "n")
	{
		do_response("File Name not changed.", "msg");
		display_menu();
		input_to("pick_menu_item");
		return 1;
	}
	if(lower_case(str[0..0]) == "y")
	{
		do_response("Please enter the file name you wish to save this "+
		"object as.", "msg");
		input_to("set_file_name");
		return 1;
	}
	do_response("The file name of this object has already been set to "+
	hl(ObjectInfo["File Name"])+".\n"
	"Do you wish to change it, y/n?", "warning");
	input_to("check_change_file_name");
	return 1;
}

//End of Function checking if they want to change an already set file name - Saide

//Function to set armor class - Saide

void set_armor_class(string str)
{
	int num;
	if(str == "**") return exit();
	if(!str || str == "" || sscanf(str, "%d", num) != 1 || strlen(str) > 2)
	{
		do_response("Please enter the armor class that this item will "+
		"give.  You may set armor class on weapons and you may use a "+
		"negative number, but please do so sparingly.", "msg");
		input_to("set_armor_class");
		return 1;
	}
	ObjectInfo["Armor Class"] = num;
	do_response("Item Armor Class set to "+hl(""+num+"")+".\n", "msg");
	display_menu();
	input_to("pick_menu_item");
	return 1;
}

//End of armor class setting function

//Function to see if they want to change an already set Armor Class - Saide

void check_change_armor_class(string str)
{
	if(str == "**") return exit();
	if(lower_case(str[0..0]) == "n")
	{
		do_response("Armor class has not been changed.", "msg");
		display_menu();
		input_to("pick_menu_item");
		return 1;
	}
	if(lower_case(str[0..0]) == "y")
	{
		do_response("Please enter the armor class that this item will "+
		"give.  You may set armor class on weapons and you may use a "+
		"negative number, but please do so sparingly.", "msg");
		input_to("set_armor_class");
		return 1;
	}
	do_response("The armor class on this item has already been set to "+
	hl(ObjectInfo["Armor Class"]) +".\n"+
	"Do you wish to change it, y/n?", "warning");
	input_to("check_change_armor_class");
	return 1;
}

//End of function to check if they want to change the armor class

//Function to set the enchantment on an item - Saide

void set_enchantment(string str)
{
	int num = 0;
	if(str == "**") return exit();
	if(!str || str == "" || sscanf(str, "%d", num) != 1 || strlen(str) > 2)
	{
		do_response("Please enter the enchantment you want this item to have.  "+
		"You can do from -6 to +6.  Please only use +6/-6 sparingly.", "msg");
		input_to("set_enchantment");
		return 1;
	}
	if(absolute_value(num) > 6)
	{
		do_response("Please enter the enchantment you want this item to have.  "+
		"You can do from -6 to +6.  Please only use +6/-6 sparingly.", "msg");
		input_to("set_enchantment");
		return 1;
	}
	ObjectInfo["Enchantment"] = num;
	do_response("Item enchantment set to "+hl(""+num+"")+".\n", "msg");
	display_menu();
	input_to("pick_menu_item");
	return 1;
}

//End of enchantment setting function

//Function to see if they want to change an already set enchantment - Saide
void check_change_enchantment(string str)
{
	if(str == "**") return exit();
	if(lower_case(str[0..0]) == "n")
	{
		do_response("Enchantment has not been changed.", "msg");
		display_menu();
		input_to("pick_menu_item");
		return 1;
	}
	if(lower_case(str[0..0]) == "y")
	{
		do_response("Please enter the enchantment you want this item to have.  "+
		"You can do from -6 to +6.  Please only use +6/-6 sparingly.", "msg");
		input_to("set_enchantment");
		return 1;

	}
	do_response("The enchantment for this item has already been set to "+
	hl(ObjectInfo["Enchantment"]) +".\n"+
	"Do you wish to change it, y/n?", "warning");
	input_to("check_change_enchantment");
	return 1;
}
//End of function to check if they want to change the enchantment

//Function to actually set an item ID - Saide

void set_item_ids(string str)
{
	string *tmp_arr;
	if(str == "**") return exit();
	if(strsrch(str, ",") == -1 || !str)
	{
		do_response("Please enter the ids for this object.\n"+
		"Seperate each item with a comma.\n"+
		"Do not use spaces after the commas.\n"+
		"Example: test,test sword,sword", "msg");
		input_to("set_item_ids");
		return 1;
	}
	tmp_arr = explode(str, ",");
	ObjectInfo["IDS"] = tmp_arr;
	do_response("Object ids set to "+
	hl(identify(ObjectInfo["IDS"])) +".", "msg");
	display_menu();
	input_to("pick_menu_item");
	return 1;

}

//End of ID setting function


//Function to check if they want to change item IDS - Saide

void check_change_item_ids(string str)
{
	if(str == "**") return exit();
	if(lower_case(str[0..0]) == "n")
	{
		do_response("Item ids not changed.", "msg");
		display_menu();
		input_to("pick_menu_item");
		return 1;
	}
	if(lower_case(str[0..0]) == "y")
	{
		do_response("Please enter the ids for this object.\n"+
		"Seperate each item with a comma.\n"+
		"Do not use spaces after the commas.\n"+
		"Example: test,test sword,sword", "msg");
		input_to("set_item_ids");
		return 1;
	}
	do_response("The ids for this object are currently "+
	hl(identify(ObjectInfo["IDS"])) + ".\n"+
	"Do you wish to change them, y/n?", "warning");
	input_to("check_change_item_ids");
	return 1;
}

//Function to set the limbs for Armor - Saide

void set_item_limbs(string str)
{
	string *tmp_arr;
	if(str == "**") return exit();
	if(strsrch(str, ",") == -1 || !str)
	{
		do_response("Please input which limbs you want "+
		"this armor to be worn on.  Use commas to seperate "+
		"each limb.  Do not use spaces after the commas. \n"+
		"Example : left hand,right hand.", "msg");
		input_to("set_item_limbs");
		return 1;
	}
	tmp_arr = explode(str, ",");
	ObjectInfo["Limbs"] = tmp_arr;
	do_response("Object Limbs set to "+
	hl(identify(ObjectInfo["Limbs"])) +".", "msg");
	display_menu();
	input_to("pick_menu_item");
	return 1;

}

//End of ID setting function


//Function to check if they want to change the items limbs - Saide

void change_item_limbs(string str)
{
	if(str == "**") return exit();
	if(lower_case(str[0..0]) == "n")
	{
		do_response("Item limbs not changed.", "msg");
		display_menu();
		input_to("pick_menu_item");
		return 1;
	}
	if(lower_case(str[0..0]) == "y")
	{
		do_response("Please input which limbs you want "+
		"this armor to be worn on.  Use commas to seperate "+
		"each limb.  Do not use spaces after the commas. \n"+
		"Example : left hand,right hand.", "msg");
		input_to("set_item_limbs");
		return 1;
	}
	do_response("This armor has already been set to be "+
	"worn on the following limbs : \n"+
	hl(identify(ObjectInfo["Limbs"])) +"\n"+
	"Do you wish to change this, y/n?", "warning");
	input_to("change_item_limbs");
	return 1;
}

//End of Item id Change Function

//Function to set an item's Normal Damage - Saide

void set_item_normal_damage(string str)
{
	int num, dice;
	if(str == "**") return exit();
	if(!str || str == "")
	{
		do_response("Please enter the normal damage that you "+
		"want this object to do in the form of #ddice - for "+
		"example - 3d4", "msg");
		input_to("set_item_normal_damage");
		return 1;
	}
	if(sscanf(str, "%dd%d", num, dice) == 2)
	{
		if(num > 0 && dice > 0)
		{
			do_response("Normal Damage set to "+hl(num+"d"+dice)+".\n", "msg");
			ObjectInfo["Damage"][0] = num+"d"+dice;
			display_menu();
			input_to("pick_menu_item");
			return 1;
		}
	}
	do_response("Please enter the normal damage that you "+
	"want this object to do in the form of #ddice - for "+
	"example - 3d4", "msg");
	input_to("set_item_normal_damage");
	return 1;
}

//End of Function to set an item's normal damage

//Function to check if they want to change the already set normal damage on an item - Saide
void change_normal_item_damage(string str)
{
	if(str == "**") return exit();
	if(lower_case(str[0..0]) == "n")
	{
		do_response("Normal damage for this item not changed.", "msg");
		display_menu();
		input_to("pick_menu_item");
		return 1;
	}
	if(lower_case(str[0..0]) == "y")
	{
		do_response("Please enter the normal damage that you "+
		"want this object to do in the form of #ddice - for "+
		"example - 3d4", "msg");
		input_to("set_item_normal_damage");
		return 1;
	}
	do_response("The normal damage for this item has "+
	"already been set to "+hl(ObjectInfo["Damage"][0])+".  "+
	"Do you wish to change it, y/n?", "warning");
	input_to("change_normal_item_damage");
	return 1;
}
//End of function to check if they want to change normal item damage

//Function to set an item's Large Damage - Saide

void set_item_large_damage(string str)
{
	int num, dice;
	if(str == "**") return exit();
	if(!str || str == "")
	{
		do_response("Please enter the large damage that you "+
		"want this object to do in the form of #ddice - for "+
		"example - 3d4", "msg");
		input_to("set_item_large_damage");
		return 1;
	}
	if(sscanf(str, "%dd%d", num, dice) == 2)
	{
		if(num > 0 && dice > 0)
		{
			do_response("Large Damage set to "+hl(num+"d"+dice)+".\n", "msg");
			ObjectInfo["Damage"][1] = num+"d"+dice;
			display_menu();
			input_to("pick_menu_item");
			return 1;
		}
	}
	do_response("Please enter the large damage that you "+
	"want this object to do in the form of #ddice - for "+
	"example - 3d4", "msg");
	input_to("set_item_large_damage");
	return 1;
}

//End of Function to set an item's large damage

//Function to check if they want to change the already set large damage on an item - Saide
void change_large_item_damage(string str)
{
	if(str == "**") return exit();
	if(lower_case(str[0..0]) == "n")
	{
		do_response("Large damage for this item not changed.", "msg");
		display_menu();
		input_to("pick_menu_item");
		return 1;
	}
	if(lower_case(str[0..0]) == "y")
	{
		do_response("Please enter the large damage that you "+
		"want this object to do in the form of #ddice - for "+
		"example - 3d4", "msg");
		input_to("set_item_large_damage");
		return 1;
	}
	do_response("The large damage for this item has "+
	"already been set to "+hl(ObjectInfo["Damage"][1])+".  "+
	"Do you wish to change it, y/n?", "warning");
	input_to("change_large_item_damage");
	return 1;
}
//End of function to check if they want to change large item damage

//Function to set an Item's Name - Saide

void set_item_name(string str)
{
	if(str == "**") return exit();
	if(!str || str == "")
	{
		do_response("You must enter a valid name for this object.", "warning");
		input_to("set_item_name");
		return 1;
	}
	ObjectInfo["Item Name"] = str;
	do_response("Item Name set to "+hl(str)+".\n", "msg");
	display_menu();
	input_to("pick_menu_item");
	return 1;
}

//End of item name set function

//Function to check if they want to change the Name of the item - Saide
void check_change_item_name(string str)
{
	if(str == "**") return exit();
	if(lower_case(str[0..0]) == "n")
	{
		do_response("Item Name not changed.", "msg");
		display_menu();
		input_to("pick_menu_item");
		return 1;
	}
	if(lower_case(str[0..0]) == "y")
	{
		do_response("Please enter the name of this object.", "msg");
		input_to("set_item_name");
		return 1;
	}
	do_response("The Item Name of this object has already been set to "+
	hl(ObjectInfo["Item Name"]) + ".\n"
	"Do you wish to change it, y/n?", "warning");
	input_to("check_change_item_name");
	return 1;
}
//END OF item name change function

//Function To Set an Items Value - Saide

void set_item_value(string str)
{
	int val;
	if(str == "**") return exit();
	val = to_int(str);
	if(!str || str == "0" || val < 0 || !intp(val))
	{
		do_response("Please enter the value you wish for this object.\n"+
		"It cannot be a negative number.", "warning");
		input_to("set_item_value");
		return 1;
	}
	do_response("Item value set to "+hl(str)+".\n", "msg");
	ObjectInfo["Value"][1] = val;
	display_menu();
	input_to("pick_menu_item");
	return 1;
}

//End of Item Value set function

//Function To Change an Items Value - Saide
void change_item_value(string str)
{
	if(str == "**") return exit();
	if(lower_case(str[0..0]) == "n")
	{
		do_response("Item value not changed.", "msg");
		display_menu();
		input_to("pick_menu_item");
		return 1;
	}
	if(lower_case(str[0..0]) == "y")
	{
		do_response("Please enter the value you wish for this object.\n"+
		"It cannot be a negative number.", "msg");
		input_to("set_item_value");
		return 1;
	}
	do_response("The current value of this object is set to "+
	hl(identify(ObjectInfo["Value"][1])) +".\n"
	"Do you wish to change this, y/n?", "warning");
	input_to("change_item_value");
	return 1;
}

//End of Value Change Function

//Function to set the long description - Saide

void set_long_description(string str, string longd)
{
	if(str == "**")
	{
		if(!longd || longd == "")
		{
			do_response("Aborting... long description for this item has not "+
			"been set.", "warning");
			display_menu();
			input_to("pick_menu_item");
			return 1;
		}
		ObjectInfo["Description"][0] = longd;
		do_response("Long description set to \n"+
		hl(ObjectInfo["Description"][0])+"\n", "msg");
		display_menu();
		input_to("pick_menu_item");
		return 1;
	}
	longd = longd + str + "\n";
	input_to("set_long_description", longd);
	return 1;
}

//End of Function to set long description

//Change Long Description Function - Saide

void check_change_long(string str)
{
	if(str == "**") return exit();
	if(lower_case(str[0..0]) == "n")
	{
		do_response("Long description not changed.\n", "msg");
		display_menu();
		input_to("pick_menu_item");
		return 1;
	}
	if(lower_case(str[0..0]) == "y")
	{
		do_response("Please input the long description of this item.\n"+
		"You may enter multiple lines, when finished enter **\n", "msg");
		input_to("set_long_description", "");
		return 1;
	}
	do_response("The current long description of this item "+
	"is set to \n"+hl(ObjectInfo["Description"][0]) + ".\n"+
	"Do you wish to change it, y/n?", "warning");
	input_to("check_change_long");
	return 1;
}

//End of Long description change function

//Function to set the lore of the object - Saide

void set_item_lore(string str, string lore_str)
{
	if(str == "**")
	{
		if(!lore_str || lore_str == "")
		{
			do_response("Aboring.... lore on this object has not been "+
			"set.", "warning");
			display_menu();
			input_to("pick_menu_item");
			return 1;
		}
		ObjectInfo["Lore"][0] = lore_str;
		do_response("Lore on this object set to \n"+
		hl(ObjectInfo["Lore"][0]) + "\n", "msg");
		display_menu();
		input_to("pick_menu_item");
		return 1;
	}
	lore_str = lore_str + str + "\n";
	input_to("set_item_lore", lore_str);
	return 1;
}

//End of Function to set item lore

//Function to check if they want to change the lore on an object - Saide

void change_item_lore(string str)
{
	if(str == "**") return exit();
	if(lower_case(str[0..0]) == "n")
	{
		do_response("Item lore has not been changed.", "msg");
		display_menu();
		input_to("pick_menu_item");
		return 1;
	}
	if(lower_case(str[0..0]) == "y")
	{
		do_response("Please enter the Lore that will be on this "+
		"object.\nYou may use multiple lines.\nPlease input ** "+
		"when finished.\n", "msg");
		input_to("set_item_lore", "");
		return 1;
	}

	do_response("The lore for this item has already been set to \n"+
	hl(ObjectInfo["Lore"][0]) + "\n"+
	"Do you wish to change it, y/n?", "warning");
	input_to("change_item_lore");
	return 1;
}

//End of Function to check if they wanna change the lore

//Function to set the lore difficulty - Saide

void set_item_lore_difficulty(string str)
{
	if(str == "**") return exit();
	if(!str || str == 0)
	{
		do_response("Please input a number, it must be between "+hl("1 - 40")+".", "warning");
		input_to("set_item_lore_difficulty");
		return 1;
	}
	if(to_int(str) > 40 || to_int(str) < 1)
	{
		do_response("Please input a number, it must be between "+hl("1 - 40")+".", "warning");
		input_to("set_item_lore_difficulty");
		return 1;
	}
	ObjectInfo["Lore"][1] = to_int(str);
	do_response("Item Lore Difficulty set to "+hl(ObjectInfo["Lore"][1])+".", "msg");
	display_menu();
	input_to("pick_menu_item");
	return 1;
}

//End of lore difficulty setting function

//Function to see if they want to change the lore difficulty - Saide

void change_item_lore_difficulty(string str)
{
	if(str == "**") return exit();
	if(lower_case(str[0..0]) == "n")
	{
		do_response("Lore difficulty has not been changed.", "msg");
		display_menu();
		input_to("pick_menu_item");
		return 1;
	}
	if(lower_case(str[0..0]) == "y")
	{
		do_response("Please input the lore difficulty.\n"+
		"Enter a number between " +hl("1 - 40")+ ".\nKeep in mind that "+
		"this is basically compared against how good "+
		"a players Academics and Spellcraft skills are.", "msg");
		input_to("set_item_lore_difficulty");
		return 1;
	}
	do_response("The lore difficulty for this item has already been "+
	"set to "+hl(ObjectInfo["Lore"][1]) + ".\n"+
	"Do you wish to change it, y/n?", "warning");
	input_to("change_item_lore_difficulty");
	return 1;
}

//End of function to see if they want to change the lore difficulty - Saide

//Function to set what's written on the object - Saide

void set_item_read(string str, string read_str)
{
	if(str == "**")
	{
		if(!read_str || read_str == "")
		{
			do_response("Aborting... writing on this object has not been "+
			"set.", "warning");
			display_menu();
			input_to("pick_menu_item");
			return 1;
		}
		ObjectInfo["Read"][0] = read_str;
		do_response("Writing on this object set to \n"+
		hl(ObjectInfo["Read"][0])+"\n", "msg");
		display_menu();
		input_to("pick_menu_item");
		return 1;
	}
	read_str = read_str + str + "\n";
	input_to("set_item_read", read_str);
	return 1;
}

//End of function to set writing on object

//Functon to see if they want to change what's written on the object - Saide

void check_change_item_read(string str)
{
	if(str == "**") return exit();
	if(lower_case(str[0..0]) == "n")
	{
		do_response("Writing on object not changed.\n", "msg");
		display_menu();
		input_to("pick_menu_item");
		return 1;
	}
	if(lower_case(str[0..0]) == "y")
	{
		do_response("Please input what will be written on this "+
		"object.\nYou may use multiple lines.\nEnter ** when finished.", "msg");
   		input_to("set_item_read", "");
		return 1;
	}
	do_response("The writing on this objectly is set to \n"+
	hl(ObjectInfo["Read"][0]) +"\n"+
	"Do you wish to change it, y/n?", "warning");
	input_to("check_change_item_read");
	return 1;
}

//End of change writing function

//Function to Set Short Description - Saide

void set_short_description(string str)
{
	if(str == "**") return exit();
	if(!str || str == "" || str == "0")
	{
		do_response("You must enter a valid short description.\n", "warning");
		input_to("set_short_description");
		return 1;
	}
	do_response("Item's short description set to \n"+
	hl(str), "msg");
	ObjectInfo["Description"][1] = str;
	display_menu();
	input_to("pick_menu_item");
	return 1;
}

//End of Function To set Short Description

//Function To Change Short Description - Saide

void check_change_short(string str)
{
	if(str == "**") return exit();
	if(lower_case(str[0..0]) == "n")
	{
		do_response("Short description not changed.\n", "msg");
		display_menu();
		input_to("pick_menu_item");
		return 1;
	}
	if(lower_case(str[0..0]) == "y")
	{
		do_response("Please input the short description of this "+
		"item.\n", "msg");
		input_to("set_short_description");
		return 1;
	}
	do_response("The current short description of this item "+
	"is \n"+hl(ObjectInfo["Description"][1]) + ".\n"+
	"Do you wish to change it, y/n?", "warning");
	input_to("check_change_short");
	return 1;
}

//End of Change Short Function - Saide

//Function to set the obvious short description - Saide

void set_obvious_short_description(string str)
{
	if(str == "**") return exit();
	if(!str || str == "" || str == "0")
	{
		do_response("Please enter a valid obvious short description.\n", "warning");
		input_to("set_obvious_short_description");
		return 1;
	}
	do_response("Item's obvious short description set to \n"+
	hl(str), "msg");
	ObjectInfo["Description"][2] = str;
	display_menu();
	input_to("pick_menu_item");
	return 1;
}

//End of obvious short description set function - Saide

//Function to check if they want to change the obvious short - Saide

void check_change_obvious_short(string str)
{
	if(str == "**") return exit();
	if(lower_case(str[0..0]) == "n")
	{
		do_response("Obvious short description not changed.\n", "msg");
		display_menu();
		input_to("pick_menu_item");
		return 1;
	}
	if(lower_case(str[0..0]) == "y")
	{
		do_response("Please input the obvious short description "+
		"of this item.\nThis is what a player sees when the "+
		"item is not identified.\n", "msg");
		input_to("set_obvious_short_description");
		return 1;
	}
	do_response("The obvious short description of this item "+
	"is "+hl(ObjectInfo["Description"][2]) +".\n"+
	"Do you wish to change it, y/n?", "warning");
	input_to("check_change_obvious_short");
	return 1;
}

//End of obvious short description change function

//Function to set the weight of the object - Saide

void set_item_weight(string str)
{
	if(str == "**") return exit();
	if(!str)
	{
		do_response("Please enter the weight of this object.", "msg");
		input_to("set_item_weight");
		return 1;
	}
	if(to_int(str) < 0)
	{
		do_response("The weight of this object cannot be "+hl("below 0")+".", "warning");
		input_to("set_item_weight");
		return 1;
	}
	ObjectInfo["Weight"] = to_int(str);
	do_response("The weight of this object has been set to " + hl(ObjectInfo["Weight"]) +
	".", "msg");
	display_menu();
	input_to("pick_menu_item");
	return 1;
}

//End of weight setting function

//Function to change the items weight - Saide

void check_change_item_weight(string str)
{
	if(str == "**") return exit();
	if(lower_case(str[0..0]) == "n")
	{
		do_response("The items weight has not been changed.", "msg");
		display_menu();
		input_to("pick_menu_item");
		return 1;
	}
	if(lower_case(str[0..0]) == "y")
	{
		do_response("Please enter the weight of this object.", "msg");
		input_to("set_item_weight");
		return 1;
	}
	do_response("The weight for this item has already been set to "+
	hl(ObjectInfo["Weight"])+ "\n"+
	"Do you wish to change it, y/n?", "warning");
	input_to("check_change_item_weight");
	return 1;
}

//End of function to see if they want to change items weight

//If they choose Clear All - Make sure they really want to - Saide

void check_clear_all(string str)
{
	if(str == "**") return exit();
	if(lower_case(str[0..0]) == "y")
	{
		do_response("Clearing "+hl("ALL")+" data...", "warning");
		ResetAll("NIL");
		return 1;
	}
	do_response("Aborting... not reseting data...", "msg");
	display_menu();
	input_to("pick_menu_item");
	return 1;
}

//End of Clear All Check
