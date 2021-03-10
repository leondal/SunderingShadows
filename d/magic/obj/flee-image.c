#include <std.h>
inherit TOWNSMAN;

object caster;
int flag;
void vanish();

void create(){
   ::create();
   set_name("wavering illusion");
   set_max_hp(99999);
   set_hp(99999);
   set_hd(50,10);
   set("aggressive",0);
   set_spoken("wizish");
   flag = 0;
}

void set_caster(object spellcaster) {
    int mylevel, myhp, myac;
    caster = spellcaster;
    if(!objectp(caster)) { vanish(); return; }
    mylevel = caster->query_level();
    myhp = caster->query_max_hp();
    myac = caster->query_ac();
    set_max_hp(myhp);
    set_hp(myhp);
    set_hd(mylevel,10);
    set_ac(myac);
}

void vanish(){
    tell_object(ETO,"The illusionary image fades away.");
    TO->move("/d/shadowgate/void");
    TO->remove();
}

void heart_beat() { // this greeble only lasts one round!
   ::heart_beat();
   if(!flag) { flag++; return; }
   if(flag) vanish();
}

void die(object ob) { vanish(); }
