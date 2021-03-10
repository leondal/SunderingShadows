#include <std.h>

//#define TYPES ({"ring","bracer","clothing","leather","sheath","thiefshield"})
//I've changed this to use is_ok_armour() - Saide

inherit OBJECT;
object current_room;

string name;
object player;
void set_player_name(string str);
void dest_fun();
int force_cancel();

void set_player(object obj)
{
    player = obj;
//   if (objectp(find_player("garrett"))) tell_object(find_player("garrett"),identify(obj));
}

void set_room(object rm) { if (objectp(rm)) current_room = rm; }

object query_player() { return player; }

void create()
{
    int score;
    ::create();
    set_id(({"completely random id "+random(999999)+"","TSR80"}));
    set_name("");
    set("short","");
    set_weight(0);
    set_property("no animate",1);
    name = "-1";
//   TO->move(player);// This might be causing bugs, trying to move it to a non-object thing.
    set_heart_beat(1);
   set_no_clean(1);
}


void heart_beat()
{
    if(!objectp(TO)) { return; }
    if(!objectp(ETO)) { return; }
    if(sizeof(ETO->query_attackers())) { force_cancel(); }
    return;
}

void init()
{
    ::init();

    if(objectp(player)) { current_room=environment(player); }

    call_out("test_invis",5);

    add_action("cancel_inv","quit");
    add_action("cancel_inv","cast");
    add_action("cancel_inv","kill");
    add_action("cancel_inv","say");
    add_action("cancel_inv","stab");
    add_action("force_cancel","step");  // changed to use force_cancel()
    add_action("cancel_inv", "yell");
}


int cancel_inv()
{
    if(!objectp(player))
    {
        dest_fun();
        return 0;
    }
    if(player->query_hidden()) { player->set_hidden(0); }
    
    player && tell_object(player, "%^YELLOW%^You appear from the shadows.%^RESET%^");
    call_out("dest_fun",1);
    return 0;
}

int force_cancel()
{
  cancel_inv();
  return 1;
}


void dest_fun()
{
    if(objectp(player))
    {
        if(player->query_hidden()) { player->set_hidden(0); }
    }
    remove_call_out("test_invis");
    ::remove();
}

void test_invis()
{
    int percent;
    int score;

    if(!objectp(player)) { return; }

      if(player->query_in_vehicle() && objectp(player->query_in_vehicle()))
    {
        cancel_inv();
        return;
    }

    if(environment(player)!=current_room)
    {
        percent=20;
        score = player->query_skill("stealth") + roll_dice(1,20);

   if(sizeof(TP->query_armour("torso"))) score += TP->skill_armor_mod(TP->query_armour("torso"));
   if(sizeof(TP->query_armour("left foot"))) score += TP->skill_armor_mod(TP->query_armour("left foot"));
   if(sizeof(TP->query_armour("right foot"))) score += TP->skill_armor_mod(TP->query_armour("right foot"));
        if(score <percent) { force_cancel(); }
        else current_room = environment(player);
    }

    if (!player->query_hidden())
    {
        call_out("dest_fun",1);
        return 1;
    }
   call_out("test_invis",2);
}

int save_me(string file) {return 0;}

int remove() {
  object temp;
  temp = find_object_or_load("/cmds/mortal/_sneak.c");
  if (PO != temp)
    log_file("player/hide","PO: "+identify(PO)+". At: "+ctime(time())+".\n");
    dest_fun();
    ::remove();
}
void internal_remove() { ::remove(); }
