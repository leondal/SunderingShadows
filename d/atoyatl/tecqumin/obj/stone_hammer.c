//Coded by Lujke

#include <std.h>
#include <daemons.h>
inherit "/d/common/obj/weapon/hammer_lg";

int sunder_track;

void create(){
  ::create();
  set("sunder_bonus", 3);
  set_name("stone warhammer");
  set_id(({ "hammer","war hammer", "warhammer", "stone hammer", "stone warhammer", "stone war hammer"}));
  set_short("%^CYAN%^Tecqumin%^RESET%^ stone %^ORANGE%^warhammer");
  set_obvious_short("massive stone %^ORANGE%^warhammer");
  set_long( (:TO, "long_desc" :) );

  set_value(150000);
  set_wield((:TO, "wield_hammer":));    
  set_unwield((:TO, "unwield_hammer":));          
  set_property("enchantment", 6);
  set_hit((:TO, "hit_stuff":));
  set_weapon_speed(1);
/*
  set_property("quest required", "Drove %^MAGENTA%^The %^BLUE%^U%^MAGENTA%^nf"
      +"%^BLUE%^e%^MAGENTA%^tt%^BLUE%^e%^MAGENTA%^r%^BLUE%^e%^MAGENTA%^d"
      +" %^RESET%^back into the %^BOLD%^%^BLACK%^vo%^RESET%^i%^BOLD%^"
      +"%^BLACK%^d%^RESET%^!");
*/
  set_lore("The mighty warhammer of the %^CYAN%^Tecqumin%^RESET%^ was made"
  +" with their traditional skills of stone, %^ORANGE%^leather%^RESET%^"
  +" and %^ORANGE%^woodworking%^RESET%^, and infused with the strength of"
  +" the jungle Gods they worshipped. It is thought to enhance the senses"
  +" of the wielder and make them more aware of opportunities to damage their"
  +" opponents' armour and defences");
  set_property("lore difficulty", 35);
  set_item_bonus("attack bonus",3);
  set_item_bonus("damage bonus",3);
  set_item_bonus("perception",2);
  sunder_track = 0;
}

string long_desc(){
  string desc;
  desc = "A massive stone war hammer, with a thick %^ORANGE%^hardwood handle%^RESET%^."
  +" The heavy, tapered stone head is strapped to the handle with %^ORANGE%^leather"
  +" straps%^RESET%^. Despite its size and weight, the hammer is exceptionally well"
  +" balanced. The blunt face of the hammer head is a fearsome%^BOLD%^%^BLACK%^"
  +" bludgeoning%^RESET%^ tool, while the point at the other end would be highly"
  +" suitable for winkling an opponent out of their armour. The handle is carved with"
  +" numerous symbolic representations of fierce tusked %^ORANGE%^warthogs%^RESET%^.";
  if (FEATS_D->can_use_feat(ETO, "sunder")){
    desc += "\n%^BOLD%^%^YELLOW%^This weapon would increase the benefit you could get"
      +" on a successful use of the sunder feat.";
  } else {
    desc += "\n%^BOLD%^%^YELLOW%^This weapon would allow you to use the sunder feat";
  }
  return desc;

}

int hit_stuff(object ob)
{ 
  if (!objectp(TO)||!objectp(ETO)||!objectp(ob)){return 0;}
  if (random(17)<15)
  {
    return 0;
  }
  switch(random(10))
  {
  case 0..2:
    tell_object(ETO, "%^BOLD%^%^BLUE%^You slam the head of the hammer into "
                    + ob->QCN + "'s%^RESET%^%^BOLD%^%^BLUE%^ face"
                    +"!%^RESET%^");
    tell_object(ob, ETO->QCN + " slams the head of " + ETO->QP + "%^RESET%^ "
                    + query_short() + "%^RESET%^ into your face!"  );
    tell_room(EETO, ETO->QCN + "%^RESET%^ slams the head of " + ETO->QP 
     + " %^RESET%^" + query_short() + " %^RESET%^into " + ob->QCN 
     + "'s%^RESET%^ face!",({ob,ETO}) );
    return 10 + random(10);
    break;
  case 4..5:
    tell_object(ETO, "%^BOLD%^%^BLUE%^You feint high, then slam the head"
      +" of the warhammer onto " + ob->QCN + "'s%^RESET%^ foot, making " 
      + ob->QO + "%^BOLD%^%^BLUE%^ fall!");
    tell_object(ob, ETO->QCN + " %^BOLD%^%^BLUE%^feints high, then slams"
      +" the head of the warhammer onto your foot! Understandably, you"
      +" fall to the ground in agony.");
    tell_room(EETO,  ETO->QCN + " %^BOLD%^%^BLUE%^feints high, then slams"
      +" the head of the warhammer onto " + ob->QCN + "'s%^RESET%^ foot,"
      +" making " + ob->QO + "%^BOLD%^%^BLUE%^ fall!", ({ob,ETO}) );
    return (5 + random(5));
    ob->set_tripped("%^BOLD%^%^BLUE%^You are struggling to stand on your"
      +" injured foot!");
    break;
  case 6..9:
    tell_object(ETO, "%^YELLOW%^You hew powerfully into "
                   + (string)ob->query_cap_name() + "'s %^YELLOW%^head"
                   +" with a devasting overhand blow with your " 
                   + query_short()+ "%^YELLOW%^!");
    tell_object(ob, "%^YELLOW%^" + (string)ETO->query_cap_name()
                   +" %^YELLOW%^hews powerfully into  your head with a"
                   +" devasting overhand blow with "
                   + (string)ETO->QP + " " + query_short() +"%^YELLOW%^!");
    tell_room(EETO, "%^YELLOW%^" + (string)ETO->query_cap_name()
                   +" %^YELLOW%^hews powerfully into "
                   + (string)ob->query_cap_name() + "'s %^YELLOW%^head"
                   +" with a devasting overhand blow with "
                   + (string)ETO->QP + " " + query_short() + "%^YELLOW%^!",
                    ({ob,ETO}) );
   return 10+ random(10);
  }
  return 0;
}

void init(){
  ::init();
  if (!objectp(ETO) || !interactive(ETO) || member_array("sunder",(string*)ETO->query_temporary_feats()) == -1){
    sunder_track = 0;
  }
}


int wield_hammer(){
  return 1;
  if (!objectp(TO)||!objectp(ETO)||!objectp(EETO)){tell_room(find_object_or_load("/realms/lujke/workshop"), "ERROR - can't read"); return 0;}

  if (FEATS_D->can_use_feat(TP, "sunder")){
    tell_object(ETO, "As you heft the mighty hammer, you feel increased"
      +" confidence in your ability to sunder your opponents' armour");
  } else {
    tell_object(ETO, "As you heft the mighty hammer, you realise that you"
      +" would be able to %^BOLD%^%^YELLOW%^sunder %^RESET%^your opponents'"
      +" armour");
    if(member_array("sunder",(string*)ETO->query_temporary_feats()) == -1) {
      ETO->add_temporary_feat("sunder");
      sunder_track = 1;
    }
  }

  tell_room(EETO, (string)ETO->query_cap_name() + " hefts " 
                  +(string)ETO->QP + " mighty stone %^ORANGE%^warhammer%^RESET%^.",ETO );
}

int unwield_hammer(){
  if (sunder_track==1){
    ETO->remove_temporary_feat("sunder");
    sunder_track = 0;
  }
  return 1;
}
