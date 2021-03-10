#include <std.h>

inherit DAEMON;
 
int cmd_backstab(string str) {
    object *weapons, *knives;
   object victim;
    int *wc;
    string *type;
    int i, j, tmp;
 
    if(!str) {
       notify_fail("Backstab whom?\n");
       return 0;
    }
    if(this_player()->query_ghost()) {
       notify_fail("How sly!\n");
       return 0;
    }
    if(this_player()->query_disabled()) return 1;
    if(environment(this_player())->query_property("no attack")) {
        notify_fail("Jerk.\n");
        return 0;
    }
    if((int)this_player()->query_skill("murder") < 5) {
        notify_fail("Don't you wish you were fast enough for that?\n");
        return 0;
    }
    if(!(victim = present(lower_case(str),environment(this_player())))) {
        notify_fail("You don't see the target here.\n");
        return 0;
    }
    if(victim == this_player()) {
        notify_fail("Backstab yourself?\n");
        return 0;
    }
    if(victim->query_ghost()) {
        notify_fail("Backstab whom?\n");
        return 0;
    }
   if(!living(victim)){
        notify_fail("You would look silly backstabbing that.\n");
        return 0;
    }
    wc = ({});
    type = ({});
    knives = ({});
    weapons = (object *)this_player()->query_wielded();
    for(i=0, tmp = sizeof(weapons); i<tmp; i++) {
        if((string)weapons[i]->query_type() != "knife") continue;
        type += ({(string)weapons[i]->query_type() });
        wc += ({ (int)weapons[i]->query_wc() });
        knives += ({ weapons[i] });
    }
    if(!sizeof(knives)) {
        write("You are not well equipped for backstabbing.");
        return 1;
    }
    this_player()->set_disabled();
        if(member_array(victim, (object *)this_player()->query_hunted()) != -1 ||
      member_array(victim, (object *)this_player()->query_attackers())!=-1) {
        notify_fail("You have lost the element of surprise!\n");
        return 0;
    }
   if(this_player()->query_current_attacker()) {
        notify_fail("You are already in combat with something else!\n");
         return 0;}
    if(victim->is_player() && !interactive(victim)) return 0;
    if(!this_player()->kill_ob(victim, 0)) return 1; /* PK hack by Val */
    write("You backstab " + (string)victim->query_cap_name() + ".");
    say(this_player()->query_cap_name() + " backstabs "+
     victim->query_cap_name() + ".", victim);
    j = (int)this_player()->query_skill("murder");
    j -= (int)victim->query_stats("dexterity");
    if(j>9) j = (j/20) + 1;
    else j = 1;
    this_player()->add_skill_points("murder",5);
    for(i=0, tmp = sizeof(knives); i<tmp; i++) {
        knives[i]->set_wc(
          (int)knives[i]->query_wc() +
          (((int)this_player()->query_skill("murder"))*
          ((int)knives[i]->query_wc()))/100
        );
    }
    for(i=0; i<j; i++)
      this_player()->execute_attack();
    for(i=0; i<sizeof(knives); i++)
      knives[i]->set_wc(wc[i]);
   this_player()->add_alignment(-5);
   return 1;
}
 
void help() {
    write("Syntax: backstab <enemy>\n\n"
      "This command is used to initiate combat with the\n"
      "monster or player you specify.\n"
    );
}
 
