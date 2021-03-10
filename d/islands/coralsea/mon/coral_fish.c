#include <std.h>
#include "../defs.h"
#include <daemons.h>
inherit WEAPONLESS;


// Coral Sea Area - Created January 2009 by Ari

object ob;

void create(){
        ::create();
        set_body_type("snake");
        set_alignment(5);
       set_hd(20,3);
        set_stats("strength",16);
        set_stats("dexterity",24);
        set_stats("intelligence",8);
        set_stats("wisdom",8);
        set("aggressive",0);
        set_size(1);
        set_property("swarm",1);
        set_overall_ac(0);
        set_hp(100+random(50));
        set_exp(300);
        set_max_level(20);
        set_name("fish");
        set_property("water breather",1);

        set_attacks_num(2);
        set_base_damage_type("pierce");
        set_damage(1,8);
        set_funcs(({"bite"}));
        set_class("fighter");
        set_func_chance(25);

    force_me("message in swims in.");
    force_me("message out swims $D.");

        switch(random(60)){
                case 0..10:
                set_id(({"lion fish","lionfish","striped lionfish","fish","fishrinn"}));
                set_gender("neuter");
                set_race("fish");
                set_short("A large striped Lionfish");  
                set_long("With its white body decorated with black and red "+
                        "stripes, this fish is stunningly beautiful.  Large, "+
                        "fan-like fins extend to either side of its  body, "+
                        "while a similar spine of webbed spines grace its "+
                        "backs.  This gives the Lionfish an angelic appearance "+
                        "that is only enhanced by their swift, graceful "+
                        "movements.  Dark eyes blend into their coloring over "+
                        "wide mouths, while a feather like tail sways back and "+
                        "forth behind this dangerous fish.");
                break;

                case 11..20:
                set_name("School of Fangbennies");
                set_id(({"bennies","school","fish","fangbennies","fishrinn"}));
                set_gender("neuter");
                set_race("fish");
                set_short("A School of Fangbennies");  
                set_long("Only a few inches in length, these small white "+
                        "fish with a dark blue dorsal fin dart about in small "+
                        "schools, weaving through the water in quick, darting "+
                        "bursts.  While harmless enough looking with small "+
                        "fins and a wide paddle like tail, it is when they "+
                        "open their mouths and reveal small, sharp fangs in "+
                        "the front of their jaws that makes them a danger.");
                break;

                case 21..30:
                set_id(({"school","fish","soldierfish","soldier fish","fishrinn"}));
                set_gender("neuter");
                set_race("fish");
                set_short("A School of Soldierfish");  
                set_long("Bright red, its difficult to miss this school of "+
                        "large eyed fish.  Long, splayed tails drive them "+
                        "through the water while smaller pectoral fins guide "+
                        "them in and out of the coral.  Large black eyes "+
                        "glitter from within a circle of silver scales, while "+
                        "other dark markings along the body give them "+
                        "variations.  A spiky dorsal fin in silver and red "+
                        "rises and falls as the little fish dart about.");
                break;

                case 31..40:
                set_id(({"stingray","ray","fish","fishrinn"}));
                set_gender("neuter");
                set_race("fish");
                set_short("A gliding stingray");  
                set_long("The wide, flat body of the stingray glides "+
                        "easily through the water with little more then a "+
                        "swish of its long, slender tail.  Large eyes rest "+
                        "upon the sandy-brown body, able to look upward as "+
                        "well as forward.  Brown and black spots cover the "+
                        "upper surface while a muted gray colors the underside "+
                        "and hides the wide mouth.");
                break;

                case 41..50:
                set_id(({"fish","leaffish","leaf fish","seaweed","fishrinn"}));
                set_gender("neuter");
                set_race("fish");
                set_short("A floating piece of seaweed");  
                set_long("What looks at first like a leaf odd kelp drifting "+
                        "by reveals itself to actually be a leaf.  Brownish "+
                        "green, the creatures body is narrow and long with a "+
                        "long wavy dorsal fin that gives it the leaf like "+
                        "appearance.  Starburst, yellow eyes are the only thing "+
                        "that causes it to stand out amongst the leaves, though "+
                        "the pectoral fins along the bottom of the fish do "+
                        "occasionally move.");
                break;

                case 51..59:
                set_id(({"rabbitfish","fish","rabbit fish","fishrinn"}));
                set_gender("neuter");
                set_race("fish");
                set_short("A colorful Rabbitfish");  
                set_long("A large black stripe beginning at the tip of "+
                        "its snout and traveling back along the upper ridge of "+
                        "its body to end at a narrow, spiny dorsalfin, causes "+
                        "this white bodied fish to stand out.  Yellow "+
                        "highlights dust its tail and lower fins, while large "+
                        "black spots on either side of the fish make it seem to "+
                        "be watching its surroundings constantly.");
                break;

       return 1;
        }
}

int bite(object targ){
if(!objectp(TO)){return 0;}
if(!objectp(targ)){return 0;}

if(!"daemon/saving_d"->saving_throw(targ,"paralyzation_poison_death")) {
                tell_object(targ,"You feel the fish's bite "+
                                        "burn through your veins.");
                tell_room(ETO,""+targ->query_cap_name()+""+
                                        " looks worried after the fish bites them.",targ);
                targ->add_poisoning(15);
                return 1;
        }
        else {
                tell_object(targ,"You shudder at the fish's "+
                                        "bite!");
                return 1;
        }
}

void heart_beat(){
        ::heart_beat();
                if(!objectp(TO)){return;}
                if(!objectp(ETO)){return;}
                if(base_name(ETO)==ROOMS"coral_b2" || 
                        base_name(ETO)==ROOMS"coral_b5" || 
                        base_name(ETO)==ROOMS"coral_s4" || 
                        base_name(ETO)==ROOMS"coral_s8" || 
                        base_name(ETO)==ROOMS"coral_s10" || 
                        base_name(ETO)==ROOMS"coral_s2"){
                tell_room(ETO,"The fish startle, "+
                        "and swim away.");
                TO->move("/d/shadowgate/void");
                TO->remove();
        }
}
