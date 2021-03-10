#include <std.h>
#include <valid_bonuses.h>

inherit DAEMON;

int help();

string repeat_string(string str, int amt);

string header = repeat_string("%^BOLD%^%^GREEN%^-=%^RESET%^", 30);

string *AllBonuses = VALID_BONUSES + ({"Ac", "enchantment"});

string repeat_string(string str, int amt)
{
	int x;
	string tmp = "";
	while(amt > 0)
	{
		tmp += str;
		amt--;
	}
	return tmp;
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

int cmd_exitem(string str)
{
	object ob;
	int x, y;
	mapping tmp_map;
	string display_str, *tmp = ({}), *sb_keys;
	string tmp_str;
	string dec = "%^BOLD%^%^GREEN%^|%^RESET%^";
	if(!str)
	{
		tell_object(TP, "Please use <exitem [object]>");
		return 1;
	}
	if(!objectp((ob = present(str, TP))))
	{
		if(!objectp((ob = present(str, ETP))))
		{
			tell_object(TP, "Sorry, couldn't find an object with the name "+
					str+".  Please try again.");
			return 1;
		}
	}
	if(living(ob)) 
	{
		tell_object(TP, "Sorry, this only works on a non-living object.  Please "+
		"try again!");
		return 1;
	}
	tmp_str = "\t"+ob->query_short();
	//tmp_str += repeat_string(" ", 53 - strlen(strip_colors(tmp_str))) + dec;
	display_str = tmp_str + "\n" + header + "\n";
	for(x = 0;x < sizeof(AllBonuses);x++)
	{
		if(AllBonuses[x] == "Ac")
		{
			tmp_str = dec+"\t%^BOLD%^%^RED%^Armor Class%^RESET%^ ";
			tmp_str += repeat_string("%^BOLD%^%^WHITE%^-%^RESET%^", 
			25 - strlen(strip_colors(tmp_str)));
			tmp_str += " " +ob->query_ac();
			tmp_str += repeat_string(" ", 53 - strlen(strip_colors(tmp_str))) + dec;
			display_str += tmp_str + "\n";
			continue;
		}
		if(!ob->query_property(AllBonuses[x])) continue;
		if(AllBonuses[x] == "skill bonus")
		{
			tmp_map = ob->query_property("skill bonus");
			if(!sizeof(tmp_map)) continue;
			sb_keys = keys(tmp_map);
			for(y = 0;y < sizeof(sb_keys);y++)
			{	
				tmp_str = dec +"\t%^BOLD%^%^RED%^"+capitalize(sb_keys[y]) +"%^RESET%^ ";
				tmp_str += repeat_string("%^BOLD%^%^WHITE%^-%^RESET%^",
				25 - strlen(strip_colors(tmp_str)));
				
				tmp_str += " " +tmp_map[sb_keys[y]];
				tmp_str += repeat_string(" ", 53 - strlen(strip_colors(tmp_str))) + dec;
				display_str += tmp_str + "\n";
				continue;
			}
			continue;
		}
		tmp_str = dec+"\t%^BOLD%^%^RED%^" + capitalize(AllBonuses[x]) + "%^RESET%^ ";
		tmp_str += repeat_string("%^BOLD%^%^WHITE%^-%^RESET%^", 
		25 - strlen(strip_colors(tmp_str)));
		tmp_str += " " +(string)ob->query_property(AllBonuses[x]); 
		tmp_str += repeat_string(" ", 53 - strlen(strip_colors(tmp_str))) + dec;
		display_str += tmp_str + "\n";
		continue;
	}
	display_str += header;
	tell_object(TP, display_str);
      return 1;
}



int help(){
   	write(
@SAIDE
    	Usage:  exitem <object>
	
	You can use this command on an object either in your inventory or in 
	your environment and it will display a list of it's different bonuses, 
	enchantment, armor class, etc. 
SAIDE
       );
   	return 1;
}
