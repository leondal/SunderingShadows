inherit "/std/room";

void create() {
    object ob;

    ::create();
    set_property("light", 2);
    set_property("indoors", 1);
   set("short","Changes Board Room");

    set("long", (: this_object(), "go_away" :));
    set_exits( 
  (["west" : "planning_room"]));
    set_invis_exits( ({ "up" }) );
    set_pre_exit_functions( ({ "up" }), ({ "do_check" }) );
    ob = new("/std/bboard");
    ob->set_name("board");
  ob->set_id( ({"board","project board"}) );

   ob->set_board_id("project");
    ob->set_max_posts(30);
  ob->set_location("/d/standard/project");
  ob->set("short","The Code Change Board");
   ob->set("long","Post all mudlib changes you make here.\n");
}

int do_check() { return archp(this_player()); }

string go_away() {
    string str;

    if(archp(this_player())) str = "The arch meeting room is upstairs. ";
    else str = "";
    str += "This is where you post ideas for our MUD.";
    return str;
}

