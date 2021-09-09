//updated base damage - Circe 4/29/04
#include <std.h>

inherit "/d/common/obj/weapon/knife.c";
int unwield_knife();
int wield_knife();
int hit_stuff(object ob);
void set_unwield_state();


void create(){
  ::create();
  set_id(({"knife","ethereal knife","amber knife","weapon", "shard",
           "amber shard", "amber"}));
  set_short("%^ORANGE%^amb%^YELLOW%^e%^RESET%^%^ORANGE%^r"
           +"%^RESET%^ shard");
  set_unwield_state();
  set_wield((:TO, "wield_knife":));
  set_unwield((:TO, "unwield_knife":));
  while ((int)TO->query_property("enchantment") != 7) {
      TO->remove_property("enchantment");
      TO->set_property("enchantment", 7);
  }
  set_item_bonus("spell damage resistance", 30);
  set_hit((:TO, "hit_stuff":));

}
string query_short(){
  int flag;
  if(objectp(ETO)){
    if(!interactive(ETO)||
     (interactive(ETO)&& member_array(TO,ETO->query_wielded(),flag)==-1)){
      set_unwield_state();
    }
  }
  return ::query_short();
}

int hit_stuff(object ob)
{
  int dam;
  if (!objectp(TO)||!objectp(ETO)||!objectp(ob)){return 0;}
  if (random(9)<5)
  {
    return 0;
  }
  switch(random(9))
  {
  case 0..4:
    tell_object(ETO, "%^ORANGE%^Your " + query_name() + "%^RESET%^"
                    +"%^CYAN%^ fl%^BOLD%^%^WHITE%^i%^RESET%^%^CYAN%^ck"
                    +"%^RESET%^e%^CYAN%^rs%^ORANGE%^ and phases before"
                    +" stabbing through " + (string)ob->QCN
                    +"'s %^RESET%^%^ORANGE%^defenses!");
   tell_object(ob, (string)ETO->QCN + "'s %^ORANGE%^" + query_name()
                    +"%^RESET%^%^CYAN%^ fl%^BOLD%^%^WHITE%^i%^RESET%^"
                    +"%^CYAN%^ck%^RESET%^e%^CYAN%^rs%^ORANGE%^ and phases"
                    +" before stabbing through your defenses!");
    tell_room(EETO, (string)ETO->QCN + "'s %^ORANGE%^" + query_name()
                    +"%^RESET%^%^CYAN%^ fl%^BOLD%^%^WHITE%^i%^RESET%^"
                    +"%^CYAN%^ck%^RESET%^e%^CYAN%^rs%^ORANGE%^ and phases"
                    +" before stabbing through " + (string)ob->QCN
                    +" %^RESET%^%^ORANGE%^defenses!",({ob,ETO}));
    set_property("magic",1);
    ob->cause_typed_damage(ob, ob->return_target_limb(), roll_dice(6, 10), "piercing");
    remove_property("magic");
    break;
    return (0);
  case 5..8:
    tell_object(ETO, "The " + query_name() + " %^RESET%^%^CYAN%^"
                    +" disappears%^RESET%^ from your hand as you strike,"
                    +" then re-appears, embedded deeply in "
                    + (string)ob->QCN + "'s %^RESET%^flesh!");
    tell_object(ob, (string)ETO->QCN +"'s %^RESET%^" + query_name()
                   +" %^CYAN%^disappears%^RESET%^ from " + (string)ETO->QP
                   +" hand as " + (string)ETO->QS + " strikes, only to"
                   +" re-appear, embedded deeply in your flesh!");
    tell_room(EETO, (string)ETO->QCN +"'s %^RESET%^" + query_name()
                   +" %^CYAN%^disappears%^RESET%^ from " + (string)ETO->QP
                   +" hand as " + (string)ETO->QS + " strikes, only to"
                   +" re-appear, embedded deeply in " + (string)ob->QCN
                  +"'s  flesh!", ({ob,ETO}) );
    set_property("magic",1);
    ob->cause_typed_damage(ob, ob->return_target_limb(), roll_dice(6, 10) + 10, "piercing");
    remove_property("magic");
    break;
    return (0);
  }
}


int wield_knife()
{
  if (!objectp(TO)||!objectp(ETO)){return 0;}
  tell_object(ETO, "As you pick up the shard of %^ORANGE%^amb%^YELLOW%^e"
                  +"%^RESET%^%^ORANGE%^r%^RESET%^, a %^CYAN%^chill"
                  +" %^RESET%^runs through your hand and along your"
                  +" forearm. A %^CYAN%^fl%^RESET%^i%^CYAN%^ck%^RESET%^e"
                  +"%^CYAN%^r%^RESET%^i%^CYAN%^ng %^BOLD%^%^WHITE%^gh"
                  +"%^RESET%^o%^BOLD%^%^WHITE%^stly %^RESET%^blade"
                  +" springs forth from what you now realise is the"
                  +" handle of an ancient %^ORANGE%^amb%^YELLOW%^e"
                  +"%^RESET%^%^ORANGE%^r %^RESET%^ knife.");
  if (objectp(EETO)){
    tell_room(EETO,  "As " + (string)ETO->QCN + " %^RESET%^ picks up the"
                  +" shard of %^ORANGE%^amb%^YELLOW%^e"
                  +"%^RESET%^%^ORANGE%^r%^RESET%^, " + (string)ETO->QS
                  +" shivers. A %^CYAN%^fl%^RESET%^i%^CYAN%^ck%^RESET%^e"
                  +"%^CYAN%^r%^RESET%^i%^CYAN%^ng %^BOLD%^%^WHITE%^gh"
                  +"%^RESET%^o%^BOLD%^%^WHITE%^stly %^RESET%^blade"
                  +" springs forth from what you now realise is the"
                  +" handle of an ancient %^ORANGE%^amb%^YELLOW%^e"
                  +"%^RESET%^%^ORANGE%^r %^RESET%^knife.",ETO);
  }
  set_name("ghostly amber knife");
  set_obvious_short("%^RESET%^A %^CYAN%^fl%^RESET%^i%^CYAN%^ck%^RESET%^e"
                   +"%^CYAN%^r%^RESET%^i%^CYAN%^ng%^RESET%^ blade"
                   +" emerging from an ancient %^ORANGE%^amb%^YELLOW%^e"
                   +"%^ORANGE%^r %^RESET%^handle");
  set_long("A %^BOLD%^%^WHITE%^gh%^RESET%^o%^BOLD%^%^WHITE%^stly%^RESET%^"
          +" knife, with a %^CYAN%^gl%^BOLD%^%^CYAN%^o%^RESET%^%^CYAN%^w"
          +"%^BOLD%^%^CYAN%^i%^RESET%^%^CYAN%^ng tr%^RESET%^a%^CYAN%^nsl"
          +"%^RESET%^u%^CYAN%^c%^RESET%^e%^CYAN%^nt%^RESET%^ fl%^BOLD%^"
          +"%^WHITE%^i%^RESET%^ck%^CYAN%^e%^RESET%^r%^BOLD%^%^WHITE%^i"
          +"%^RESET%^ng blade and an %^ORANGE%^amb%^YELLOW%^e%^RESET%^"
          +"%^ORANGE%^r %^RESET%^handle.");
  return 1;
}

void __ActuallyUnwield() {
   ::__ActuallyUnwield();
  set_unwield_state();
}

int unwield_knife()
{
  if (!objectp(TO)||!objectp(ETO)||!objectp(EETO)){return 0;}
  tell_object(ETO, "As you release the %^ORANGE%^amb%^YELLOW%^e%^RESET%^"
                  +"%^ORANGE%^r h%^YELLOW%^a%^RESET%^%^ORANGE%^ndl"
                  +"%^YELLOW%^e%^RESET%^, the %^CYAN%^fl%^RESET%^i"
                  +"%^CYAN%^ck%^RESET%^e%^CYAN%^r%^RESET%^i%^CYAN%^ng"
                  +"%^RESET%^ blade disappears, leaving you once more"
                  +" with just a shard of %^ORANGE%^amb%^YELLOW%^e"
                  +"%^RESET%^%^ORANGE%^r%^RESET%^");
  tell_room(EETO, "As "+(string)ETO->QCN+" releases the %^ORANGE%^amb"
                 +"%^YELLOW%^e%^RESET%^%^ORANGE%^r h%^YELLOW%^a%^RESET%^"
                 +"%^ORANGE%^ndl%^YELLOW%^e%^RESET%^, the %^CYAN%^fl"
                 +"%^RESET%^i%^CYAN%^ck%^RESET%^e%^CYAN%^r%^RESET%^i"
                 +"%^CYAN%^ng%^RESET%^ blade disappears, leaving "
                 + (string)ETO->QO +" once more with just a shard of"
                 +" %^ORANGE%^amb%^YELLOW%^e%^RESET%^%^ORANGE%^r"
                 +"%^RESET%^",ETO);
  set_unwield_state();
  return 1;
}

void set_unwield_state()
{
  set_name("%^RESET%^shard of %^ORANGE%^amb%^YELLOW%^e%^RESET%^"
          +"%^ORANGE%^r%^RESET%^");
  set_obvious_short("%^RESET%^shard of %^ORANGE%^amb%^YELLOW%^e%^RESET%^"
                   +"%^ORANGE%^r%^RESET%^");
  set_long("A small shard of %^ORANGE%^amb%^YELLOW%^e%^RESET%^%^ORANGE%^r"
          +" %^RESET%^that looks like it has been worked at some time in"
          +" the past. It is a cylindrical shape, with a rough crossbar,"
          +" like the handle of a small knife.");
}

int query_ethereal(){
  return 1;
}
