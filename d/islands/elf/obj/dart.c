// dart that makes people mad -hades 1/31/2012
#include <std.h>
#include <daemons.h>
inherit THROWING_WEAPON;


void create() {
    ::create();
    set_id(({"dart","red dart","rage dart"}));
    set_name("Rage Dart");
    set_obvious_short("A %^RED%^red%^RESET%^ dart");
    set_short("%^RED%^rage dart%^RESET%^");
    set_long("This is a strange looking dart that has been "+
	"covered in a dark red liquid.  It has a metal tip that "+
	"is barbed in such a way as to be well coated in liquid. "+
	" The shaft is made of wood.  It has several feathers "+
	"attached to the end to make it fly straight.");
    set_lore("These darts have been coated in a herb"+
	" that causes the victim to fall into an uncontrollable"+
	" rage and attack everything in sight.");
    set_property("lore difficulty",12);
    set_weight(2);
    set_value(1000);
    set_wc(1,2);
    set_large_wc(1,2);
    set_large_thrown_wc(1,10);
    set_thrown_wc(1,6);
    set_thrown_hit_func((:TO,"throw_j":));
	set_prof_type("spear");
	set_weapon_prof("simple");
}

int side_effect(object ob) {
  object *inven;
  int i,j;
  tell_object(ob,"%^RED%^You begin to feel an uncontrollable RAGE!\n");
  tell_room(environment(ob),"%^RED%^"+ob->QCN+" appears to be enraged!\n",ob);
  inven=filter_array(all_living(environment(ob)),"is_non_immortal",FILTERS_D);
  j=sizeof(inven);
  for(i=0;i<j;i++) {
  if(living(inven[i])) {
   if(inven[i] != ob) ob->kill_ob(inven[i],1);
   }
}
  return 1;
}

int throw_j(object ob) {
        tell_object(ob,"%^ORANGE%^"+ETO->QCN+" throws a dart at "+
           "you, and its barbed head sinks into your flesh.");
        tell_room(environment(ob),"%^ORANGE%^"+ETO->QCN+" hurls a "+
           "dart at "+ob->QCN+" and it sinks into "+ob->QO+" flesh.",({ob,TP}));
        if(!"/daemon/saving_throw_d.c"->fort_save(ob,-20))side_effect(ob);
        return 20;
}

