/*
  compiler.c
  
  Uses my basic compiler to create a virtual zone.
  Next iteration of alternative reality quest.
  
  -- Tlaloc -- 9.19.21
*/

#include <daemons.h>

//X and Y Axis Limits
#define MAX_WIDTH 5
#define MAX_HEIGHT 10
#define PATH "/d/common/obj/special/daily/"

//rename_object() or compile() would have been the ideal method
//to do this. Without those funs, we will use a mapping instead.

mapping cloned_rooms;
       
string dest_room;

void compile_plane()
{
    int x;
    string key, exit_key, short, long;
    object room;
    
    x = 0;
    cloned_rooms = ([  ]);

    short = get_room_short();
    
    //Clone the rooms
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
                     
            if(objectp(room))
                write("Adding room : " + file_name(room) + " to ["+x+"]["+y+"]");                
            else
            {
                write("Error: Room add not successful.");
                continue;
            }
            
            long = get_room_long();
            room->set_short(short);
            room->set_long(long);
            
        }
        x++;       
    }
  
    x = 0;

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
            
                write("Attempting to add exits to " + file_name(cloned_rooms[key]));
        
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
}

void destroy_plane()
{
    string file;
    
    object *rooms, ob;
    
    if(!sizeof(cloned_rooms))
    {
        write("No rooms in the mapping.");
        return;
    }
    
    foreach(string str in keys(cloned_rooms))
    {
        ob = cloned_rooms[str];
        if(!objectp(ob))
        {
            write(str + " is not an object.");
            continue;
        }
        write("Destroying : " + file_name(ob));
        destruct(ob);
    }
    
    cloned_rooms = ([  ]);
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
    return CRAYON_D->color_string("Plane of Shadows", "very black");
}

string get_room_long()
{
    return CRAYON_D->color_string("You are lost in the Plane of Shadows.", "dark black");
}
