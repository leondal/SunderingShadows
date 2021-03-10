// Command to allow avatars to create rooms for plots and such.  
// They are restricted to creating rooms in /d/av_rooms/<their name>/

#include <std.h>
#include <security.h>

inherit OBJECT;

#define PATH "/d/av_rooms/"
#define OP "/daemon/persistent_room_d.c"
//////////////////////////////////////////

void main_menu(object obj);
void selection(string str,object obj,string menu);
void confirm_save(string str,object obj,string file);
void save_room(object obj);
void confirm_delete(string str,object obj, string file);
void delete_room(string str,object obj);
void preview_room(object obj);
void edit_existing(string str,object obj);
void set_searches(string str,object obj,mapping map);
void set_exits(string str,object obj,mapping map);
void set_items(string str,object obj,mapping map);
void save_door(object obj);
void save_lock(object obj);
void confirm_delete_all_doors(string str,object obj);
void confirm_delete_one_door(string str,object obj,string door);
void door_display(object obj);
void confirm_edit_door(string str,object obj,string door);
void door_creator(string str,object obj);
int door_check(object obj);
int lock_check(object obj);
void confirm_delete_all_locks(string str,object obj,string door);
void confirm_delete_one_lock(string str,object obj,string door,string lock);
void confirm_edit_lock(string str,object obj,string lock);
void lock_creator(string str,object obj);
void add_door_data(string str,object obj,string type);
void add_lock_data(string str,object obj,string type);
void select_lock_entry(string str,object obj);
void select_door_entry(string str,object obj);
void create_or_edit_lock(object obj);
void create_or_edit_door(object obj);
void door_selection(string str,object obj);
void door_editor(object obj);
void map_data_entry(object obj,string type);
void string_data_entry(string str,object obj,string type);
void editor(object obj);
void exit_origin(string str,object obj);
void exit_destination(string str,object obj,string room,string direction);
void exit_direction(string str,object obj,string room);
void add_room_exit(string str,object obj);
void move_rooms(string str,object obj);
void set_path(object obj);
void display_rooms(object obj);
int help(string str);
void quit(object obj);
int path_check(object obj,string path);
void begin(object obj);

////////////////////////////////////////

mapping SEARCHES=([]),EXITS=([]),ITEMS=([]),DOORS=([]);
string DIR,WORKING_DOOR,WORKING_LOCK;
int	EDITING;
object PRD;


void main_menu(object obj)
{
	if(!objectp(obj)) { return; }
	tell_object(obj,"     %^MAGENTA%^Welcome to the avatar room generator!%^RESET%^");
	tell_object(obj,"%^RESET%^%^BOLD%^Please select one of the following options:\n%^RESET%^"
		"  %^MAGENTA%^1%^RESET%^> %^BOLD%^Display your existing rooms.\n%^RESET%^"
		"  %^MAGENTA%^2%^RESET%^> %^BOLD%^Go to an existing room.\n%^RESET%^"
		"  %^MAGENTA%^3%^RESET%^> %^BOLD%^Create a new room.\n%^RESET%^"
		"  %^MAGENTA%^4%^RESET%^> %^BOLD%^Edit one of your existing rooms.\n%^RESET%^"
		"  %^MAGENTA%^5%^RESET%^> %^BOLD%^Add an exit from a mud room to one of your rooms.\n%^RESET%^"
		"  %^MAGENTA%^6%^RESET%^> %^BOLD%^Delete one of your existing rooms.\n%^RESET%^"
		"  %^MAGENTA%^7%^RESET%^> %^BOLD%^Exit from the avatar room generator.\n\n%^RESET%^");
	input_to("selection",obj,"main_menu");
	return;
}

void selection(string str,object obj,string menu)
{
	mapping info=([]);
	string *arr=({});
	int i;


	if(!objectp(obj)) { return; }
	
	if(!stringp(str)) 
	{ 
		main_menu(obj);
		return;
	}
	
	switch(menu)
	{
	case "main_menu":

		switch(str)
		{
		case "1":
			display_rooms(obj);
			return;

		case "2":
			tell_object(obj,"    %^RESET%^%^BOLD%^Please type the full path of the room that you wish "
				"to move to, including the %^RESET%^%^YELLOW%^.c%^RESET%^%^BOLD%^ at the end.%^RESET%^");
			input_to("move_rooms",obj);
			return;

		case "3":
			editor(obj);
			return;

		case "4":// edit existing

			tell_object(obj,"    %^RESET%^%^BOLD%^Which room would you like to edit?  Please enter the full path of "
				"the file, including the %^RESET%^%^YELLOW%^.c%^%^RESET%^%^BOLD%^ on the end.%^RESET%^");
			input_to("edit_existing",obj);
			return;

		case "5":
			tell_object(obj,"    %^RESET%^%^BOLD%^You can add an exit from the standard mud rooms to one "
				"of your own rooms or any other mud room in two different ways.  Please choose your "
				"preferred method.\n%^RESET%^"
				"  %^MAGENTA%^1%^RESET%^> %^RESET%^%^BOLD%^Add a new exit from your current room.\n%^RESET%^"
				"  %^MAGENTA%^2%^RESET%^> %^RESET%^%^BOLD%^Type in the full path of the room which you want to add the exit from.\n%^RESET%^"
				"  %^MAGENTA%^3%^RESET%^> %^RESET%^%^BOLD%^Return to Main Menu.\n%^RESET%^"
				"  %^MAGENTA%^4%^RESET%^> %^RESET%^%^BOLD%^Quit avatar room generator.\n%^RESET%^"
				"%^RESET%^%^YELLOW%^NOTE: Exits from the mud to your rooms are not permenant, and as such "
				"will need to be added again after a reboot, or a room clean_up%^RESET%^");
			input_to("add_room_exit",obj);
			return;

		case "6":
			tell_object(obj,"    %^RESET%^%^BOLD%^Enter the full file name of the room that you would like "
				"to delete.  You must include the %^RESET%^%^YELLOW%^.c%^RESET%^%^BOLD%^ on the end of the "
				"file name and you can only delete rooms that you have previously created with this "
				"editor.%^RESET%^");
			input_to("delete_room",obj);
			return;

		case "7":
		case "exit":
		case "quit":
		case "q":
			quit(obj);
			return;

		default:
			main_menu(obj);
			return;
		}
		return;

	case "display_rooms":

		switch(str)
		{
		case "1":
			main_menu(obj);
			return;
		case "2":
			quit(obj);
			return;
		default:
			main_menu(obj);
			return;
		}		
		return;
	
	case "move_rooms_fail":

		switch(str)
		{
		case "1":
			tell_object(obj,"    %^RESET%^%^BOLD%^Please type the full path of the room that you wish "
				"to move to, including the %^RESET%^%^YELLOW%^.c%^RESET%^%^BOLD%^ at the end.%^RESET%^");
			input_to("move_rooms",obj);
			return;
		case "2":
			main_menu(obj);
			return;
		case "3":
			quit(obj);
			return;
		default:
			main_menu(obj);
			return;

		}
		return;

	case "move_rooms_pass":

		switch(str)
		{
		case "1":
			main_menu(obj);
			return;
		case "2":
			quit(obj);
			return;
		default:
			main_menu(obj);
			return;
		}
		return;

	case "editor":
		
		switch(str)
		{
		case "1"://name
			tell_object(obj,"    %^RESET%^%^BOLD%^Please enter the file name for your room.  This "
				"name should contain no punctuation and no spaces.  Underscores are allowed.  "
				"%^RESET%^%^RED%^DO NOT%^RESET%^%^BOLD%^ put the %^RESET%^%^YELLOW%^.c%^RESET%^%^BOLD%^ "
				"onto the end of the file name, the editor will do that for you.  You may enter "
				"%^RESET%^<%^MAGENTA%^q%^RESET%^> %^BOLD%^or %^RESET%^<%^MAGENTA%^quit%^RESET%^> %^BOLD%^"
				"to return to the main menu.%^RESET%^");
			input_to("string_data_entry",obj,"name");
			return;

		case "2"://indoors

			tell_object(obj,"  %^RESET%^%^BOLD%^Enter 1 for an indoor room, or 0 for an outdoor room.%^RESET%^");
			input_to("string_data_entry",obj,"indoors");
			return;

		case "3"://light

			tell_object(obj,"    %^RESET%^%^BOLD%^Enter the light level for the room.  -1 is dark for humans "
				"and 5 is very bright.  Keep in mind that outdoor rooms have adjustments to "
				"their light levels during the night time hours so they may not need to begin "
				"very dark.%^RESET%^");
			input_to("string_data_entry",obj,"light");
			return;

		case "4"://terrain type

			tell_object(obj,"    %^RESET%^%^BOLD%^Enter the terrain type for this room.  The terrain type effects "
				"things like hunting and foraging, and will eventually determine factors for the "
				"global search daemon that will one day be put in.  (No, seriously :P).  Valid "
				"terrain types are: "+implode(PRD->query_terrains(),", ")+"\n%^RESET%^");
			input_to("string_data_entry",obj,"terrain_type");
			return;

		case "5"://travel type

			info = PRD->query_travel_types();
			arr = keys(info);

			tell_object(obj,"    %^RESET%^BOLD%^Enter the travel type that you would like for this room.  The travel "
				"type will effect the stamina drain in this room.  The number following the "
				"travel type is the percentage that the player will loose stamina when they "
				"leave the room.  The list of travel types are as follows:%^RESET%^");

			for(i=0;i<sizeof(arr);i++)
			{
				tell_object(obj,"\t%^RESET%^%^BOLD%^"+arr[i]+":  %^RESET%^%^MAGENTA%^"+info[arr[i]]+"%^RESET%^");
			}

			input_to("string_data_entry",obj,"travel_type");
			return;

		case "6"://climate

			tell_object(obj,"    %^RESET%^%^BOLD%^Enter the climate for this room.  This will determine "
				"the average temprature and the weather for the room.  Valid choices "
				"are :"+implode(PRD->query_climates(),", ")+"\n%^RESET%^");
			input_to("string_data_entry",obj,"climate");
			return;

		case "7"://short desc

			tell_object(obj,"    %^RESET%^%^BOLD%^Enter the short description for this room.%^RESET%^");
			input_to("string_data_entry",obj,"short_desc");
			return;

		case "8"://long desc

			tell_object(obj,"    %^RESET%^%^YELLOW%^To prevent errors with long descriptions overflowing, "
				"the long desc gets broken up into lines that are 200 characters long.  In normal writing "
				"this poses no problems and it will not even be noticed in the final room description.  However, "
				"if you happen to have a color code at the line break it could possibly not work properly.  "
				"You won't be able to see for sure until you have saved the file and go to the room.  If it "
				"happens, you can try rewording a little, or moving your color code to fix the problem.\n%^RESET%^");
			tell_object(obj,"    %^RESET%^%^YELLOW%^Enter the long description for this room.%^RESET%^");
			input_to("string_data_entry",obj,"long_desc");
			return;

		case "9"://smell

			tell_object(obj,"    %^RESET%^%^BOLD%^Enter the scent that players smell in this room.%^RESET%^");
			input_to("string_data_entry",obj,"smell");
			return;

		case "10"://listen

			tell_object(obj,"    %^RESET%^%^BOLD%^Enter the listen for this room.%^RESET%^");
			input_to("string_data_entry",obj,"listen");
			return;

		case "11"://search

			map_data_entry(obj,"search");
			return;

		case "12"://items

			map_data_entry(obj,"items");
			return;

		case "13"://exits

			map_data_entry(obj,"exits");
			return;

		case "14"://doors

			map_data_entry(obj,"doors");
			return;

		case "15"://preview

			preview_room(obj);
			return;

		case "16"://save

			save_room(obj);
			return;

		case "17":
			main_menu(obj);
			return;

		case "18":
			quit(obj);
			return;

		default:
			main_menu(obj);
			return;
		}

	default:
		main_menu(obj);
		return;
	}
	return;
}

void confirm_save(string str,object obj,string file)
{
	string name;
	object *living=({}),room;	
	int i;

	if(!objectp(obj)) { return; }
	switch(str)
	{
	case "yes":
	case "Yes":
	case "y":
	case "Y":

		name = PRD->query_room_data("name");
		if(!stringp(name) || name == "" || name == " ")
		{
			tell_object(obj,"%^RESET%^%^YELLOW%^File name invalid, please set your >>Name<< again.");
			editor(obj);
			return;
		}
		PRD->set_file(name);
		tell_object(obj,"%^RESET%^%^YELLOW%^Confirmed, writing file "+file+"%^RESET%^");

		room = find_object(file);
		if(objectp(room))
		{
			living = all_living(room);
			if(sizeof(living))
			{
				if(sizeof(living))
				{
					for(i=0;i<sizeof(living);i++)
					{
						if(!objectp(living[i])) { continue; }
						living[i]->move("/d/shadowgate/void");
					}
				}
			}

			rm(file);
			if(objectp(room)) { room->remove(); }
			if(objectp(room)) { destruct(room); }
			PRD->SAVE();

			if(sizeof(living))
			{
				for(i=0;i<sizeof(living);i++)
				{
					if(!objectp(living[i])) { continue; }
					living[i]->move(file);
				}
			}
		}
		else
		{
			if(EDITING && file_exists(file))
			{
				if(objectp(room))
				{
					living = all_living(room);
					if(sizeof(living))
					{
						for(i=0;i<sizeof(living);i++)
						{
							if(!objectp(living[i])) { continue; }
							living[i]->move("/d/shadowgate/void");
						}
					}
					rm(file);
					if(objectp(room)) { room->remove(); }
					if(objectp(room)) { destruct(room); }
					PRD->SAVE();

					if(sizeof(living))
					{
						for(i=0;i<sizeof(living);i++)
						{
							if(!objectp(living[i])) { continue; }
							living[i]->move(file);
						}
					}
				}
				rm(file);
				PRD->SAVE();
				main_menu(obj);
				return;
			}
			if(file_exists(file)) { rm(file); }
			PRD->SAVE();
		}

		main_menu(obj);
		return;
	default:
		tell_object(obj,"%^RESET%^%^YELLOW%^Aborting..  returning to main menu.%^RESET%^");
		main_menu(obj);
		return;
	}
	return;
}

void save_room(object obj)
{
	mapping info =([]);
	string file;
	if(!objectp(obj)) { return; }
	if(!PRD->query_complete())
	{
		tell_object(obj,"    %^RESET%^%^YELLOW%^You have not yet entered all of the information needed to save "
			"this room.  The following items need to be entered before you are allowed "
			"to save: "+implode(PRD->stage_check(),", ")+".\n%^RESET%^");
		main_menu(obj);
		return;
	}
	info = PRD->query_room_info();
	file = ""+DIR+""+info["name"]+".c";
	if(file_exists(file) && !EDITING)
	{
		tell_object(obj,"    %^RESET%^%^YELLOW%^This file already exists.  If you meant to edit this file instead, "
			"use the edit an existing room feature instead.\n%^RESET%^");
		main_menu(obj);
		return;
	}
	if(!get_dir(DIR)) 
	{ 
		mkdir(DIR); 
		tell_object(obj,"%^RESET%^%^YELLOW%^Creating directory "+DIR+"%^RESET%^");
	}
	tell_object(obj,"%^RESET%^%^BOLD%^Do you really want to save this room?\n%^RESET%^");
	input_to("confirm_save",obj,file);
	return;
}

void confirm_delete(string str,object obj, string file)
{
	object room;
	if(!objectp(obj)) { return; }
	switch(str)
	{
	case "yes":
	case "Yes":
	case "y":
	case "Y":
		tell_object(obj,"%^RESET%^%^YELLOW%^Confirmed, deleting "+file+"...%^RESET%^");
		PRD->delete_room_from_map(file);
		room = find_object(file);
		rm(file);
		if(objectp(room)) { room->remove(); }
		if(objectp(room)) { destruct(room); }
		tell_object(obj,"%^RESET%^%^YELLOW%^Finished, returning to main menu.%^RESET%^");
		main_menu(obj);
		return;
	default:
		tell_object(obj,"%^RESET%^%^YELLOW%^Aborting..  returning to main menu.%^RESET%^");
		main_menu(obj);
		return;
	}
	return;
}

void delete_room(string str,object obj)
{
	if(!objectp(obj)) { return; }
	if(!path_check(obj,str)) 
	{
		tell_object(obj,"    %^RESET%^%^YELLOW%^You have tried to remove a file from an invalid "
			"path.  Please check your spelling and try again.%^RESET%^");
		main_menu(obj);
		return;
	}
	if(!file_exists(str))
	{
		tell_object(obj,"    %^RESET%^%^YELLOW%^The file "+str+" does not exist, please check "
			"your spelling and try again.%^RESET%^");
		main_menu(obj);
		return;
	}
	tell_object(obj,"    %^RESET%^%^BOLD%^Are you sure you would like to delete the file "+str+"?\n%^RESET%^");
	input_to("confirm_delete",obj,str);
	return;
}

void do_pause(string str,object obj)
{
	if(!objectp(obj)) { return; }
	editor(obj);
	return;
}

void preview_room(object obj)
{
	int i;
	mapping info=([]),tmp=([]);
	string *arr=({});

	info = PRD->query_room_info();

	tell_object(obj,"%^RESET%^%^YELLOW%^Displaying current working room..\n\n%^RESET%^");

	tell_object(obj,"File name: "+info["name"]+"");
	tell_object(obj,""+info["short_desc"]+"");
	tell_object(obj,""+info["long_desc"]+"\n");
	tell_object(obj,"Smell: "+info["smell"]+"");
	tell_object(obj,"Sound: "+info["listen"]+"\n");
	tell_object(obj,"Indoors: "+info["indoors"]+"");
	tell_object(obj,"Terrain: "+info["terrain_type"]+"");
	tell_object(obj,"Travel: "+info["travel_type"]+"");
	tell_object(obj,"Climate: "+info["climate"]+"");

	if(mapp(info["searches"]))
	{
		arr = keys(info["searches"]);
		if(sizeof(arr))
		{
			tell_object(obj,"Searches:");
			for(i=0;i<sizeof(arr);i++)
			{
				tell_object(obj,"    "+arr[i]+" : "+info["searches"][arr[i]]+"");
			}
		}
	}

	if(mapp(info["items"]))
	{
		arr = keys(info["items"]);
		{
			if(sizeof(arr))
			{
				tell_object(obj,"Items:");
				for(i=0;i<sizeof(arr);i++)
				{
					if(pointerp(arr[i]))
					{
						tell_object(obj,""+identify(arr[i])+" : "+info["items"][arr[i]]+"");
					}
					else
					{
						tell_object(obj,""+arr[i]+" : "+info["items"][arr[i]]+"");
					}
				}
			}
		}
	}

	tell_object(obj,"%^RESET%^%^YELLOW%^Press any key to continue...");
	input_to("do_pause",obj);
	return;
}

void edit_existing(string str,object obj)
{
	mapping info=([]);
	string tmp;
	if(!objectp(obj)) { return; }
	if(!file_exists(str))
	{
		tell_object(obj,"  %^RESET%^%^YELLOW%^The file that you choose to edit, "+str+" does not exist.  "
			"Returning to main menu.%^RESET%^");
		main_menu(obj);
		return;
	}
	if(!path_check(obj,str))
	{
		tell_object(obj,"    %^RESET%^%^YELLOW%^The file "+str+" is not in your directory.  Returning to the "
			"main menu.%^RESET%^");
		main_menu(obj);
		return;
	}
	tell_object(obj,"%^RESET%^%^YELLOW%^Confirmed, loading file "+str+" for editing..%^RESET%^");
	
	PRD->clean_room_info();
	info = PRD->retrieve_room_info(str);
	SEARCHES=([]);EXITS=([]);ITEMS=([]);DOORS=([]);
	
	PRD->set_room_info(info);

	tmp = str;
	tmp = replace_string(tmp,DIR,"");
	tmp = replace_string(tmp,".c","");
	PRD->set_room_name(tmp);
	PRD->set_path(tmp);

	SEARCHES = info["search"];
	EXITS = info["exits"];
	ITEMS = info["items"];
	DOORS = info["doors"];
	PRD->fill_stages();
	PRD->set_doors(DOORS);
	
	EDITING = 1;	
	tell_object(obj,"%^RESET%^%^YELLOW%^File loaded, entering the editor.%^RESET%^");
	editor(obj);
	return;
}

void set_searches(string str,object obj,mapping map)
{
	string search,message,*temp=({});
	int num,i;

	if(!objectp(obj)) { return; }
	switch(str)
	{
	case "":
	case "**":
		tell_object(obj,"%^RESET%^%^BOLD%^Confirmed, no searches for this room.  Returning to editor.\n%^RESET%^");
		PRD->set_room_searches(([]));
		editor(obj);
		return;

	case "delete":
		tell_object(obj,"%^RESET%^%^BOLD%^Confirmed, clearing searches.%^RESET%^");
		SEARCHES = ([]);
		map_data_entry(obj,"search");
		return;

	case "done":
	case "finished":
		tell_object(obj,"%^RESET%^%^BOLD%^Confirmed, saves for this room are as follows:\n");
		temp = keys(SEARCHES);
		if(sizeof(temp))
		{
			for(i=0;i<sizeof(temp);i++)
			{
				tell_object(obj,""+temp[i]+" : "+SEARCHES[temp[i]]+"");
			}
		}
		PRD->set_room_searches(SEARCHES);
		editor(obj);
		return;

	default:		
		if(strsrch(str,"*") == -1)
		{
			tell_object(obj,"%^RESET%^%^YELLOW%^You must enter your search in the format: "
				"search*message recieved%^RESET%^");
			map_data_entry(obj,"search");
			return;
		}
		else
		{
			num = strsrch(str,"*");
			search = str[0..(num-1)];
			message = str[(num+1)..(strlen(str))];
			if(mapp(map))
			{
				map += ([ search : message, ]);
			}
			SEARCHES = map;
			tell_object(obj,""+search+" : "+message+" %^RESET%^%^BOLD%^added as a search for this room.\n"
				"enter %^RESET%^<%^MAGENTA%^done%^RESET%^>%^BOLD%^ or %^RESET%^<%^MAGENTA%^finished"
				"%^RESET%^> %^BOLD%^if you are finished adding searches, or type another search to "
				"add more.  Remember to use the format: search*message recieved.\n%^RESET%^");
			input_to("set_searches",obj,map);
			return;
		}
	}
	return;
}

void set_exits(string str,object obj,mapping map)
{
	string direction,destination,*temp=({});
	int num,i;

	if(!objectp(obj)) { return; }
	switch(str)
	{
	case "":
	case "**":
		tell_object(obj,"%^RESET%^%^BOLD%^Confirmed, no exits for this room.  Returning to editor.\n%^RESET%^");
		PRD->set_room_exits(([]));
		editor(obj);
		return;

	case "delete":
		tell_object(obj,"%^RESET%^%^BOLD%^Confirmed, clearing exits.%^RESET%^");
		EXITS = ([]);
		PRD->set_room_exits(([]));
		PRD->delete_all_hidden();
		map_data_entry(obj,"exits");
		return;

	case "done":
	case "finished":
		tell_object(obj,"%^RESET%^%^BOLD%^Confirmed, exits for this room are as follows:\n");
		temp = keys(EXITS);
		if(sizeof(temp))
		{
			for(i=0;i<sizeof(temp);i++)
			{
				tell_object(obj,""+temp[i]+" : "+EXITS[temp[i]]+"");
			}
		}
		PRD->set_room_exits(EXITS);
		editor(obj);
		return;

	default:		
		if(strsrch(str," ") == -1)
		{
			tell_object(obj,"%^RESET%^%^YELLOW%^You must enter your exit in the format: exit "
				"/destination/room%^RESET%^");
			map_data_entry(obj,"exits");
			return;
		}
		else
		{
			//num = strsrch(str," ");
			//direction = str[0..(num-1)];
			//destination = str[(num+1)..(strlen(str))];
			
			temp = explode(str," ");
			if(sizeof(temp) < 2)
			{
				tell_object(obj,"%^RESET%^%^BOLD%^Please use the format exit /destination/room.c or "
					"exit hidden /destination/room.c");
				input_to("set_exits",obj,map);
				return;
			}
			direction = temp[0];
			if(temp[1] != "hidden") { destination = temp[1]; }
			if(!destination)
			{
				if(sizeof(temp) != 3)
				{
					tell_object(obj,"%^RESET%^%^BOLD%^Please use the format exit /destination/room.c or "
						"exit hidden /destination/room.c");
					input_to("set_exits",obj,map);
					return;
				}
				if(temp[1] == "hidden")
				{
					PRD->add_hidden_exit(direction);
				}
				destination = temp[2];
			}			

			destination = replace_string(destination,".c","");
			if(mapp(map))
			{
				map += ([ direction : destination, ]);
			}			
			EXITS = map;
			tell_object(obj,""+direction+" : "+destination+" %^RESET%^%^BOLD%^added as an exit for this room.\n"
				"enter %^RESET%^<%^MAGENTA%^done%^RESET%^>%^BOLD%^ or %^RESET%^<%^MAGENTA%^finished%^RESET%^>"
				"%^BOLD%^if you are finished adding exits, or type another exit to add more.  Remember to use "
				"the format: direction /destination/room or direction hidden /destination/room  if you would "
				"like for the exit to be invisible to the player.\n%^RESET%^");
			input_to("set_exits",obj,map);
			return;
		}
	}
	return;
}

void set_items(string str,object obj,mapping map)
{
	mixed *temp=({});
	string item,description,*items=({});
	int num,i;

	if(!objectp(obj)) { return; }
	switch(str)
	{
	case "":
	case "**":
		tell_object(obj,"%^RESET%^%^BOLD%^Confirmed, no items for this room.  Returning to editor.\n%^RESET%^");
		PRD->set_room_items(([]));
		editor(obj);
		return;

	case "delete":
		tell_object(obj,"%^RESET%^%^BOLD%^Confirmed, clearing items.%^RESET%^");
		ITEMS = ([]);
		map_data_entry(obj,"items");
		return;

	case "done":
	case "finished":
		tell_object(obj,"%^RESET%^%^BOLD%^Confirmed, items for this room are as follows:\n");
		temp = keys(SEARCHES);
		if(sizeof(temp))
		{
			for(i=0;i<sizeof(temp);i++)
			{
				if(pointerp(temp[i]))
				{
					tell_object(obj,""+identify(temp[i])+" : "+ITEMS[temp[i]]+"");
				}
				else
				{
					tell_object(obj,""+temp[i]+" : "+ITEMS[temp[i]]+"");
				}
			}
		}
		PRD->set_room_items(ITEMS);
		editor(obj);
		return;

	default:		
		if(strsrch(str,"*") == -1)
		{
			tell_object(obj,"%^RESET%^%^YELLOW%^You must enter your item in the format: "
				"item*description of item, or item,item2,item3*description of item%^RESET%^");
			map_data_entry(obj,"items");
			return;
		}

		else
		{
			num = strsrch(str,"*");
			item = str[0..(num-1)];
			description = str[(num+1)..(strlen(str))];

			if(strsrch(item,",") != -1)
			{
				items = explode(item,",");
				if(mapp(map))
				{
					map += ([ items : description ]);
				}
				tell_object(obj,""+identify(items)+" : "+description+" %^RESET%^%^BOLD%^added as an "
					"item for this room.\n"
					"enter %^RESET%^<%^MAGENTA%^done%^RESET%^>%^BOLD%^ or %^RESET%^<%^MAGENTA%^finished "
					"%^RESET%^>%^BOLD%^ if you are finished adding items, or type another item to add more.");
				ITEMS = map;
				input_to("set_items",obj,map);
				return;
			}
			else
			{
				if(mapp(map))
				{
					map += ([ item : description, ]);
				}
				ITEMS = map;
				tell_object(obj,""+item+" : "+description+" %^RESET%^%^bold%^added as an item for this room.\n"
					"enter %^RESET%^<%^MAGENTA%^done%^RESET%^>%^BOLD%^ or %^RESET%^<%^MAGENTA%^finished"
					"%^RESET%^> %^BOLD%^if you are finished adding items, or type another item to add more.");
				input_to("set_items",obj,map);
				return;
			}
		}
	}
	return;
}

void save_door(object obj)
{
	string *incomplete=({});
	int num;

	if(!objectp(obj)) { return; }
	num = PRD->complete_door(WORKING_DOOR);
	if(!num)
	{
		incomplete = (string *)PRD->query_door_stages() - (string *)PRD->query_completed_door_stages();
		tell_object(obj,"%^RESET%^%^YELLOW%^Your door is not yet completed, you have "
			"the following stages left to finish: "+implode(incomplete,", ")+"");
		create_or_edit_door(obj);
		return;
	}
	tell_object(obj,"%^RESET%^%^BOLD%^Confirmed, saving door "+WORKING_DOOR+".%^RESET%^");
	tell_object(obj,"%^RESET%^%^BOLD%^Returning to editor...%^RESET%^");

	PRD->clear_current_door(WORKING_DOOR);
	WORKING_DOOR = "";
	door_editor(obj);
	return;
}

void save_lock(object obj)
{
	string *incomplete=({});
	int num;

	if(!objectp(obj)) { return; }
	num = PRD->complete_lock(WORKING_DOOR,WORKING_LOCK);
	if(!num)
	{
		incomplete = (string *)PRD->query_lock_stages() - (string *)PRD->query_completed_lock_stages();
		tell_object(obj,"%^RESET%^%^YELLOW%^Your lock is not yet completed, you have "
			"the following stages left to finish: "+implode(incomplete,", ")+"");
		create_or_edit_lock(obj);
		return;
	}
	tell_object(obj,"%^RESET%^%^BOLD%^Confirmed, saving lock "+WORKING_LOCK+".%^RESET%^");
	tell_object(obj,"%^RESET%^%^BOLD%^Returning to editor...%^RESET%^");
	tell_object(obj,"%^RESET%^%^YELLOW%^You must go through the editor again to add another lock "
		"to your door, or return to the door menu to save the door.%^RESET%^");
	PRD->clear_current_lock(WORKING_LOCK);
	WORKING_LOCK = "";
	create_or_edit_lock(obj);
	return;
}

void confirm_delete_all_doors(string str,object obj)
{
	if(!objectp(obj)) { return; }
	switch(str)
	{
	case "yes":
	case "Yes":
	case "y":
	case "Y":

		tell_object(obj,"%^RESET%^%^YELLOW%^Confirmed, deleting all doors for this room...%^RESET%^\n");
		WORKING_DOOR = "";
		PRD->clear_all_doors();
		tell_object(obj,"%^RESET%^%^YELLOW%^Finished, returning to door editor.");
		door_editor(obj);
		return;

	default:

		tell_object(obj,"%^RESET%^%^YELLOW%^Aborting...\n%^RESET%^");
		door_editor(obj);
		return;
	}
	return;
}

void confirm_delete_one_door(string str,object obj,string door)
{
	string *doors=({});
	if(!objectp(obj)) { return; }
	
	if(stringp(door) && door != "")
	{
		switch(str)
		{
		case "Yes":
		case "yes":
		case "Y":
		case "y":		
			
			tell_object(obj,"%^RESET%^%^YELLOW%^Confirmed, deleting door "+door+"..");
			PRD->delete_door(door);
			tell_object(obj,"%^RESET%^%^YELLOW%^Finishing, returning to door menu.%^RESET%^\n");
			door_editor(obj);
			return;

		default:

			tell_object(obj,"%^RESET%^%^YELLOW%^Aborting...%^RESET%^");
			door_editor(obj);
			return;
		}
	}
	if(!PRD->is_existing_door(door))
	{
		tell_object(obj,"%^RESET%^%^BOLD%^That is not listed as a door for this room.  Please "
			"check your spelling and capitilization and try again.  Returning to door editor.");
		door_editor(obj);
		return;
	}
	tell_object(obj,"%^RESET%^%^YELLOW%^Do you really want to delete the door "+str+"?  Enter "
		"yes to confirm, anything else to abort.");
	input_to("confirm_delete_one_door",obj,str);
	return;
}

void door_display(object obj)
{
	mapping door=([]),lock=([]),door_locks=([]),info=([]);
	string open_closed,locked,*doors=({}),*locks=({});
	int i,j,diff,is_locked;

	if(!objectp(obj)) { return; }
	
	info = PRD->query_doors();
	if(mapp(info)) { doors = keys(info); }
	if(!sizeof(doors))
	{
		tell_object(obj,"%^RESET%^%^BOLD%^Currently there are no doors for this room..%^RESET%^\n");
		door_editor(obj);
		return;
	}

	tell_object(obj,"%^RESET%^%^BOLD%^You have the following doors listed for this room:\n");
	for(i=0;i<sizeof(doors);i++)
	{
		door = info[doors[i]];
		door_locks = door["door_locks"];
		if(mapp(door_locks)) { locks = keys(door_locks); }

		if(door["door_closed"] == 1) { open_closed = "closed"; }
		else { open_closed = "open"; }
		if(door["door_locked"] == 1) { locked = "locked"; }
		else { is_locked = "unlocked"; }

		tell_object(obj,"Door: "+door["door_id"]+"");
		tell_object(obj,"    Direction:      "+door["door_direction"]+"");
		tell_object(obj,"    Destination:    "+door["door_destination"]+"");
		tell_object(obj,"    Open or Closed: "+open_closed+"");
		tell_object(obj,"    Door Locked:    "+is_locked+"");
		tell_object(obj,"    Door Key:       "+door["door_key"]+"");
		tell_object(obj,"    Description:    "+door["door_description"]+"");
		tell_object(obj,"    Open Message:   "+door["door_open_message"]+"");
		tell_object(obj,"    Close Message:  "+door["door_close_message"]+"");
		tell_object(obj,"    Knock Message:  "+door["door_knock_message"]+"\n");
		if(sizeof(locks))
		{
			for(j=0;j<sizeof(locks);j++)
			{
				lock = door_locks[locks[j]];
				diff = lock["lock_difficulty"];
				locked = lock["is_locked"];

				tell_object(obj,"        Lock: "+lock["lock_name"]+"");
				tell_object(obj,"            Lock Difficulty:  "+diff+"");
				tell_object(obj,"            Is Locked:        "+is_locked+"");
				tell_object(obj,"            Lock Key:         "+lock["lock_key"]+"");
				tell_object(obj,"            Lock Description: "+lock["lock_description"]+"\n");
			}
		}
		tell_object(obj,"\n\n");
	}
	door_editor(obj);
	return;
}

void confirm_edit_door(string str,object obj,string door)
{
	if(!objectp(obj)) { return; }
	switch(str)
	{
	case "Yes":
	case "yes":
	case "Y":
	case "y":

		tell_object(obj,"%^RESET%^%^BOLD%^Confirmed, editing "+door+".%^RESET%^\n");
		PRD->fill_door_stages();
		PRD->set_current_door(door);
		WORKING_DOOR = door;
		create_or_edit_door(obj);
		return;

	default:

		tell_object(obj,"%^RESET%^%^BOLD%^Aborting...%^RESET%^");
		door_editor(obj);
		return;
	}
	return;
}

void door_creator(string str,object obj)
{
	if(!objectp(obj)) { return; }

	if(!stringp(str) || str == "" || str == " ")
	{
		tell_object(obj,"%^RESET%^%^YELLOW%^You must enter the name of the door that you would "
			"like to create or edit.  Returning to door editor...%^RESET%^");
		door_editor(obj);
		return;
	}

	if(PRD->is_existing_door(str))
	{
		tell_object(obj,"%^RESET%^%^YELLOW%^You have entered a door named "+str+", this door already "
			"exists.  If you wish to edit the door, enter <yes>.%^RESET%^");
		input_to("confirm_edit_door",obj,str);
		return;
	}

	tell_object(obj,"%^RESET%^%^BOLD%^Creating a new door: "+str+".%^RESET%^");
	
	PRD->setup_new_door(str);
	WORKING_DOOR = str;
	PRD->set_door_data(str,"door_id",str);
	create_or_edit_door(obj);
	return;
}

int door_check(object obj)
{
	string *completed=({});
	completed = PRD->query_completed_door_stages();

	if(member_array("door_id",completed) == -1 || !WORKING_DOOR || WORKING_DOOR == "")
	{
		tell_object(obj,"%^RESET%^%^YELLOW%^You must enter the Door_id before you can "
			"enter any of the other information.%^RESET%^");
		create_or_edit_door(obj);
		return 0;
	}
	return 1;
}

int lock_check(object obj)
{
	string *completed = ({});
	completed = PRD->query_completed_lock_stages();
	if(!WORKING_DOOR || WORKING_DOOR == "")
	{
		tell_object(obj,"%^RESET%^%^YELLOW%^You must enter the Door_id before you can "
			"enter the Lock_name.%^RESET%^");
		create_or_edit_lock(obj);
		return 0;
	}
	if(member_array("lock_name",completed) == -1 || !WORKING_LOCK || WORKING_LOCK == "")
	{
		tell_object(obj,"%^RESET%^%^YELLOW%^You must enter the Lock_name before you "
			"can enter any of the other information.%^RESET%^");
		create_or_edit_lock(obj);
		return 0;
	}
	return 1;
}

void confirm_delete_all_locks(string str,object obj,string door)
{
	if(!objectp(obj)) { return; }
	if(stringp(door) && door != "")
	{
		switch(str)
		{
		case "yes":
		case "Yes":
		case "y":
		case "Y":

			tell_object(obj,"%^RESET%^%^YELLOW%^Confirmed, deleting all locks for the door "+door+"...%^RESET%^\n");
			WORKING_LOCK = "";
			PRD->clear_all_locks(door);
			tell_object(obj,"%^RESET%^%^YELLOW%^Finished, returning to door editor.");
			door_editor(obj);
			return;

		default:

			tell_object(obj,"%^RESET%^%^YELLOW%^Aborting...\n%^RESET%^");
			door_editor(obj);
			return;
		}
	}
	if(!PRD->is_existing_door(str))
	{
		tell_object(obj,"%^RESET%^%^BOLD%^The door "+str+" is not listed as a door for this room.  "
			"Please check your spelling and capitilization and try again.");
		door_editor(obj);
		return;
	}
	tell_object(obj,"%^RESET%^%^RED%^Are you sure you want to delete all the looks on the door "+str+"?  "
		"Enter <yes> to confirm, anything else to abort.%^RESET%^");
	input_to("confirm_delete_all_locks",obj,str);
	return;
}

void confirm_delete_one_lock(string str,object obj,string door,string lock)
{
	string *locks=({}),door_name,lock_name;
	int num;
	if(!objectp(obj)) { return; }
	
	if(stringp(lock) && lock != "")
	{
		switch(str)
		{
		case "Yes":
		case "yes":
		case "Y":
		case "y":		
			
			tell_object(obj,"%^RESET%^%^YELLOW%^Confirmed, deleting lock "+lock+"..");
			PRD->delete_lock(door,lock);
			tell_object(obj,"%^RESET%^%^YELLOW%^Finishing, returning to door menu.%^RESET%^\n");
			door_editor(obj);
			return;

		default:

			tell_object(obj,"%^RESET%^%^YELLOW%^Aborting...%^RESET%^");
			door_editor(obj);
			return;
		}
	}

	if(strsrch(str,"*") == -1)
	{
		tell_object(obj,"%^RESET%^%^BOLD%^You must use the syntax name_of_door*name_of_lock, returning "
			"to editor.%^RESET%^");
		door_editor(obj);
		return;
	}
	num = strsrch(str,"*");
	door_name = str[0..(num-1)];
	lock_name = str[(num+1)..strlen(str)];

	if(!PRD->is_existing_lock(door_name,lock))
	{
		tell_object(obj,"%^RESET%^%^BOLD%^"+lock_name+" is not listed as a lock for "+door_name+".  Please "
			"check your spelling and capitilization and try again.  Returning to door editor.");
		door_editor(obj);
		return;
	}

	tell_object(obj,"%^RESET%^%^YELLOW%^Do you really want to delete the lock "+lock_name+"?  Enter "
		"<yes> to confirm, anything else to abort.");
	input_to("confirm_delete_one_lock",obj,door_name,lock_name);
	return;
}

void confirm_edit_lock(string str,object obj,string lock)
{
	mapping door_map=([]),lock_map=([]);
	if(!objectp(obj)) { return; }
	switch(str)
	{
	case "Yes":
	case "yes":
	case "Y":
	case "y":

		tell_object(obj,"%^RESET%^%^BOLD%^Confirmed, editing "+lock+".%^RESET%^\n");
		PRD->fill_lock_stages();
		PRD->set_current_lock(lock);
		door_map = PRD->query_doors();
		lock_map = door_map[WORKING_DOOR]["door_locks"];
		PRD->setup_current_lock(lock_map);
		WORKING_LOCK = lock;
		create_or_edit_lock(obj);
		return;

	default:

		tell_object(obj,"%^RESET%^%^BOLD%^Aborting...%^RESET%^");
		create_or_edit_lock(obj);
		return;
	}
	return;
}

void lock_creator(string str,object obj)
{
	if(!objectp(obj)) { return; }

	if(!stringp(str) || str == "" || str == " ")
	{
		tell_object(obj,"%^RESET%^%^YELLOW%^You must enter the name of the lock that you would "
			"like to create or edit.  Returning to lock editor...%^RESET%^");
		create_or_edit_lock(obj);
		return;
	}

	if(PRD->is_existing_lock(WORKING_DOOR,str))
	{
		tell_object(obj,"%^RESET%^%^YELLOW%^You have entered a lock named "+str+", this lock already "
			"exists.  If you wish to edit the lock, enter <yes>.%^RESET%^");
		input_to("confirm_edit_lock",obj,str);
		return;
	}

	tell_object(obj,"%^RESET%^%^BOLD%^Creating a new lock: "+str+".%^RESET%^");
	
	PRD->setup_new_lock(WORKING_DOOR,str);
	WORKING_LOCK = str;
	PRD->set_lock_data(WORKING_DOOR,WORKING_LOCK,"lock_name",str);
	create_or_edit_lock(obj);
	return;
}

void add_door_data(string str,object obj,string type)
{
	int num;
	if(!objectp(obj)) { return; }
	if(!stringp(str) || str == "" || str == " ")
	{
		tell_object(obj,"%^RESET%^%^BOLDYou must make a selection from the list...%^RESET%^\n");
		door_editor(obj);
		return;
	}

	switch(type)
	{
	case "name":

		door_creator(str,obj);
		return;

	case "destination":

		if(!door_check(obj)) { return; }
		tell_object(obj,"%^RESET%^%^BOLD%^Confirmed, destination set to "+str+".%^RESET%^");
		PRD->set_door_data(WORKING_DOOR,"door_destination",str);
		create_or_edit_door(obj);
		return;

	case "direction":

		if(!door_check(obj)) { return; }
		tell_object(obj,"%^RESET%^%^BOLD%^Confirmed, direction set to "+str+".%^RESET%^");
		PRD->set_door_data(WORKING_DOOR,"door_direction",str);
		create_or_edit_door(obj);
		return;

	case "closed":

		if(!door_check(obj)) { return; }
		if(!intp(to_int(str))) 
		{
			tell_object(obj,"%^RESET%^%^YELLOW%^You must enter a 1 or a 0, returning to door editor.%^RESET%^");
			create_or_edit_door(obj);
			return;
		}
		num = to_int(str);
		if(!num)
		{
			tell_object(obj,"%^RESET%^%^BOLD%^Confirmed, setting the door to begin %^RESET%^%^YELLOW%^opened.%^RESET%^");
		}
		else
		{
			tell_object(obj,"%^RESET%^%^BOLD%^Confirmed, setting the door to begin %^RESET%^%^YELLOW%^closed.%^RESET%^");

		}
		PRD->set_door_data(WORKING_DOOR,"door_closed",str);
		create_or_edit_door(obj);
		return;

	case "open_message":

		if(!door_check(obj)) { return; }
		tell_object(obj,"%^RESET%^%^BOLD%^Confirmed, setting open message to:\n\t%^RESET%^"+str+"");
		PRD->set_door_data(WORKING_DOOR,"door_open_message",str);
		create_or_edit_door(obj);
		return;

	case "close_message":

		if(!door_check(obj)) { return; }
		tell_object(obj,"%^RESET%^%^BOLD%^Confirmed, setting close message to:\n\t%^RESET%^"+str+"");
		PRD->set_door_data(WORKING_DOOR,"door_close_message",str);
		create_or_edit_door(obj);
		return;

	case "description":

		if(!door_check(obj)) { return; }
		tell_object(obj,"%^RESET%^%^BOLD%^Confirmed, door description set to:\n\t%^RESET%^"+str+"");
		PRD->set_door_data(WORKING_DOOR,"door_description",str);
		create_or_edit_door(obj);
		return;

	case "knock":

		if(!door_check(obj)) { return; }
		tell_object(obj,"%^RESET%^%^BOLD%^Confirmed, knock message set to:\n\t%^RESET%^"+str+"");
		PRD->set_door_data(WORKING_DOOR,"door_knock_message",str);
		create_or_edit_door(obj);
		return;

	default:
		create_or_edit_door(obj);
		return;
	}
	return;
}

void add_lock_data(string str,object obj,string type)
{
	int num;

	if(!objectp(obj)) { return; }
	switch(type)
	{
	case "name":

		lock_creator(str,obj);
		return;

	case "key":

		if(!lock_check(obj)) { return; }
		tell_object(obj,"%^RESET%^%^BOLD%^Confirmed, setting the lock key for this lock to: "+str+".%^RESET%^");
		PRD->set_lock_data(WORKING_DOOR,WORKING_LOCK,"lock_key",str);
		create_or_edit_lock(obj);
		return;

	case "description":

		if(!lock_check(obj)) { return; }
		tell_object(obj,"%^RESET%^%^BOLD%^Confirmed, setting the description for this lock to: \n"+str+"%^RESET%^");
		PRD->set_lock_data(WORKING_DOOR,WORKING_LOCK,"lock_description",str);
		create_or_edit_lock(obj);
		return;

	case "difficulty":

		if(!lock_check(obj)) { return; }
		if(!intp(to_int(str))) 
		{
			tell_object(obj,"%^RESET%^%^YELLOW%^You must enter a number for the lock difficulty.%^RESET%^");
			create_or_edit_lock(obj);
			return;
		}
		num = to_int(str);
		num = (num * -1);
		PRD->set_lock_data(WORKING_DOOR,WORKING_LOCK,"lock_difficulty",""+num+"");
		create_or_edit_lock(obj);
		return;		

	case "locked":

		if(!lock_check(obj)) { return; }
		if(!intp(to_int(str)))
		{
			tell_object(obj,"%^RESET%^%^YELLOW%^You must enter a 1 for locked or a 0 for unlocked.%^RESET%^");
			create_or_edit_lock(obj);
			return;
		}
		PRD->set_lock_data(WORKING_DOOR,WORKING_LOCK,"is_locked",str);
		create_or_edit_lock(obj);
		return;
		
	default:
		create_or_edit_lock(obj);
		return;
	}
	return;
}

void set_working_door(string door,object obj)
{
	if(!objectp(obj)) { return; }
	if(!stringp(door) && door == "")
	{
		tell_object(obj,"You must enter the name of the door you wish to add a lock to.");
		create_or_edit_lock(obj);
		return;
	}
	if(!PRD->is_existing_door(door))
	{
		tell_object(obj,"That is not listed as one of the doors for this room, please "
			"check your spelling and try again.");
		create_or_edit_lock(obj);
		return;
	}
	tell_object(obj,"You are now adding a lock to %^YELLOW%^ "+door+"%^RESET%^.");
	WORKING_DOOR = door;
	PRD->set_current_door(door);
	PRD->fill_door_stages();
	create_or_edit_lock(obj);
	return;
}

void select_lock_entry(string str,object obj)
{
	if(!objectp(obj)) { return; }

	if(!WORKING_DOOR || WORKING_DOOR == "")
	{
		tell_object(obj,"%^RESET%^%^BOLD%^Please enter the name of the door that you would like "
			"to add this lock to.  It must match exactly the full name of the door in the room "
			"including any color codes that you might have originally given the door.%^RESET%^");
		input_to("set_working_door",obj);
		return;
	}

	switch(str)
	{
	case "1": // lock name

		tell_object(obj,"%^RESET%^%^BOLD%^Please enter the name of the lock.  This must be set before "
			"any of the other information about the lock can be set.  This will be the short description "
			"of the lock when the player looks at the door.%^RESET%^");
		input_to("add_lock_data",obj,"name");
		return;

	case "2": // lock key

		tell_object(obj,"%^RESET%^%^BOLD%^Please enter the name of the key for this lock.  If this is going "
			"to be a lock that has no key, then you can enter <none> or <no key>.  You can create the actual "
			"key for the lock using the item command.  The %^RESET%^<%^MAGENTA%^name%^RESET%^> %^BOLD%^of the "
			"%^RESET%^%^YELLOW%^item %^RESET%^%^BOLD%^must be EXACTLY the same as the key here, including any "
			"spacing or punctuation.%^RESET%^");
		input_to("add_lock_data",obj,"key");
		return;

	case "3": // lock description

		tell_object(obj,"%^RESET%^%^BOLD%^Please enter the description of the lock.  This will be what the "
			"player sees when they look at this lock specifically.  For example if this lock is named "
			"'padlock', when the character types 'look padlock', they will see the description "
			"you enter here.%^RESET%^");
		input_to("add_lock_data",obj,"description");
		return;

	case "4": // lock difficulty

		tell_object(obj,"%^RESET%^%^BOLD%^Please enter the difficulty for this lock to be picked by thieves.  "
			"This is a number from 0 on up.  The number is basically an exact reduction from their pick locks "
			"percentage.  If you enter 50 for example, then it'll decrease their base pick lock percentage by "
			"50 when trying to pick this door.  For locks that you want there to be no chance of picking, enter "
			"very high numbers, such as 1000.  This will guarantee that a key is needed to get inside.%^RESET%^");
		input_to("add_lock_data",obj,"difficulty");
		return;

	case "5": // is locked?

		tell_object(obj,"%^RESET%^%^BOLD%^Please enter if this lock should begin as locked or not.  Enter "
			"a 1 for locked, or a 0 for unlocked.");
		input_to("add_lock_data",obj,"locked");
		return;

	case "6": // save lock

		save_lock(obj);
		return;

	case "7": // return to lock editor

		tell_object(obj,"%^RESET%^%^BOLD%^Confirmed, returning to lock editor.%^RESET%^");
		PRD->clear_current_lock(WORKING_DOOR,WORKING_LOCK);
		WORKING_LOCK = "";
		create_or_edit_lock(obj);
		return;

	case "8": // return to door editor

		tell_object(obj,"%^RESET%^%^BOLD%^Confirmed, returning to door editor.%^RESET%^");
		PRD->clear_current_lock(WORKING_DOOR,WORKING_LOCK);
		WORKING_LOCK = "";
		create_or_edit_door(obj);
		return;

	case "9": // return to main menu

		tell_object(obj,"%^RESET%^%^BOLD%^Confirmed, returning to main menu.%^RESET%^");
		PRD->clear_current_lock(WORKING_DOOR,WORKING_LOCK);
		WORKING_LOCK = "";
		return;

	case "10": // No locks, return to door editor
		if(!door_check(obj)) { return; }
		tell_object(obj,"%^RESET%^%^BOLD%^Confirmed, no locks for this door, returning to "
			"editor");
		PRD->set_door_data(WORKING_DOOR,"door_locks","");
		create_or_edit_door(obj);
		return;

	default:
		create_or_edit_lock(obj);
		return;
	}
}

void select_door_entry(string str,object obj)
{
	if(!objectp(obj)) { return; }
	switch(str)
	{
	case "1": // name

		tell_object(obj,"%^RESET%^%^BOLD%^Please type the name of the door that you would like to "
			"add or edit.  This will be what the door looks like at the room exits, not the "
			"long description of the door.  IE:  Large Iron Door  %^RESET%^%^YELLOW%^NOTE%^RESET%^%^BOLD%^ "
			"If you are editing an existing door, please note that your capitilization must match the "
			"existing door.%^RESET%^");
		input_to("add_door_data",obj,"name");
		return;

	case "2": // destination

		tell_object(obj,"%^RESET%^%^BOLD%^Please enter the destination room for this door.  All "
			"doors must be placed on an existing exit and this destination must be the same destination "
			"as the door's exit.  For this editor, it does not matter in which order you add the doors "
			"and exits, as long as both the door and exit have the same destination file.  Please enter "
			"the destination in the format   %^RESET%^%^YELLOW%^/d/av_rooms/ares/testroom   %^RESET%^");
		input_to("add_door_data",obj,"destination");
		return;

	case "3": // direction

		tell_object(obj,"%^RESET%^%^BOLD%^Please enter the direction that this door will cover.  This will "
			"be the exit in the room that the door blocks.  This must be a real exit in your room before "
			"the door will load.  The door destination, and door direction must EXACTLY match your room's exit.  "
			"If your room is %^RESET%^%^YELLOW%^north%^RESET%^%^BOLD%^ /realms/ares/test  Then your door "
			"direction would be %^RESET%^%^YELLOW%^north%^RESET%^%^BOLD%^, and your door "
			"destination would be /realms/ares/test %^RESET%^");
		input_to("add_door_data",obj,"direction");
		return;

	case "4": // is closed?

		tell_object(obj,"%^RESET%^%^BOLD%^Please enter a 1 for the door to begin in the closed state and "
			"a 0 for it to begin in the open state.%^RESET%^");
		input_to("add_door_data",obj,"closed");
		return;

	case "5": // open message

		tell_object(obj,"%^RESET%^%^BOLD%^Please enter the open message that players will see when they "
			"open this door.  It can be as simple or as detailed as you would like, but a message must "
			"be set.%^RESET%^");
		input_to("add_door_data",obj,"open_message");
		return;

	case "6": // close message

		tell_object(obj,"%^RESET%^%^BOLD%^Please enter the close message that players will see when "
			"they close this door.  It can be as simple or as detailed as you would like, but a "
			"message must be set.%^RESET%^");
		input_to("add_door_data",obj,"close_message");
		return;

	case "7": // description

		tell_object(obj,"%^RESET%^%^BOLD%^Please enter the long description for the door.  This will "
			"be what the player sees when they actually look at the door in the room.%^RESET%^");
		input_to("add_door_data",obj,"description");
		return;

	case "8": // knock message

		tell_object(obj,"%^RESET%^%^BOLD%^Please enter the knock message that players will see "
			"when they knock on the door.  The players name will be placed immediately before this "
			"message and the name of the doors will be placed immediately after it.  IE: %^YELLOW%^ "
			"grabs the heavy knocker and pounds on the%^RESET%^%^BOLD%^ would be displayed as: "
			"<Player> grabs the heavy knocker and pounds on the <door name>.  This can be as simple "
			"or as detailed as you like.%^RESET%^");
		input_to("add_door_data",obj,"knock");
		return;

	case "9": // locks

		if(!door_check(obj)) { return; }
		tell_object(obj,"%^RESET%^%^BOLD%^Entering the lock editor...%^RESET%^");
		create_or_edit_lock(obj);
		return;

	case "10": // save 

		save_door(obj);
		return;

	case "11": // return to door editor

		tell_object(obj,"%^RESET%^%^BOLD%^Confirmed, returning to door editor.");
		PRD->clear_current_door(WORKING_DOOR);
		WORKING_DOOR = "";
		door_editor(obj);
		return;

	case "12": // return to main menu

		tell_object(obj,"%^RESET%^%^BOLD%^Confirmed, returning to main menu.");
		PRD->clear_current_door(WORKING_DOOR);
		WORKING_DOOR = "";
		main_menu(obj);
		return;

	default:
		main_menu(obj);
		return;

	}
	return;
}

void create_or_edit_lock(object obj)
{
	string *lock_stages=({}),*completed=({}),*display=({});
	int i,num;

	if(!objectp(obj)) { return; }

	lock_stages = PRD->query_lock_stages();
	completed = PRD->query_completed_lock_stages();
	
	for(i=0;i<sizeof(lock_stages);i++)
	{
		if(member_array(lock_stages[i],completed) != -1)
		{
				display += ({ "%^RESET%^%^YELLOW%^>>%^RESET%^%^CYAN%^"+capitalize(lock_stages[i])+"%^RESET%^%^YELLOW%^<<%^RESET%^" });
		}
		else
		{
				display += ({ "%^RESET%^%^YELLOW%^>>%^RESET%^%^RED%^"+capitalize(lock_stages[i])+"%^RESET%^%^YELLOW%^<<%^RESET%^" });
		}
	}
	num = sizeof(display);

	tell_object(obj,"%^RESET%^%^BOLD%^This is the lock editor.  You are not required to put locks on your doors, "
		"but if you do not, they will still have a default lock named 'lock'.  This lock will be lockable and "
		"unlockable from either side without a key.  You can add as many locks to a door as you want.  None of the "
		"information for an individual lock will be saved until you select the save lock option.  If all of the "
		"stages for the lock are completed then the lock will save to the door and you can create another one.  The "
		"individual selections for the lock contain more information about the data you need to enter.%^RESET%^");
	for(i=0;i<sizeof(display);i++)
	{
		tell_object(obj,"  %^RESET%^%^MAGENTA%^"+arrange_string((i + 1)+"%^RESET%^>",4)+""+display[i]+".");
	}
	tell_object(obj,"  %^RESET%^%^MAGENTA%^"+(num + 1)+"%^RESET%^>%^BOLD%^  Save lock.%^RESET%^");
	tell_object(obj,"  %^RESET%^%^MAGENTA%^"+(num + 2)+"%^RESET%^>%^BOLD%^  Return to lock editor.%^RESET%^");
	tell_object(obj,"  %^RESET%^%^MAGENTA%^"+(num + 3)+"%^RESET%^>%^BOLD%^  Return to door editor.%^RESET%^");
	tell_object(obj,"  %^RESET%^%^MAGENTA%^"+(num + 4)+"%^RESET%^>%^BOLD%^  Return to main menu.%^RESET%^");
	tell_object(obj,"  %^RESET%^%^MAGENTA%^"+(num + 5)+"%^RESET%^>%^YELLOW%^ No Locks, return to door editor.%^RESET%^");
	input_to("select_lock_entry",obj);
	return;
}

void create_or_edit_door(object obj)
{
	string *door_stages=({}),*completed=({}),*display=({});
	int i,num;
	
	if(!objectp(obj)) { return; }
	
	door_stages = PRD->query_door_stages();
	completed   = PRD->query_completed_door_stages();

	for(i=0;i<sizeof(door_stages);i++)
	{
		if(member_array(door_stages[i],completed) != -1)
		{
				display += ({ "%^RESET%^%^YELLOW%^>>%^RESET%^%^CYAN%^"+capitalize(door_stages[i])+"%^RESET%^%^YELLOW%^<<%^RESET%^" });
		}
		else
		{
				display += ({ "%^RESET%^%^YELLOW%^>>%^RESET%^%^RED%^"+capitalize(door_stages[i])+"%^RESET%^%^YELLOW%^<<%^RESET%^" });
		}
	}
	num = sizeof(display);

	tell_object(obj,"%^RESET%^%^BOLD%^This is the door editor.  From here you can adjust all of the settings "
		"for the doors for your room.  All doors will have a default 'lock' if a lock is not specified.  "
		"This lock will not have a key and it can be locked and unlocked at will from both inside and outside "
		"the room.  If a key is defined for a door and the door is set to locked, then that key or lockpicking "
		"will be needed to unlock the door.  You do not need to specify a lock and a key for every door.  The "
		"system will set those to default for you.  Note:  Before you can save a door, all of the "
		"required settings must be entered.  Also note that if you leave the door editor at any time before "
		"saving the door, your progress will be lost.  You must enter the Door_id first before any other "
		"information can be entered about the door.  You must have an identical copy of your door in the destination "
		"room that leads back to the first door.  The two doors are connected so that when a player knocks on "
		"one side, people on the other side can hear it.  However, the 'inside' room can have certain details "
		"changed.  For example, you can have the inside set to not locked, or have the lock difficulty set "
		"to 0 so that it can be locked or unlocked from inside without the use of a key.%^RESET%^\n");

	for(i=0;i<sizeof(display);i++)
	{
		tell_object(obj,"  %^RESET%^%^MAGENTA%^"+arrange_string((i + 1)+"%^RESET%^>",4)+""+display[i]+".");
	}
	tell_object(obj,"  %^RESET%^%^MAGENTA%^"+(num + 1)+"%^RESET%^>%^BOLD%^ Save door.%^RESET%^");
	tell_object(obj,"  %^RESET%^%^MAGENTA%^"+(num + 2)+"%^RESET%^>%^BOLD%^ Return to door editor.%^RESET%^");
	tell_object(obj,"  %^RESET%^%^MAGENTA%^"+(num + 3)+"%^RESET%^>%^BOLD%^ Return to main menu.%^RESET%^");
	input_to("select_door_entry",obj);
	return;
}

void door_selection(string str,object obj)
{
	if(!objectp(obj)) { return; }

	switch(str)
	{
	case "1":

		door_display(obj);
		door_editor(obj);
		return;

	case "2": 

		create_or_edit_door(obj);
		return;

	case "3":

		create_or_edit_lock(obj);
		return;

	case "4": 

		tell_object(obj,"%^RESET%^%^BOLD%^Please type the name of the door that you would like to "
			"delete.  Make sure that your capitilization matches the existing door.%^RESET%^");
		input_to("confirm_delete_one_door",obj);
		return;

	case "5": 

		tell_object(obj,"%^RESET%^%^RED%^Are you sure you want to delete all of your doors?  "
			"Enter <yes> to confirm, anything else to abort.");
		input_to("confirm_delete_all_doors",obj);
		return;

	case "6":

		tell_object(obj,"%^RESET%^%^BOLD%^Please type the name of the door followed by the lock that "
			"you want to delete from it.  Use the following syntax: name_of_door*name_of_lock%^RESET%^");
		input_to("confirm_delete_one_lock",obj);
		return;

	case "7":

		tell_object(obj,"%^RESET%^%^BOLD%^Please type the name of the door that you would like to "
			"delete all the locks from.%^RESET%^");
		input_to("confirm_delete_all_locks",obj);
		return;

	case "8": 

		tell_object(obj,"%^RESET%^%^BOLD%^Confirmed, no doors in this room, returning "
			"to editor.");
		PRD->add_stage("doors");
		editor(obj);
		return;

	case "9": 

		tell_object(obj,"%^RESET%^%^BOLD%^Confirmed, returning to editor...%^RESET%^\n");
		editor(obj);
		return;

	case "10": 

		tell_object(obj,"%^RESET%^%^BOLD%^Confirmed, returning to main menu...%^RESET%^\n");
		main_menu(obj);
		return;

	default:
		tell_object(obj,"%^RESET%^%^BOLD%^Returning to main menu.\n");
		main_menu(obj);
		return;
	}
	return;
}

void door_editor(object obj)
{
	if(!objectp(obj)) { return; }
	tell_object(obj,"%^RESET%^%^BOLD%^Please choose one of the following options:\n"
		"  %^RESET%^%^MAGENTA%^1%^RESET%^>%^BOLD%^  Show existing doors and locks.\n%^RESET%^"
		"  %^RESET%^%^MAGENTA%^2%^RESET%^>%^BOLD%^  Add or edit a door.\n%^RESET%^"
		"  %^RESET%^%^MAGENTA%^3%^RESET%^>%^BOLD%^  Add or edit a lock.\n%^RESET%^"
		"  %^RESET%^%^MAGENTA%^4%^RESET%^>%^BOLD%^  Delete a door.\n%^RESET%^"
		"  %^RESET%^%^MAGENTA%^5%^RESET%^>%^BOLD%^  Delete all doors.\n%^RESET%^"
		"  %^RESET%^%^MAGENTA%^6%^RESET%^>%^BOLD%^  Delete a lock from a door.\n%^RESET%^"
		"  %^RESET%^%^MAGENTA%^7%^RESET%^>%^BOLD%^  Delete all locks from a door.\n%^RESET%^"
		"  %^RESET%^%^MAGENTA%^8%^RESET%^>%^YELLOW%^  No Doors for this room, return to editor.\n%^RESET%^"
		"  %^RESET%^%^MAGENTA%^9%^RESET%^>%^BOLD%^  Return to Editor.\n%^RESET%^"
		"  %^RESET%^%^MAGENTA%^10%^RESET%^>%^BOLD%^ Return to Main Menu.\n%^RESET%^");
	input_to("door_selection",obj);
	return;
}

void map_data_entry(object obj,string type)
{
	if(!objectp(obj)) { return; }
	switch(type)
	{
	case "search":

		tell_object(obj,"    %^RESET%^%^BOLD%^Please enter your first search in the format: "
			"search_term*what the player will see when they search.  IE:  footprint*You find "
			"a footprint in the sand.\n"
			"If you do not want any searches, enter a blank line, or **.\n  To delete your searches "
			"and start over, enter <delete>");
		input_to("set_searches",obj,SEARCHES);
		return;

	case "items":

		tell_object(obj,"%^RESET%^%^BOLD%^Please enter the first item.  Items are things in the room that a "
			"player can look at.  There are two options for the format that items can be entered.  "
			"The first format is item*<description of item> IE: chair*This is a sturdy wooden chair.  "
			"The second format is item,item2,item3*description of item  This format is used when "
			"several things in the room have the same description.  If you do not want any items in "
			"this room, enter a blank line or **.  To delete your items and start over, enter <delete>");
		input_to("set_items",obj,ITEMS);
		return;

	case "exits":

		tell_object(obj,"%^RESET%^%^BOLD%^Please enter your first exit in the format: direction /destination/room "
			"IE: north /d/av_rooms/ares/myroom  Note that you do not need the .c on the end of the "
			"file name when making exits.  If you do not want any exits in this room, enter a blank "
			"line or **.  To delete the exits and start over, enter <delete>\n");
		input_to("set_exits",obj,EXITS);
		return;

	case "doors":
		tell_object(obj,"%^RESET%^%^BOLD%^Entering the door editor...%^RESET%^");
		door_editor(obj);
		return;

	default:
		editor(obj);
		return;
	}
	
	return;
}

void string_data_entry(string str,object obj,string type)
{
	int num;
	mapping info=([]);
	string *arr=({});

	if(!objectp(obj)) { return; }

	if(!stringp(str) || str == "q" || str == "quit" || str == "exit" || str == "abort")
	{
		main_menu(obj);
	}

	switch(type)
	{
	case "name":

		PRD->set_room_name(str);
		PRD->set_path(str);
		tell_object(obj,"%^RESET%^%^YELLOW%^File name set to "+str+".  Returning to editor.\n%^RESET%^");
		editor(obj);
		return;

	case "indoors":

		PRD->set_indoors_outdoors(to_int(str));
		if(to_int(str) == 0)
		{
			tell_object(obj,"%^RESET%^%^BOLD%^This room is now set to be an outdoors room.  "
				"Returning to editor.\n%^RESET%^");
		}
		else
		{
			tell_object(obj,"%^RESET%^%^BOLD%^This room is now set to be an indoors room.  "
				"Returning to editor.\n%^RESET%^");
		}
		editor(obj);
		return;

	case "light":

		PRD->set_room_light(to_int(str));
		tell_object(obj,"%^RESET%^%^BOLD%^Light level in the room now set to "+str+".  Returning "
			"to editor.\n%^RESET%^");
		editor(obj);
		return;

	case "terrain_type":

		num = PRD->set_room_terrain(str);
		if(!num)
		{
			tell_object(obj,"%^RESET%^%^YELLOW%^You have entered an invalid terrain type.  "
				"Valid choices for terrains are : "+implode(PRD->query_terrains(),",")+"\n "
				"Please try again.");
			input_to("string_data_entry",obj,"terrain_type");
			return;
		}
		else
		{
			tell_object(obj,"%^RESET%^%^BOLD%^Terrain for the room is now set to "+str+".  "
				"Returning to editor.\n%^RESET%^");
			editor(obj);
			return;
		}
		return;

	case "travel_type":

		info = PRD->query_travel_types();
		arr = keys(info);

		if(member_array(str,arr) == -1)
		{
			tell_object(obj,"%^RESET%^%^YELLOW%^You have entered an invalid travel type.  Valid "
				"choices for travel types are : "+implode(arr,",")+"\n Please try again.%^RESET%^");
			input_to("string_data_entry",obj,"travel_type");
			return;
		}
		else
		{
			tell_object(obj,"%^RESET%^%^BOLD%^Travel type for the room is now set to "+str+".  "
				"Returning to editor.\n%^RESET%^");
			PRD->set_room_travel(str);
			editor(obj);
			return;
		}
		return;

	case "climate":

		num = PRD->set_room_climate(str);
		if(!num)
		{
			tell_object(obj,"%^RESET%^%^YELLOW%^You have entered an invalid climate type.  Valid choices "
				"for climates are: "+implode(PRD->query_climates(),",")+"\n Please try again.%^RESET%^");
			input_to("string_data_entry",obj,"climate");
			return;
		}
		else
		{
			tell_object(obj,"%^RESET%^%^BOLD%^Climate for the room is now set to "+str+".  Returning to "
				"editor.\n%^RESET%^");
			editor(obj);
			return;
		}
		return;

	case "short_desc":

		PRD->set_room_short(str);
		tell_object(obj,"%^RESET%^%^BOLD%^Setting room short description to:\n"+str+"\nReturning to editor.\n");
		editor(obj);
		return;

	case "long_desc":

		PRD->set_long_desc(str);
		tell_object(obj,"%^RESET%^%^BOLD%^Settling room long description to:\n"+str+"\nReturning to editor.\n");
		editor(obj);
		return;

	case "smell":

		PRD->set_room_smell(str);
		tell_object(obj,"%^RESET%^%^BOLD%^Setting the smell in this room to:\n"+str+"\nReturning to editor.\n");
		editor(obj);
		return;

	case "listen":

		PRD->set_room_listen(str);
		tell_object(obj,"%^RESET%^%^BOLD%^Setting the listen in this room to:\n"+str+"\nReturning to editor.\n");
		editor(obj);
		return;

	default:
		editor(obj);
		return;
	}
	return;
}

void editor(object obj)
{
	string *stages=({}),*incomplete = ({}),*display=({});
	int i,j,num;

	if(!objectp(obj)) { return; }
	
	stages = PRD->query_stages();
	
	if(!pointerp(stages) || stages == ({}))
	{
		return notify_fail("%^RESET%^%^RED%^Invalid stages in /cmds/avatar/_makeroom.c, please contact a wiz.%^RESET%^");
	}

	incomplete = PRD->stage_check();

	if(pointerp(incomplete))
	{
		for(i=0;i<sizeof(stages);i++)
		{
			if(member_array(stages[i],incomplete) == -1)
			{
				display += ({ "%^RESET%^%^YELLOW%^>>%^RESET%^%^CYAN%^"+capitalize(stages[i])+"%^RESET%^%^YELLOW%^<<%^RESET%^" });
			}
			else
			{
				display += ({ "%^RESET%^%^YELLOW%^>>%^RESET%^%^RED%^"+capitalize(stages[i])+"%^RESET%^%^YELLOW%^<<%^RESET%^" });
			}
		}
	}
	num = sizeof(display);

	tell_object(obj,"%^RESET%^%^BOLD%^This is the room editor.  The following list includes all of the options "
		"that you are able to modify.  The list is color coded to represent its status.  Items "
		"in %^RESET%^%^RED%^red%^RESET%^%^BOLD%^ have yet to be completed and items "
		"in %^RESET%^%^CYAN%^cyan%^RESET%^%^BOLD%^ have already been set.  You must set every "
		"item before you can save the room.  If you make a mistake when you set an item, you "
		"can pick that item again to make any corections.  The room will not be saved to file "
		"until you choose to do so. %^RESET%^%^YELLOW%^NOTE%^RESET%^%^BOLD%^ While items that are in %^RESET%^"
		"%^CYAN%^cyan%^RESET%^%^BOLD%^ have already been set, you can still go back and change them as many "
		"times as you want until you save the file.%^RESET%^%^BOLD%^  Please make your choice "
		"from the following list:\n");
	for(i=0;i<sizeof(display);i++)
	{
		tell_object(obj,"  %^RESET%^%^MAGENTA%^"+arrange_string((i + 1)+"%^RESET%^>",4)+""+display[i]+".");
	}
	tell_object(obj,"  %^RESET%^%^MAGENTA%^"+(num + 1)+"%^RESET%^> %^BOLD%^Preview Room.\n%^RESET%^"
		"  %^RESET%^%^MAGENTA%^"+(num + 2)+"%^RESET%^>%^BOLD%^ Save room (All items must be completed).\n%^RESET%^"
		"  %^RESET%^%^MAGENTA%^"+(num + 3)+"%^RESET%^>%^BOLD%^ Return to Main Menu.\n%^RESET%^"
		"  %^RESET%^%^MAGENTA%^"+(num + 4)+"%^RESET%^>%^BOLD%^ Exit from avatar room generator.\n%^RESET%^");
	input_to("selection",obj,"editor");
	return;
}

void exit_origin(string str,object obj)
{
	if(!objectp(obj)) { return; }

	if(str == "abort" || str == "quit" || str == "exit" || str == "q")
	{
		main_menu(obj);
		return;
	}

	if(!stringp(str) || str == "" || str == " ")
	{
		tell_object(obj,"%^RESET%^%^YELLOW%^You need to enter an origin room for this exit.  "
			"Please type the full file name of the room you wish the exit to begin.  "
			"You do not need the %^RESET%^%^BOLD%^.c%^RESET%^%^YELLOW%^ on the end.  "
			"Type %^RESET%^<%^MAGENTA%^q%^RESET%^>%^YELLOW%^ or %^RESET%^<%^MAGENTA%^quit%^RESET%^"
			">%^YELLOW%^ to return to the Main Menu%^RESET%^");
		input_to("exit_origin",obj);
		return;
	}
	if(!file_exists(str) && !file_exists(""+str+".c"))
	{
		tell_object(obj,"%^RESET%^%^YELLOW%^You have entered an invalid file for the origin of this exit.  "
			"Please check your spelling and try again.  You do not need the %^RESET%^%^BOLD%^.c "
			"%^RESET%^%^YELLOW%^on the end of the file name.  Enter %^RESET%^<%^MAGENTA%^q%^RESET%^> "
			"%^YELLOW%^or %^RESET%^<%^MAGENTA%^quit%^RESET%^>%^YELLOW%^ to return to the Main Menu.%^RESET%^");
		input_to("exit_origin",obj);
		return;
	}
	tell_object(obj,"%^RESET%^%^YELLOW%^Confirmed, entering "+str+" as the origin room for this exit.  Please "
		"enter the direction that the exit should go.  IE:  north, south, etc.%^RESET%^");
	input_to("exit_direction",obj,str);
	return;
}

void exit_destination(string str,object obj,string room,string direction)
{
	if(!objectp(obj)) { return; }

	if(str == "abort" || str == "quit" || str == "exit" || str == "q")
	{
		main_menu(obj);
		return;
	}

	if(!stringp(str) || str == "" || str == " ")
	{
		tell_object(obj,"  %^RESET%^%^YELLOW%^You need to enter a destination for this exit, you must enter "
			"the full path, but you need not add the %^RESET%^%^BOLD%^.c%^RESET%^%^YELLOW%^ at the end.%^RESET%^");
		input_to("exit_destination",obj,room,direction);
		return;
	}
	if(!file_exists(str) && !file_exists(""+str+".c"))
	{
		tell_object(obj,"%^RESET%^%^YELLOW%^You have entered an invalid destination room for this exit.  Please "
			"check your spelling and try again.  Enter <q> or <quit> to return to the main menu.%^RESET%^");
		input_to("exit_destination",obj,room,direction);
		return;
	}
	tell_object(obj,"%^RESET%^%^BOLD%^Confirmed, adding a "+direction+" exit from room "+room+" to "
		"room "+str+".%^RESET%^");
	str = replace_string(str,".c","");
	find_object_or_load(room)->add_exit(str,direction);
	tell_object(obj,"%^RESET%^%^YELLOW%^Finishing...\nReturning to Main Menu.%^RESET%^\n");
	main_menu(obj);
	return;
}

void exit_direction(string str,object obj,string room)
{
	if(!objectp(obj)) { return; }

	if(str == "abort" || str == "quit" || str == "exit" || str == "q")
	{
		main_menu(obj);
		return;
	}

	if(!stringp(str) || str == "" || str == " ")
	{
		tell_object(obj,"%^RESET%^%^BOLD%^You need to enter a direction that this exit should go.  IE: "
			"north, south, etc.%^RESET%^");
		input_to("exit_direction",obj,room);
		return;
	}
	if(!file_exists(room) && !file_exists(""+room+".c"))
	{
		tell_object(obj,"%^RESET%^%^BOLD%^You have entered an invalid source room, returning "
			"to main menu.%^RESET%^");
		main_menu(obj);
		return;
	}
	tell_object(obj,"%^RESET%^%^BOLD%^Confirmed, exit direction "+str+" entered.  Please enter the destination "
		"room for this exit.  You must enter the whole destination, but you do not need the "
		"%^RESET%^%^YELLOW%^.c %^RESET%^%^BOLD%^on the end of the file name.%^RESET%^");
	input_to("exit_destination",obj,room,str);
	return;
}

void add_room_exit(string str,object obj)
{
	string room;
	if(!objectp(obj)) { return; }
	switch(str)
	{
	case "1":		
		tell_object(obj,"%^RESET%^%^BOLD%^Confirmed, adding exit from "+base_name(environment(obj))+"\n"
			"Please enter the direction that this exit should go.  IE: north, south, etc.%^RESET%^");
		room = base_name(environment(obj));
		input_to("exit_direction",obj,room);
		return;

	case "2":
		tell_object(obj,"%^RESET%^%^BOLD%^Please enter the complete file name of the room you wish the exit "
			"to originate from.  You do not need to use %^RESET%^%^YELLOW%^.c%^RESET%^%^BOLD%^ on "
			"the end of the file.\n%^RESET%^");
		input_to("exit_origin",obj);
		return;

	case "3":
		main_menu(obj);
		return;

	case "4":
		quit(obj);
		return;

	default:
		main_menu(obj);
		return;
	}
	return;
}

void move_rooms(string str,object obj)
{
	if(!objectp(obj)) { return; }

	if(!stringp(str) || !file_exists(str))
	{
		tell_object(obj,"%^RESET%^%^BOLD%^That room either does not exist, or you have mispelled "
			"it.  Please check your spelling and capitalization.  You must include the entire path of the room "
			"plus the %^RESET%^%^YELLOW%^.c%^RESET%^%^BOLD%^ on the end.  IE: /d/av_rooms/ares/myroom.c\n"
			"Please select one of the following options: \n"
			"  %^RESET%^%^MAGENTA%^1%^RESET%^> %^BOLD%^Enter the file name again.\n%^RESET%^"
			"  %^RESET%^%^MAGENTA%^2%^RESET%^> %^BOLD%^Return to the main menu.\n%^RESET%^"
			"  %^RESET%^%^MAGENTA%^3%^RESET%^> %^BOLD%^Exit the avatar room generator.\n%^RESET%^");
		input_to("selection",obj,"move_rooms_fail");
		return;
	}
	obj->move(str);
	tell_object(obj,"%^RESET%^%^YELLOW%^Moving to new location...%^RESET%^");
	tell_object(obj,"%^RESET%^%^YELLOW%^Displaying room...%^RESET%^");
	tell_object(obj,environment(obj)->query_short());
	tell_object(obj,environment(obj)->query_long()+"\n");
	tell_object(obj,environment(obj)->query_long_exits()+"\n");
	tell_object(obj,"%^YELLOW%^Room description shortened for display purposes...%^RESET%^");
	tell_object(obj,"%^RESET%^%^YELLOW%^Please select one of the following options:\n%^RESET%^"
		"  %^RESET%^%^MAGENTA%^1%^RESET%^> %^BOLD%^Return to main menu.\n%^RESET%^"
		"  %^RESET%^%^MAGENTA%^2%^RESET%^> %^BOLD%^Exit the avatar room generator.%^RESET%^");
	input_to("selection",obj,"move_rooms_pass");
	return;
}

void set_path(object obj)
{
	string name;
	if(!objectp(obj))
	{
		return notify_fail("TP is invalid in set_path in /cmds/avatar/avatar_room_generator.c");
	}	
	name = (string)obj->query_true_name();
	DIR = PATH + name + "/";
	PRD->set_path(DIR);
	return;
}

void end_of_display(object obj)
{
	tell_object(obj,"\n\n%^RESET%^%^BOLD%^Please select one of the following options.\n"
		"  %^RESET%^%^MAGENTA%^1%^RESET%^> %^BOLD%^Return to Main Menu.\n%^RESET%^"
		"  %^RESET%^%^MAGENTA%^2%^RESET%^> %^BOLD%^Exit the avatar room generator.\n%^RESET%^");
	input_to("selection",obj,"display_rooms");
	return;
}

void display_rooms(object obj)
{
	string *rooms=({}),*display=({}),line;
	function func;
	int i;

	if(!objectp(obj)) { return; }

	if(pointerp(get_dir(DIR)))
	{
		rooms = get_dir(DIR);
	}

	if(sizeof(rooms))
	{
		for(i=0;i<sizeof(rooms);i++)
		{
			if((i + 2) < sizeof(rooms)-1)
			{
				line = "%^RESET%^%^YELLOW%^  "+arrange_string(rooms[i],24)+""+arrange_string(rooms[i+1],24)+""+arrange_string(rooms[i+2],24)+"";
				i += 2;
			}
			else if((i + 1) <= sizeof(rooms)-1)
			{
				line = "%^RESET%^%^YELLOW%^  "+arrange_string(rooms[i],24)+""+arrange_string(rooms[i+1],24)+"";
				i++;
			}
			else
			{
				line = "%^RESET%^%^YELLOW%^  "+arrange_string(rooms[i],24)+"";
			}
			display += ({ line });
		}

		tell_object(obj,"%^RESET%^%^BOLD%^You currently have these rooms in your directory:\n%^RESET%^");
		func = (:call_other,TO,({"end_of_display",obj}):);
		obj->more(display,"info",func);
	}

	else
	{
		tell_object(obj,"%^RESET%^%^YELLOW%^Currently there are no rooms listed in your directory.%^RESET%^");
		end_of_display(obj);
	}
	return;
}

int help(string str)
{
	write("%^RESET%^%^BOLD%^This is the room generator for avatars to create rooms for plot related play.  "
		"These rooms are meant to be temporary in nature and will not have a permenant "
		"entrance from the mud as a whole.  The rooms are set to 'no teleport' to prevent "
		"players from remembering locations there and abusing unaccesable rooms where the "
		"avatars are not online.  The individual menu prompts contain the help files that "
		"you should need to understand the command.  If there are any problems or suggestions "
		"send a mail to Ares.%^RESET%^");
	return 1;
}

void quit(object obj)
{
	if(!objectp(obj)) { return; }
	tell_object(obj,"%^RESET%^%^YELLOW%^Exiting from the avatar room generator...\n\n%^RESET%^");
	if(objectp(PRD)) { PRD->remove(); }
	if(objectp(TO)) { TO->remove(); }
	return;
}

int path_check(object obj,string path)
{
	if(!objectp(obj)) { return 0;}
	if(!stringp(path)) { return 0; }
	write("DIR: "+DIR+"  path: "+path+"");
	if(strsrch(path,DIR) == -1) { return 0; }
	return 1;
}

void begin(object obj)
{
	PRD = new(OP);
	PRD->move(obj);
	set_path(obj);
	main_menu(obj);
	return 1;
}

void create()
{
	::create();
	seteuid(UID_SYSTEM);
	return;
}

