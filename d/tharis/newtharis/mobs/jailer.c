#include <std.h>
#include "/d/common/common.h"
#include <daemons.h>

#define CITYLAW "tharis law"

inherit "/std/jailer";

int give_key(string str);
int guard_check(string str);

void create()
{
    ::create();
    set_jail("/d/tharis/newtharis/rooms/jail_main");
    set_cell("/d/tharis/newtharis/rooms/jail");
    set_property("official","tharis");
    set_property("knock unconscious",1);
    set_id(({"jailer", "guard", "girard", "tharis jailer", CITYLAW}));
    set_name("tharis jailer");
    set_short("%^CYAN%^BOLD%^Girard, the Tharis Jailer%^RESET%^");
    set_long(CRAYON_D->color_string("You see before you a man of a pale complexion and dark disposition. He is wearing a high-collared grey leather jacket, which extends down to his knees, just above his knee-length riding boots. He carries a single arming sword at his side, kept in a leaf-gilt fine leather scabbard. His face is serious and forebidding, with deep black eyes that stare at you with cold intensity. The shadows around him seem to seep into him, nourishing him with their dark caress.  He obviously takes his job as the city jailer VERY seriously.", "very black"));
    set_race("human");
    set_gender("male");
    set_size(2);
    set_hd(60);
    set_acquired_template("shade");
    set_hp(roll_dice(query_hd(),60));
    set_max_level(50);
    set_overall_ac(-60);
    set_exp(1000);
    set_alignment(3);
    set_class("fighter");
    set_stats("charisma",12);
    set_stats("strength", 24);
    set_stats("constitution", 24);
    set_stats("wisdom", 16);
    set_stats("dexterity", 14);
    set_property("swarm",1);
    set_property("no bows", 1);
    set_property("no dominate", 1); 
    new("/d/tharis/newtharis/obj/jail_key")->move(this_object());
    force_me("wear key");
    new("/d/common/obj/armour/coif")->move(TO);
    command("wear coif");
    switch(random(3)) {
        case 0:
        RANDGEAR->arm_me(this_object(), "edgedm", 30, 2, 75);
        RANDGEAR->armor_me(this_object(), "shield", 30, 1, 75);
            break;
        case 1:
        RANDGEAR->arm_me(this_object(), "edgedl", 30, 2, 75);
            break;
        case 2:
        RANDGEAR->arm_me(this_object(), "bluntm", 30, 2, 75);
        RANDGEAR->arm_me(this_object(), "blunts", 30, 2, 75);
            break;
    }
}

void reset()
{
   object ob;
   ::reset();
   if(ob = present("skeleton key", this_object()))
      if(!ob->query_worn())
        command("wear key");
}

void init()
{
   ::init();
   if(base_name(environment(this_object())) == JailFile) {
      add_action("guard_check", "pick");
      add_action("guard_check", "unlock");
   }
   add_action("no_way","rush");
   add_action("no_way","stab");
}

int kill_ob(object ob, int i)
{
    int hold;
    object room;
    
    room = environment(this_object());
    
    hold = ::kill_ob(ob,i);
    if (hold)
    {
        tell_room(room, "The jailer yells loudly for help.");
        new("/d/antioch/antioch2/mons/patrol_guard")->move(room);
        new("/d/antioch/antioch2/mons/patrol_guard")->move(room);
        new("/d/antioch/antioch2/mons/patrol_guard")->move(room);
    }
    return hold;
}

int guard_check(string str)
{
   string *jailers;
   jailers = AREALISTS_D->query_jailer_names(JailLoc);
   if(strsrch(str, "cell door") == -1)
        return 0;
   if(member_array(this_player()->query_name(),jailers) != -1 || this_player()->id(CITYLAW) || this_player()->query_true_invis())
      return 0;
   if(str == "lock on cell door") { 
      tell_room(environment(this_player()),"The jailer catches "+this_player()->QCN+" trying to pick the lock to the cell door!", this_player());
      tell_object(this_player(),"The jailer catches you trying to pick the lock and attacks!");
   }
   if(str == "cell door with key" || str == "cell door with skeleton key") {
      if(this_player()->query_true_invis())   return 0;
      tell_room(environment(this_player()),"The jailer catches "+this_player()->QCN+" trying to unlock "
         "the cell door!", this_player());
      tell_object(this_player(),"The jailer catches you trying to unlock "
         "the cell door and attacks!");
   }
   force_me("kill "+this_player()->query_name());
   command("block south");
   return 1;
}
