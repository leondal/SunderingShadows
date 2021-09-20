/*
  compiler.c
  
  Uses my basic compiler to create a virtual zone.
  Next iteration of alternative reality quest.
  
  -- Tlaloc -- 9.19.21
*/

/*
  This is, in my opinion, a simpler method of implementing an
  alternate reality kind of quest.
  
  The idea here is that, in the entrance room, a command exists to
  clone a compiler for that character and use it to build and destroy
  the plane.
  
  Essentially, this is a virtual object that clones a virtual area.
*/

/* This system consists of several components:
   -- This compiler object, which creates the rooms, adds the exits, and places monsters.
      ->This object is a clone specific to the player using the demiplane.
   -- The entrance room, or hub, where the player initiates the creation of the demiplane.
   -- The quest item, which is the goal of the player. This will be placed on a boss monster.
      ->When picked up, it will move the player to the hub and destroy the plane.
   -- The boss monster, which will be holding the said quest item.
*/

#include <daemons.h>

//X and Y Axis Limits
#define MAX_WIDTH 2
#define MAX_HEIGHT 5
#define PATH "/d/common/obj/daily/"

//rename_object() or compile() would have been the ideal method
//to do this. Without those funs, we will use a mapping instead.

mapping cloned_rooms;
       
string dest_room;
string *monsters_to_use;

void compile_plane(object owner)
{
    int x;
    string key, exit_key, short, long;
    object room;
    
    if(!userp(owner))
        owner = previous_object();
    if(!userp(owner))
    {
        write("Owner identification failed!");
        return;
    }
    
    x = 0;
    cloned_rooms = ([  ]);

    short = get_room_short();
    //This gives us a list of filenames for monsters, based on level
    monsters_to_use = shuffle(CHAMPION_D->retrieve_monster_list(owner->query_level()));
    monsters_to_use = monsters_to_use[0..5];
    
    if(!sizeof(monsters_to_use))
    {
        write("Monster list compile fail...");
        return;
    }
    
    //Clone the rooms, clone the monsters
    while(get_eval_cost() > 10000 && x < MAX_WIDTH)
    {
        for(int y = 0; y < MAX_HEIGHT; y++)
        {
            key = (string)x + "x" + (string)y;
            
            if(load_object(PATH + key))
                room = find_object(PATH + key);
            else
                room = clone_object(PATH + "base_room");
            
            cloned_rooms += ([ key : room, ]);
                     
            if(!objectp(room))
            {
                write("Adding room failed: ["+x+"] ["+y+"]");
                //write("Adding room : " + file_name(room) + " to ["+x+"]["+y+"]");
                continue;
            }
            
            long = get_room_long();
            room->set_short(short);
            room->set_long(long);
            room->set_owner(owner);
            room->set_compiler(this_object());
            
            
            //Add monsters
            for(int z = 0; z < random(6); z++)
            {
                if(catch(new(monsters_to_use[random(sizeof(monsters_to_use) - 1)])->move(cloned_rooms[key])))
                {
                    write("Monster cloning failed!");
                    continue;
                }
            }           
        }
        x++;       
    }
  
    x = 0;

    write("Adding room exits...");
    
    //Arrange exits
    while(get_eval_cost() > 10000 && x < MAX_WIDTH)
    {
        if(!sizeof(cloned_rooms))
        {
            write("No mapping size");
            return;
        }
        
        for(int y = 0; y < MAX_HEIGHT; y++)
        {
            key = (string)x + "x" + (string)y;
        
            if(objectp(cloned_rooms[key]))
            {
            
                //write("Attempting to add exits to " + file_name(cloned_rooms[key]));
        
                //North
                if(y < MAX_HEIGHT - 1)
                {
                    exit_key = (string)x + "x" + (string)(y + 1);
                    if(load_object(PATH + exit_key))
                        dest_room = PATH + exit_key;
                    else
                        objectp(cloned_rooms[exit_key]) && dest_room = file_name(cloned_rooms[exit_key]);
                    
                    dest_room && cloned_rooms[key]->add_exit(dest_room, "north");
                }

                //South
                if(y > 0)
                {
                    exit_key = (string)x + "x" + (string)(y - 1);
                    if(load_object(PATH + exit_key))
                        dest_room = PATH + exit_key;
                    else
                        objectp(cloned_rooms[exit_key]) && dest_room = file_name(cloned_rooms[exit_key]);
                    
                    dest_room && cloned_rooms[key]->add_exit(dest_room, "south");
                }
        
                //East
                if(x < MAX_WIDTH - 1)
                {
                    exit_key = (string)(x + 1) + "x" + (string)y;
                    if(load_object(PATH + exit_key))
                        dest_room = PATH + exit_key;
                    else
                        objectp(cloned_rooms[exit_key]) && dest_room = file_name(cloned_rooms[exit_key]);
                    
                    dest_room && cloned_rooms[key]->add_exit(dest_room, "east");
                }

                //West
                if(x > 0)
                {
                    exit_key = (string)(x - 1) + "x" + (string)y;
                    if(load_object(PATH + exit_key))
                        dest_room = PATH + exit_key;
                    objectp(cloned_rooms[exit_key]) && dest_room = file_name(cloned_rooms[exit_key]);
                    
                    dest_room && cloned_rooms[key]->add_exit(dest_room, "west");
                }
        
                if(!sizeof(cloned_rooms[key]->query_exits()))
                {
                    write("No exits added to " + file_name(cloned_rooms[key]));
                    return;
                }
            }
        }
        
        x++;
    }
    
    write("Area Compiled Successfully!");
    
    if(!catch(owner->move(cloned_rooms["0x0"])))
        write("Transfer of owner to area successful!");
    
    call_out("check_plane", 60, owner);
}

void check_plane(object owner)
{
    //Check if they're still logged in
    if(!userp(owner))
        destroy_plane(owner);
    
    //Check if they're still in the area
    if(environment(owner)->query_owner() != owner)
        destroy_plane(owner);        
    
    call_out("check_plane", 60, owner);
}

void destroy_plane(object owner)
{
    string file;
    
    object *rooms, ob;
    
    if(!sizeof(cloned_rooms))
    {
        write("No rooms in the mapping.");
        return;
    }
    
    if(objectp(owner) && environment(owner)->is_demiplane_room())
    {
        owner->move(PATH + "entrance");
        tell_object(owner, "You are whisked away to safety as the plane collapses!");
    }
    
    foreach(string str in keys(cloned_rooms))
    {
        ob = cloned_rooms[str];
        if(!objectp(ob))
        {
            write(str + " is not an object.");
            continue;
        }
        //write("Destroying : " + file_name(ob));
        destruct(ob);
    }
    
    owner->remove_property("demiplane compiler");
    "/d/common/obj/daily/entrance"->remove_traveler(owner);
    cloned_rooms = ([  ]);
    destruct(this_object());
}

mapping query_rooms()
{
    return cloned_rooms;
}

string get_room_file(int x, int y)
{
    string key;
    
    key = (string)x + "x" + (string)y;
    return file_name(cloned_rooms[key]);
}

string get_room_short()
{
    return CRAYON_D->color_string("Strange Demiplane", "very black");
}

string get_room_long()
{
    return CRAYON_D->color_string("You are lost in a strange Demiplane.", "dark black");
}