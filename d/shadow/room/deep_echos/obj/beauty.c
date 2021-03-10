//loosely based of of spear of insanity coded by grazzt
#include <std.h>
#include "../deep_echo.h"

inherit "/d/common/obj/weapon/spear_lg";
int uses,xx,yy;
void create() {
    ::create();
    set_name("spear");
    set_id(({"spear","longspear","beauty kills","beauty"}));
    set_short("%^BOLD%^%^BLACK%^Be%^WHITE%^au%^BLACK%^ty"+
	" K%^WHITE%^il%^BLACK%^ls%^RESET%^");
	set_obvious_short("%^BOLD%^%^BLACK%^A ri%^WHITE%^bb%^BLACK%^on"+
    " c%^WHITE%^ov%^BLACK%^er%^WHITE%^ed"+
	" %^BLACK%^sp%^WHITE%^ea%^BLACK%^r%^RESET%^");
    set_long(
"%^BOLD%^%^BLACK%^This weapon seems more like "+
"a fashion statement than a tool used"+
" for battle.  It has a %^WHITE%^sparkling silver"+
" rose%^BLACK%^ for a tip.  The rose "+
"is made flawlessly as if by someone with skill beyond a master "+
"craftsman.  The shaft is completely covered by black"+
" and %^WHITE%^white %^BLACK%^"+
"ribbons.  They %^WHITE%^sp%^BLACK%^ir%^WHITE%^al%^BLACK%^"+
" up and down the shaft with seemingly no end.  "+
"It is impossible to tell what wood the shaft is made of "+
"from because the ribbons fit so perfectly.%^RESET%^");
    set_lore(
"It is said that there was a group of Jarmilans that turned "+
"themselves into weapons.  They were so obsessed with "+
"beauty that they often killed the ugly or poor.  "+
"The reasoning was to create a world that was a beautiful "+
"place to be.  Eventually, the group began to age and "+
"could not stand the thought of growing old.  Most infused "+
"their souls to weapons to carry on their quest through "
"worthy adventurers.");
    set_property("lore difficulty",19);
    set_value(1000);
    set_hit((: TO, "extra_hit":));
    set_wield((: TO, "extra_wield":));
    set_unwield((: TO, "extra_unwield" :));
    set_property("enchantment",3);
    set_heart_beat(1);
    uses = random(75)+10;
}

void sensey(){  //point out ugly ppl in room
  object *ppl, wieldy, loc;
  int i,cha;
  if(!ETO) return;
  if(!EETO) return;
  wieldy = ETO;
  loc = environment(wieldy);
  ppl = all_living(loc);
  for (i = 0; i < sizeof (ppl); i++){
    cha= ppl[i]->query_stats("charisma");
    if( cha < 8)
	  write(ppl[i]->query_cap_name()+"is so ugly"+
	   " the world would be better without them.");
  }
}
void heart_beat() {
    int align,i,dam;
    object owner,env,obj,*inv;
	if(!objectp(ETO)) return;
    env = ETO;
    if(objectp(env) && living(env)) {
        owner = ETO;;
        env = environment(owner);
    }
    if(!(TO->query_wielded())) {
        return;
    } else {
        if( obj = present("corpse",env)) {

            tell_room(EETO,"%^BOLD%^%^WHITE%^"+
              owner->QCN+"'s spear lashes out at the corpse with ribbons.\n"
              "%^BLACK%^The ribbons wrap around the corpse completely.  \n"
              "The corpse spasms as they tighten and shrink"+
			  " into nothing.%^RESET%^");
            if(owner->query_hp() < owner->query_max_hp())
            {
            owner->heal(random(10)+10);
            }
            uses = uses + random(2)+1;
            obj->remove();
            return;
			}

    if((int)environment(TO)->query_hp() < 50 && uses > 5) {
      message("my_action","%^BOLD%^%^MAGENTA%^"+
        "The spear shouts:%^RESET%^ You are bleeding all over me, stop it!"
      ,environment(TO));
	  ETO->heal(random(10)+1);
      dam = random(1)+1;
      uses = uses -5;
      return;}
			else {
            xx = random(500);
            yy = random(19)+1;
            if(xx < 1) {
                if(yy == 1) {
                    tell_object(owner,""
                        "%^BOLD%^%^RED%^The spear tells you:%^RESET%^ "
                        "Look at what you are wearing, is it okay?"
                    );
                }
                if(yy == 2) {
                    tell_object(owner,""
                        "%^BOLD%^%^RED%^The spear tells you:%^RESET%^ "
                        "Are you dressed properly for this?"
                    );
                }
                if(yy == 3) {
                    tell_object(owner,""
                        "%^BOLD%^%^RED%^The spear tells you:%^RESET%^ "
                        "If we see something ugly, destroy it."
                    );
                }
                if(yy == 4) {
                    tell_object(owner,""
                        "%^BOLD%^%^RED%^The spear tells you:%^RESET%^ "
                        "You should always dress in back and white "
                        "that way we can match."
                    );
                }
                if(yy == 5) {
                    tell_object(owner,""
                        "%^BOLD%^%^RED%^The spear tells you:%^RESET%^ "
                        "We must make this world beautiful "
                        "through any means, understand?"
                    );
                }
                if(yy == 6) {
                    tell_object(owner,""
                        "%^BOLD%^%^RED%^The spear tells you:%^RESET%^ "
                        "We hate ugly people "
                        "they should just disappear."
                    );
                }
                if(yy == 7) {
                    tell_object(owner,""
                        "%^BOLD%^%^RED%^The spear tells you:%^RESET%^ "
                        "It is important to keep oneself clean "
                        "...more important to keep ME clean."
                    );
                }
                if(yy == 8) {
                    tell_object(owner,""
                        "%^BOLD%^%^RED%^The spear tells you:%^RESET%^ "
                        "By the power of Sune we will "
                        "recreate this world."
                    );
                }
				if(yy == 11) tell_object(owner,
				  "%^BOLD%^%^RED%^The spear tells you:%^RESET%^"+
				  " If we miss, it is your fault, not mine");
				if(yy == 12) tell_object(owner,
				  "%^BOLD%^%^RED%^The spear tells you:%^RESET%^"+
				  " Our mission is holy, we must not stray.");
				if(yy == 13) tell_object(owner,
				 "%^BOLD%^%^RED%^The spear tells you:%^RESET%^"+
				 " I think we should kill those of neutrality, "+
				 "the passion of both good and evil are "+
				 "a wonderful thing.");



if(yy == 14) tell_object(owner,"You feel the need to adjust your clothing.");
if(yy == 15) tell_object(owner,"Expensive dining sounds good right now.");
if(yy == 16) tell_object(owner,"Images of a ball with dancers fill your mind.");
if(yy == 17) tell_object(owner,"%^BOLD%^%^RED%^The spear tells you:%^RESET%^"+
   " Sometimes love hurts.");
if(yy == 18) tell_object(owner,"%^BOLD%^%^RED%^The spear tells you:%^RESET%^"+
   " What is with your clothing, are you sure it is proper?");
if(yy == 19) tell_object(owner,"%^BOLD%^%^RED%^The spear tells you:%^RESET%^ "+
   " The ugly things of this world are the enemy... we must defeat them.");
                if(yy == 9) {
                    tell_object(owner,""
                        "%^BOLD%^%^RED%^The spear tells you:%^RESET%^ "
                        " If you forsake our mission, I'll kill you.");
                }
                if(yy == 10) {
                    if((int)owner->query_hp() < 50) {
                        tell_object(owner,""
                            "%^BOLD%^%^RED%^The spear tells you:%^RESET%^ "
                            "You should take better care of yourself.  "+
							"There is nothing beautiful about being "+
							"covered in scars.");


                    } else {
                        tell_object(owner,""
                            "%^BOLD%^%^RED%^The spear tells you:%^RESET%^ "
                            "We make a good team just do NOT "+
                            "forget our mission of love and beauty.");
                    }
                }
            }
            return;
        }
    }
}
int extra_hit(object ob) {
    int xx,dam, cha,num;
    object rib, vic;
	if(!ETO) return 1;
	cha = ETO->query_stats("charisma");
    vic = environment(TO)->query_current_attacker();
if(!objectp(ob) || !objectp(vic)) return 1;
    if(uses < 0) {tell_object(ETO,"The spear seems exausted.");
	            return 0;}
    if(random(9) > 3) return 0;

    xx=random(4)+1;
    switch(xx) {

    case 1:
    message("my_action",""
        "%^BOLD%^%^BLACK%^A single ribbon unwinds from your spear and wraps itself around "
        +vic->query_cap_name()+
        " knocking them down."

    ,environment(TO));
    message("other_action",""
      "%^%^BOLD%^%^BLACK%^A single ribbon unwinds from "+ETO->query_cap_name()+
	  "'s spear and wraps itself around "
        +vic->query_cap_name()+
        " knocking them down."
    ,environment(ob),(({environment(TO), ob})));
    message("my_action",
        "%^BOLD%^%^BLACK%^A ribbon wraps around your foot, yanking you to the ground."
     ,ob);
	vic->set_tripped(1,"%^RED%^You try to get up, but the world is spinning.");
    vic->cause_typed_damage(vic,0,roll_dice(1,10),"bludgeoning");
    uses = uses - random(3)+1;

    return 1;

    case 2..3:
	num = cha-14; // extra dam for good cha
    dam = roll_dice(num,8);
    message("my_action",""
        "%^BOLD%^%^BLACK%^You gracefully lunge foward and "
		+num+
        " ri%^WHITE%^bb%^BLACK%^ons impale your target."
    ,environment(TO));
    message("other_action",""+
        "%^BOLD%^%^BLACK%^The spear wielded by "+
        environment(TO)->query_cap_name()+
		" shoots out ri%^WHITE%^bb%^BLACK%^ons that impale "
		+vic->query_name()+"."
    ,environment(ob),(({environment(TO), ob})));

    return dam;


  case 4:

  if (!random(2)) {
    message("my_action",""+
        "%^BOLD%^%^RED%^The spear tells you:%^RESET%^ Looks like you "+
        "need my help.\n"+
        "%^BOLD%^%^BLACK%^A %^WHITE%^s%^BLACK%^w%^WHITE%^"+
		"i%^BLACK%^r%^WHITE%^l%^BLACK%^ of ribbons erupts from the spear.\n"
    ,environment(TO));
    message("other_action",""+
        "%^BOLD%^%^BLACK%^R%^WHITE%^i%^BLACK%^b"+
		"%^WHITE%^b%^BLACK%^o%^WHITE%^n%^BLACK%^s from "
        +environment(TO)->query_cap_name()+
        " spear erupt forth forming a dress. "
    ,environment(ob),(({environment(TO), ob})));
    message("my_action",""
        "%^BOLD%^%^BLACK%^A dress is formed from the spear of "
        +environment(TO)->query_cap_name()+"."
      ,ob);
	    rib =new(MOBS"ribbon");
	    rib ->move(environment(ETO));
		 ETO->add_protector(rib);
		rib ->force_me("kill "+vic->query_name());
        ETO->add_follower(rib);
  }
    uses = uses - 3;
    return dam;

    }
  }

int extra_wield() { // no ugly wielders
    int cha;
    if (!ETO) return 0;
	cha=ETO->query_stats("charisma");
      if(cha >15){
		write(
            "%^CYAN%^As you wield the spear, you begin to think"+
            " highly of yourself.");
        say(
            "%^CYAN%^"+ETOQN+" wields a spear and gets a far "+
            "away look in "+ETO->QP+" eyes\n"+
            "Strangely "+ETO->QS+" looks more noble. ");
		}
	else{
	   say("%^RED%^"+ETOQCN+" holds the spear but jerks violently"+
	     " as ribbons lash out from it, wrapping tightly.");
	   write("%^BOLD%^%^RED%^Your whole body seems to seize and you feel ugly.");
	   TP->set_paralyzed(10,"Your head is pounding");
       TP->set_bound(50,"Ribbons bind you fast.");
	   return 0;
	   }
    return 1;
}
int extra_unwield() {
    object tp;
    tp = ETO;
    if (!tp) return 0;
    tell_object(ETO,
        "%^BOLD%^%^RED%^The spear tells you:%^RESET%^ "+
		"Grrr, you better not forsake our mission.  I'm still watching.");
    return 1;
}
