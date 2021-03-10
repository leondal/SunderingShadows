#include <std.h>
inherit OBJECT;

#define NORTH 0
#define NORTHEAST 1
#define EAST 2
#define SOUTHEAST 3
#define SOUTH 4
#define SOUTHWEST 5
#define WEST 6
#define NORTHWEST 7

#define STRAIGHT 0
#define BEND_RIGHT 1
#define RIGHT 2
#define SHARP_RIGHT 3
#define FULL_TURN 4
#define BEND_LEFT 5
#define LEFT 6
#define SHARP_LEFT 7
#define DOGLEG_LEFT 8
#define DOGLEG_RIGHT 9
#define DEAD_END 10
#define IN_SPIRAL_LEFT 11
#define IN_SPIRAL_RIGHT 12

string mazename, startpoint, endpoint, *special_rooms, roompath;
int x, y, direction, gridsize, start_x, start_y, next_section, prev_x, prev_y, room_number, sections_added, count;
mapping room_map = ([]);


void set_special_rooms(string * rooms);
void add_special_room(string room);
void set_roompath(string str);
string query_roompath();
void remove_special_room(string room);
string * query_special_rooms();
void set_gridsize(int size);
int query_gridsize();
void set_start_x(int i);
void set_start_y(int i);
int query_start_x();
int query_start_y();
void set_direction(int dir);
int query_direction();
int calculate_x(int start_point, int direction);
int calculate_y(int start_point, int direction);
int calculate_location(int start, int direction);
int find_location(int start, int direction, int turn);
int add_room(int turn, object ob);
int add_section(int type, object ob);
int init_maze(int start_x, int start_y, string name, int size);
int build_maze(object ob);
int set_main_path(object ob);

void create(){
      ::create();
      x = 1;
      y = 1;
      direction = 1;
      gridsize = 10;
      start_x = random(10);
      start_y = random(10);
      next_section = 0;
      room_number - 0;
      set_name("sign");
      set_id(({"sign", "notice"}));
      set_short("a sign");
      set_long("An interesting looking sign about the maze. You should read it."); 
    	set_weight(20000);
   	set_value(2);
}

