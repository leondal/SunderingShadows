//Coded by Saide As A better/more effective way for avatars to clone items

#include <std.h>
#include <daemons.h>
#include <security.h>
#include <move.h>
#define AVDIR "/cmds/avatar/avclone_info/"
#define AVAREAS AVDIR + "AreaInfo"
inherit DAEMON;

private mapping AreaObjects, AvcloneAreas;
nosave mapping TmpMap;
nosave string EUID_TMP;
nosave int IC;
nosave string hformat = "\n%^BOLD%^%^GREEN%^===================================="+
"=====================================\n%^RESET%^";

mixed build_avclone_database(int myFlag);

//Taken from Grendel's Code - in order to sort the arrays
//Saide

private void swap(int i, int j, string* stuff)
{
        string tmp;
        tmp = stuff[i];
        stuff[i]=stuff[j];
        stuff[j]=tmp;
}

void AvcloneAreaRestore()
{
	if(mapp(AvcloneAreas))
	{
		if(sizeof(keys(AvcloneAreas))) return;
	}
	AvcloneAreas = ([]);
	seteuid(UID_DAEMONSAVE);
	restore_object(AVAREAS);
	seteuid(getuid());
}

void AvcloneObjectRestore(string area)
{
	if(!stringp(area)) return;
	if(!mapp(AvcloneAreas)) AvcloneAreaRestore();
	if(member_array(area, keys(AvcloneAreas)) == -1) return;
	AreaObjects = ([]);
    TmpMap = ([]);
	TmpMap = copy(AvcloneAreas);
    //tell_object(TP, "AvcloneAreas = "+identify(AvcloneAreas));
	AvcloneAreas = ([]);
    if(!file_exists(AVDIR+area+".o"))
    {
        AreaObjects = ([]);
        return;
    }
	seteuid(UID_RESTORE);
	restore_object(AVDIR+area);
    seteuid(getuid());
	AvcloneAreas = TmpMap;
    //tell_object(TP, "AvcloneAreas now = "+identify(AvcloneAreas));
}

void AvcloneAreasSave()
{
	TmpMap = ([]);
	TmpMap = copy(AreaObjects);
	AreaObjects = ([]);
    seteuid(UID_RESTORE);
	save_object(AVAREAS);
    seteuid(getuid());
	AreaObjects = TmpMap;
}

void AvcloneObjectSave(string area)
{
    TmpMap = ([]);
	TmpMap = copy(AvcloneAreas);
	AvcloneAreas = ([]);
    seteuid(UID_RESTORE);
	save_object(AVDIR + area);
    seteuid(getuid());
	AvcloneAreas = TmpMap;
}

mixed *sort(string *stuff)
{
    int i,j;

 	for(j=0;j<sizeof(stuff);j++)
	{
      	for(i=sizeof(stuff)-1;i>j;i--)
		{
    		if(!stringp(stuff[i-1]) || !strlen(stuff[i-1])) continue;
			if(!stringp(stuff[i]) || !strlen(stuff[i-1])) continue;
		    if(lower_case(stuff[i]) < lower_case(stuff[i-1]))
			{
		    	swap(i-1,i,stuff);
        	}
      	}
    }
	return stuff;
}


//END of what's stolen from Grendel

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

string create_display_list(mapping objects_list, int flag)
{
	string *terms = ({}), *object_info = ({});
	int x, acount, ocount, wcount, mcount;
	string tmp_str = "";
	string tmp_arm = "%^CYAN%^Armor: %^RESET%^\n";
	string tmp_wep = "%^CYAN%^Weapons: %^RESET%^\n";
	string tmp_other = "%^CYAN%^Other: %^RESET%^\n";
	string tmp_mon = "%^CYAN%^Monster: %^RESET%^\n";
	terms = keys(objects_list);
	for(x = 0;x < sizeof(terms);x++)
	{
		tmp_str = "";
		object_info = objects_list[terms[x]];
		tmp_str += "%^CYAN%^Short:  %^RESET%^";
		tmp_str += terms[x] + "\n";
		tmp_str += "\t%^CYAN%^Clone Words:  %^RESET%^";
		tmp_str += object_info[4][0] + ", ";
		tmp_str += object_info[4][1] + "\n";
		if(wizardp(TP))
		{
			tmp_str += "\t%^CYAN%^File Name:  %^RESET%^";
			tmp_str += object_info[1] + "\n";
		}
		if(flag == 1)
		{
			tmp_str += "\t%^CYAN%^Object Type:  %^RESET%^";
			tmp_str += object_info[3] + "\n";
			tmp_str += "\t%^CYAN%^Area:  %^RESET%^";
			tmp_str += object_info[2] + "\n";
		}
		if(object_info[3] == "armor")
		{
			acount++;
			tmp_arm += acount + ".) " + tmp_str + "\n";
		}
		else if(object_info[3] == "weapon")
		{
			wcount++;
			tmp_wep += wcount + ".) " + tmp_str + "\n";
		}
		else if(object_info[3] == "monster")
		{
			mcount++;
			tmp_mon += mcount + ".) " +tmp_str +"\n";
		}
		else
		{
			ocount++;
			tmp_other += ocount + ".) " + tmp_str + "\n";
		}
	}
	return tmp_arm + tmp_wep + tmp_mon+ tmp_other;
}

void avclone_register(object ob)
{
	string *myAreas, myArea, *tmparr, myDir;
	int x, flag;
	if(!objectp(TO)) return;
	if(!objectp(ob)) return;
	myAreas = keys(AvcloneAreas);
	tmparr = explode(base_name(ob), "/");
	if(sizeof(tmparr) < 1) myArea = tmparr[0];
	else myArea = tmparr[1];
	myDir = implode(tmparr[0..(sizeof(tmparr)-2)], "/")+"/";

	if(member_array(myArea, myAreas) != -1)
	{
		if(member_array(myDir, AvcloneAreas[myArea]) != -1)
		{
			tell_object(TP, ob->query_short() + " is already registered in the "+
			myArea + " area!");
			return 1;
		}
		for(x = 0;x < sizeof(myAreas);x++)
		{
			if(member_array(myDir, AvcloneAreas[myAreas[x]]) != -1)
			{
				tell_object(TP, ob->query_short() + " is already registered in the "+
				myAreas[x] + " area!");
				return 1;
			}
			continue;
		}
		AvcloneAreas[myArea] += ({myDir});
		flag = 1;
	}
	else
	{
		for(x = 0;x < sizeof(myAreas);x++)
		{
			if(member_array(myDir, AvcloneAreas[myAreas[x]]) != -1)
			{
				tell_object(TP, ob->query_short() + " is already registered in the "+
				myAreas[x] + " area!");
				return 1;
			}
			continue;
		}
		AvcloneAreas += ([myArea : ({myDir}) ]);
		flag = 2;
	}
	if(flag)
	{
		AvcloneAreasSave();
		if(flag == 1)
		{
			tell_object(TP, "Registering "+ob->query_short() + " in the area "+myArea+"!");
			build_avclone_database(0);
		}
		else
		{
			tell_object(TP, "Adding the area "+myArea+" to avclone and registering "+
			ob->query_short() + " in it!");
			build_avclone_database(0);
		}
		return 1;
	}
}


void nuke(object ob)
{
	if(!ob)
	{
		return;
	}
	if(environment(ob)) return;
	ob->remove();
	if(ob)
	{
		destruct(ob);
	}
}

//building a database that will look like
//(["area name" : (["directory 1" : (["objects" : "objects information mapping", "count" : count, "false count" : false count]) ]) ])

mixed build_avclone_database(int myFlag)
{
	string *areas, object_type, *tmp_arr, true_short, short;
	string myShort, myFileName, myTrueFileName;
	int depth, x, y, i, count, false_count;
	string myArea, myDir;
	int myCount, flag;
	string *object_files = ({}), *search_words = ({});
	mapping avclone_in_depth_info = ([]);
	mapping myDirObjects = ([]);
	object ob;

	areas = sort(keys(AvcloneAreas));

	for(x = 0;x < sizeof(areas);x++)
	{
		myArea = areas[x];
		AvcloneObjectRestore(myArea);

		for(y = 0; y < sizeof(AvcloneAreas[myArea]);y++)
		{
			//should be the directory
			myDir = AvcloneAreas[myArea][y];
			if(myArea == "avatars") object_files = get_dir("/d/avatars/"+myDir+"/*.c");
			else object_files = get_dir(myDir + "*.c");
			if(sizeof(keys(AreaObjects)))
			{
				if(AreaObjects[myDir])
				{
					//tell_object(TP, "My dir = "+myDir);
					myCount = AreaObjects[myDir]["count"];
					myCount += AreaObjects[myDir]["false count"];
					//tell_object(TP, "myCount = "+myCount +"&& sizeof = "+sizeof(object_files));
					if(myCount == sizeof(object_files)) continue;
				}
			}

			myDirObjects = ([]);

			//Starting of File Loop - Saide
			for(i = 0;i < sizeof(object_files);i++)
			{
				if(myArea == "avatars")
                {
                    if(catch(ob = new("/d/avatars/" + myDir +"/"+ object_files[i])))
                    {
                        false_count++;
                        continue;
                    }
                }
				else
                {
                    if(catch(ob = new(myDir + object_files[i])))
                    {
                        false_count++;
                        continue;
                    }
                }
				if(!objectp(ob))
				{
					false_count++;
					continue;
				}
				else
				{
					search_words = ({});
					short = (string)ob->query("short");
					if(short)
					{
						if(functionp(short))
						{
							short = ob->query_short();
						}
						true_short = strip_colors(short);
						if(stringp(true_short)) true_short = lower_case(true_short);
						if(living(ob))
						{
							object_type = "monster";
						}
						else if(ob->is_armour())
						{
							object_type = "armor";
						}
						else if(ob->is_weapon())
						{
							object_type = "weapon";
						}
						else
						{
							object_type = "other";
						}
					}
                    continue;
				}
				myTrueFileName = base_name(ob);
				tmp_arr = explode(myTrueFileName, "/");
				if(myArea == "avatars")
				{
					myFileName = tmp_arr[(sizeof(tmp_arr)-2)] + "/" + tmp_arr[(sizeof(tmp_arr)-1)];
				}
				else
				{
					myFileName = tmp_arr[(sizeof(tmp_arr)-1)];
				}
				flag++;
				count++;
				search_words += ({lower_case(myFileName)});
				search_words += ({true_short});
				myDirObjects += ([short : (["filename" : myFileName, "true filename" : myTrueFileName,
				"object type" : object_type, "search words" : search_words ]) ]);
				nuke(ob);
				continue;
			}
			//end of object building loop

			if(AreaObjects[myDir])
			{
				AreaObjects[myDir]["objects"] = myDirObjects;
				AreaObjects[myDir]["count"] = count;
				AreaObjects[myDir]["false count"] = false_count;
			}
			else AreaObjects += ([ myDir : (["objects" : myDirObjects, "count" : count, "false count" : false_count ]) ]);
			false_count = 0;
			count = 0;
			continue;
		}
		AvcloneObjectSave(myArea);
		continue;
	}
	if(flag)
	{
		SAVE_D->remove_array("AVCLONE_IN_DEPTH");
	}
}

mixed compile_objects_list(string area, string type, int flag)
{
	string *areas, myArea, fname, tr_fname, object_type, true_short, short;
	int depth, x, y, i, z, k;
	string *myDirs, *search_words = ({}), *myShorts, myDir, *TmpDirs;
	object ob; //Variable that handles loading/manipulating an object

	//Format of (["Short" : ({"file_name", "true_file_name", "area", "type",
	//({"Search words"})]);
	mapping cp_objects_list = ([]), myTmp = ([]), tmpObjectInfo = ([]);

	areas = keys(AvcloneAreas);

	area = lower_case(area);
	type = lower_case(type);
	if(!stringp(type) || !strlen(type)) return -4;

	if(area != "search" && area != "avsearch")
	{
		depth = 1;
		if(member_array(area, areas) == -1)
		{
			return -1;
		}
		if(type != "armor" && type != "weapon" && type != "other" && type != "monster")
		{
			type = "all";
		}
	}
	else
	{
		depth = sizeof(areas) - 1;
		tell_object(TP, "Searching "+sizeof(areas)+" areas.");
	}
    IC = 0;
    TmpDirs = ({});
	for(x = 0;x < depth;x++)
	{
		if(area == "search")
		{
			myArea = areas[x];
		}
		else
		{
			myArea = area;
		}
        //tell_object(TP, "Searching area "+myArea);
        AreaObjects = ([]);
        AvcloneObjectRestore(myArea);
		myDirs = keys(AreaObjects);
		if(!sizeof(myDirs)) continue;

		for(i = 0;i < sizeof(myDirs);i++)
		{
			myDir = myDirs[i];
            if(strsrch(myDir, myArea) == -1)
            {
                TmpDirs += ({myDir});
                continue;
            }
			tmpObjectInfo = AreaObjects[myDir]["objects"];
            if(!sizeof(myShorts = keys(tmpObjectInfo))) continue;
            IC += sizeof(myShorts);
  			for(z = 0;z < sizeof(myShorts);z++)
			{
                flag = 0;
				if(area == "search")
				{
					search_words = tmpObjectInfo[myShorts[z]]["search words"];
					for(k = 0;k < sizeof(search_words);k++)
					{
                  		if(!stringp(search_words[k])) continue;
						if(strsrch(search_words[k], type) != -1) flag++;
						continue;
					}
				}
				else
				{
					if(type != "all" && type != tmpObjectInfo[myShorts[z]]["object type"]) continue;
					flag++;
				}
				if(flag)
				{
					search_words = tmpObjectInfo[myShorts[z]]["search words"];;
					fname = tmpObjectInfo[myShorts[z]]["filename"];
					tr_fname = tmpObjectInfo[myShorts[z]]["true filename"];
					object_type = tmpObjectInfo[myShorts[z]]["object type"];
					cp_objects_list += ([myShorts[z] : ({fname, tr_fname, myArea,
					object_type, search_words})]);
					continue;
				}
			}
			continue;
		}
        if(sizeof(TmpDirs))
        {
            for(i = 0;i < sizeof(TmpDirs);i++)
            {
                map_delete(AreaObjects, TmpDirs[i]);
            }
            if(sizeof(keys(AreaObjects))) AvcloneObjectSave(myArea);
            else
            {
                map_delete(AvcloneAreas, myArea);
                AvcloneAreasSave();
                if(file_exists(AVDIR+myArea+".o"))
                {
                    seteuid(UID_RESTORE);
                    rm(AVDIR+myArea+".o");
                    seteuid(geteuid());
                }
            }

        }
		//END OF FILE LOOP
        continue;

	}
    if(sizeof(TmpDirs))
    {

    }
	return cp_objects_list;
}

int cmd_avclone(string str)
{
	string *tmp = ({}), head, area, item, type, short;
	string *areas = ({}), object_names = ({});
	string tmps = "";
	object ob;
	mixed objects_list;
	int i, x, y;

	AvcloneAreaRestore();
	if(mapp(AvcloneAreas))
	{
		if(sizeof(keys(AvcloneAreas))) areas = sort(keys(AvcloneAreas));
	}

	//Shows the available areas to clone items from - Saide
	if(!str)
	{
		head = hformat;
		head += "\t\t\t\tAreas";
		head += hformat;
		if(str == "avatars") areas = AvcloneAreas["Avatars"];
		for(i = 0;i < sizeof(areas);i++)
		{
			tmps = "";
			if((i+1) < 10)
			{
				tmps += " " + (i + 1) + ".) ";
			}
			else
			{
				tmps += (i+1) + ".) ";
			}
			tmps += capitalize(areas[i]);
			tmp += ({tmps});
		}
		write(head);
		write(format_page(tmp, 3));
		write(hformat);
		return 1;
	}
    EUID_TMP = geteuid();

	if(str == "rebuild")
	{
		tell_object(TP, "Refreshing avclone database.");
    	build_avclone_database(0);
		return 1;
	}

	if(sscanf(str, "%s %s", area, type) == 2)
	{
		//Part of the code that handles searching - Saide
		if(area == "remove")
		{
			if((string)TP->query_name() == "saide")
			{
				if(!type) return 1;
				if(type)
				{
					map_delete(AvcloneAreas, type);
					AvcloneAreasSave();
					if(file_exists(AVDIR+type+".o"))
					{
						seteuid(UID_RESTORE);
						rm(AVDIR+type+".o");
						seteuid(getuid());
					}
					tell_object(TP, "removing area "+type+" from avclone!");
				}
				return 1;
			}
		}
		if(area == "register")
		{
			if(!type)
			{
				tell_object(TP, "What do you wish to register with avclone?");
				return 1;
			}
			if(!objectp(ob = present(type, TP)))
			{
				if(!objectp(ob = present(type, ETP)))
				{
					tell_object(TP, "You do not see a "+type+" to register!");
					return 1;
				}
				if(userp(ob))
				{
					tell_object(TP, "You cannot register a player!");
					return 1;
				}
			}
			tell_object(TP, "Attemping to register "+ob->query_short()+" to work "+
			"with avclone.");
			avclone_register(ob);
			return 1;
		}

		if(area == "search" || area == "avsearch")
		{
			if(!type || type == "")
			{
				tell_object(TP, "You must enter a valid search term.");
				return 1;
			}
			if(area == "search")
			{
				objects_list = compile_objects_list(area, type, 0);
                if(!mapp(objects_list)) objects_list = compile_objects_list(area, type, 0);
			}
			else if(area == "avsearch")
			{
				objects_list = compile_objects_list(area, type, 1);
                if(!mapp(objects_list)) objects_list = compile_objects_list(area, type, 1);
			}
            if(!mapp(objects_list))
            {
                tell_object(TP, "Apparently something broke... Saide is trying to sort it out "+
                "hopefully this is only temporary. ");
                return 1;
            }
			y = sizeof(keys(objects_list));
			if(y)
			{
				tell_object(TP, "Your search found %^BOLD%^%^WHITE%^("+y
                + "/"+IC+")%^RESET%^ items"+
				" that matched the term "+type);
				tmps += create_display_list(objects_list, 1);
				TP->more(explode(tmps, "\n"));
				return 1;
			}
			else
			{
				tell_object(TP, "Sorry, but no items were found with the term "+
				type+".  Please try again.");
				return 1;
			}
		}
		//END OF SEARCH CODE AREA - Saide

		//START of Code That Tries to Clone the Item - Saide
		area = lower_case(area);
		type = lower_case(type);
		//type = explode(type, " ")[0];
		//tell_object(TP, "type = "+type+" and area = "+area);


		if(type != "armor" && type != "other" && type != "weapon" && type != "monster")
		{
			if((objects_list = compile_objects_list(area, type, 1)) == -1)
			{
				tell_object(TP, "No area with the name "+area+" found.  Try again.");
				return 1;
			}
			object_names = keys(objects_list);
			for(x = 0;x < sizeof(object_names);x++)
			{
				if(member_array(type, objects_list[object_names[x]][4]) != -1)
				{
					if(catch(ob = new(objects_list[object_names[x]][1])))
                    {
                        tell_object(TP, "Error trying to clone object.");
                        return 1;
                    }
					break;
				}
			}
			if(!ob)
			{
				tell_object(TP, "No object with the name "+type+" found in the "+
				"area "+area+ ".  Please try again.");
				return 1;
			}
			if(living(ob)) ob->move(ETP);
			else
			{
				if(ob->move(TP) != MOVE_OK)
				{
					ob->move(ETP);
					tell_object(TP, ob->query("short") + " has been spawned on the ground!");
				}
			}
			tell_object(TP, "You create a "+ob->query("short")+"!");
			return 1;
		}
		//END OF CLONING CODE - Saide
		else
		{
			if((objects_list = compile_objects_list(area, type, 0)) == -1)
			{
				tell_object(TP, "No area with the name "+area+" found.  Try again.");
				return 1;
			}
			if(objects_list == -2)
			{
				tell_object(TP, "Cannot display avatar objects because of "+
				"the massive amount - use avclone avsearch <search_term> and then "+
				"avclone avatars <item_name> to clone the item.");
				return 1;
			}
			if(objects_list == -3)
			{
				tell_object(TP, "something is whacky!");
				return 1;
			}
			if(objects_list == -4)
			{
				tell_object(TP, "invalid type declared");
				return 1;
			}
			if(!sizeof(keys(objects_list)))
			{
				tell_object(TP, "No objects of type "+type+" found in the area "+
				area+".  Please try again.");
				return 1;
			}
			tmps += create_display_list(objects_list, 0);
			TP->more(explode(tmps,"\n"));
			return 1;
		}
	}
	else
	{
		str = lower_case(str);
		if((objects_list = compile_objects_list(str, "All", 0)) == -1)
		{
			tell_object(TP, "No area with the name "+str+" found.  Try again.");
			return 1;
		}
		if(objects_list == -2)
		{
			tell_object(TP, "Cannot display avatar objects because of "+
			"the massive amount - use avclone avsearch <search_term> and then "+
			"avclone avatars <item_name> to clone the item.");
			return 1;
		}
		if(!sizeof(keys(objects_list)))
		{
			tell_object(TP, "No objects found for the area "+str+".  Please try again.");
			return 1;
		}
		tmps += create_display_list(objects_list, 0);
		TP->more(explode(tmps,"\n"));
		return 1;
	}
}




int help()
{
    write("%^BOLD%^%^CYAN%^Syntax%^RESET%^:"+
	    "\tavclone\n"+
	    "\tavclone <%^BOLD%^%^WHITE%^area_name%^RESET%^>\n"+
	    "\tavclone <%^BOLD%^%^WHITE%^area_name%^RESET%^> <%^BOLD%^%^WHITE%^item_type"+
	    "%^RESET%^>\n"+
	    "\tavclone <%^BOLD%^%^WHITE%^area_name%^RESET%^> "+
	    "<%^BOLD%^%^WHITE%^item_to_clone%^RESET%^>\n"+
	    "\tavclone <%^BOLD%^%^WHITE%^search%^RESET%^> "+
	    "<%^BOLD%^%^WHITE%^search term%^RESET%^>\n"+
	    "\tavclone <%^BOLD%^%^WHITE%^register> "+
		"<%^BOLD%^%^WHITE%^target%^RESET%^>\n\n\n"+
	    "The avclone command is a advanced clone command for avatars to use for either "+
	    "replacing equipment or cloning equipment for a persona to use.\n\n"+

	    "avclone by itself will show the areas currently supported by the command.\n\n"+
	    "avclone <area_name> will list all the available items from the specified "+
	    "<area_name>.  <area_name> must be an area that is currently supported. \n\n"+
	    "avclone <area_name> <item_type> will list all available items of the "+
	    "<item_type> specified.  Valid <item_type>'s are armor, weapon, monster, and other. \n\n"+
	    "avclone <area_name> <item_to_clone> will clone the specied <item_to_clone> " +
	    "from the specified <area_name>.  Please note that you may use "+
	    "either of the two Clone Words provided from the list.\n\n"+
	    "Finally, avclone <search> <search term> will search through the "+
	    "supported areas to find items that match your search - you can "+
	    "then clone them by using the provided Area and one of the two clone words.\n\n"+
	    "There is no need to do avclone avsearch anymore, by default your search "+
		"will include avatar directories. \n\n"+
		"avclone <register> <target> will let you attempt to register the "+
		"target specified either in your inventory or in the room to "+
		"work with avclone in the future.");
	return 1;
}
