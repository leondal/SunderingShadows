inherit "/std/monster";

int count_eggs;

create() {
    ::create();
   set_name("easter bunny");
   set("id",  ({ "bunny", "easter bunny" }) );
    set("short", "Easter bunny");
    set("long", "Hippity Hoppity.\nOh, joy, it's the Easter Bunny.\nWatch him drool.\nHe is hiding Easter eggs all over Nightmare.\n");
   set("aggressive", 0);
   set_speed(30);
   set_moving(1);
    set_gender("male");
  set_level(30);
   set_alignment(200);
   set("race", "mutant bunny");
   set_max_hp(500000);
   set_hp(500000);
    set_chats(10,
        ({ "The Easter Bunny drools.\n",
        "The Easter Bunny farts at you.\n",
        "The Easter Bunny mumbles about rotten eggs.\n" })
    );
    set_skill("melee", 400);
    set_body_type("quadraped");
}

void catch_tell(string str) {
    string who;

    if(!interact("enters", str)) return;
    sscanf(str, "%s enters%*s", who);
    who = lower_case(who);
    call_out("egghead", 2, who);
}

void egghead(string who) {
    object ob, it;

    ob = present(who, environment(this_object()));
    if(!ob) return;
    if(random(101) < 25) {
        tell_object(ob, "The Easter Bunny throws an egg at you!\n");
        tell_room(environment(this_object()), "The Easter Bunny throws an egg at "+ob->query_cap_name()+".\n", ({ ob }));
        it = new("/obj/misc/easter_egg");
        it->move(ob);
    }
}

void heart_beat() {
    object it;
    count_eggs++;
    if(count_eggs > 60) {
        count_eggs = 0;
        it = new("/obj/misc/easter_egg");
        it->move(this_object());
        force_me("hide egg");
    }
    ::heart_beat();
}
