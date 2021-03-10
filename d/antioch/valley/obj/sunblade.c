//Changed over to longsword inherit - Added new desc
//Cythera 9/05
#include <std.h>
#include "../valley.h"
inherit "/d/common/obj/weapon/longsword.c";

void create()
{
	::create();
	set_name("%^YELLOW%^S%^RESET%^%^ORANGE%^u%^YELLOW%^n%^RESET%^"+
		"%^ORANGE%^b%^YELLOW%^l%^RESET%^%^ORANGE%^a%^YELLOW%^d"+
		"%^RESET%^%^ORANGE%^e%^RESET%^");
	set_id(({"longsword","sword","sun sword","blade","sunblade","sun blade"}));
	set_short("%^YELLOW%^S%^RESET%^%^ORANGE%^u%^YELLOW%^n%^RESET%^"+
		"%^ORANGE%^b%^YELLOW%^l%^RESET%^%^ORANGE%^a%^YELLOW%^d"+
		"%^RESET%^%^ORANGE%^e%^RESET%^");
   set_obvious_short("%^YELLOW%^A yellow long sword%^RESET%^");
	set_long("%^ORANGE%^This long sword has been forged from a strong alloy "+
	"that has a %^YELLOW%^yellow tinge%^RESET%^%^ORANGE%^ to it."+
	" The blade has been forged with such skill that the blade is quite"+
	" light but exceptionally strong and perfectly balanced. A large"+
	" %^RED%^ruby%^ORANGE%^, with a %^YELLOW%^sunburst%^RESET%^%^ORANGE%^"+
	" engraved into its face in bass-relief, which reflects fragmented"+
	"%^BOLD%^%^WHITE%^ light%^RESET%^%^ORANGE%^ with an odd pulse has "+
	"been set into the %^YELLOW%^golden hilt%^RESET%^%^ORANGE%^. "+
	"There are four smaller %^RED%^rubies%^ORANGE%^ that have been set "+
	"into the %^YELLOW%^gold%^RESET%^%^ORANGE%^ crosspiece over the top"+
	" of the hilt that flash brightly in the light.%^RESET%^");
   set("lore","This sword was once used by the dedicated followers of "+
	"Lathander who forged several of these weapons in order to combat"+
	" a large force of undead creatures that threatened to crush his "+
	"people. The swords were known as Sunblades, for they harness the "+
	"power of the sun in order to fight evil. The strange mabion metal"+
	" they are made of makes them much faster than normal weapons, and"+
	" thus doubly effective against the normally slower undead monsters."+
   	" From there other faiths started to adopt the sunblade in their "+
	"battles with the undead.");
	set_property("lore",14);
        set_property("enchantment",(random(2))+3);
	set_value(1600);
	set_hit((:TO,"hitme":));
	set_wield((:TO,"wieldme":));
	set_unwield((:TO,"removeme":));
}

int wieldme()
{
	int align;

	align = ETO->query_alignment();
        if(ETO->query_lowest_level() < 15) {
		tell_object(ETO,"You must be of greater stature before"+
		" the blade will let you wield it.");
		return 0;
	}
	switch(align) {
		case 1: case 4: case 7:
			tell_object(ETO,"%^YELLOW%^The %^RED%^ruby%^YELLOW%^"+
			" on the hilt flashes in approval.");
			tell_room(environment(ETO),"%^BOLD%^The %^RED%^ruby"+
			"%^WHITE%^ on the hilt of "+ETO->query_cap_name()+"'s"+
			" sword flashes briefly.",ETO);
			set_item_bonus("magic resistance",1);
            	set_item_bonus("attack bonus",2);
            	set_item_bonus("damage bonus",2);
			//set_ac(0);
         ETO->set_property("good item",1);
			return 1;

		case 2: case 5: case 8:
			tell_object(ETO,"%^YELLOW%^The smaller %^RED%^rubies"+
			"%^YELLOW%^ on the hilt glow faintly.");
			tell_room(environment(ETO),"%^BOLD%^The smaller %^RED%^"+
			"rubies%^WHITE%^ on the hilt of "+ETO->query_cap_name()+"'s"+
			" sword glow faintly.",ETO);
			set_item_bonus("magic resistance",1);
            	set_item_bonus("attack bonus",0);
            	set_item_bonus("damage bonus",0);
			//set_ac(0);
         ETO->set_property("good item",1);
			return 1;

		case 3: case 6: case 9:
			tell_object(ETO,"%^YELLOW%^All the %^RED%^rubies%^YELLOW%^"+
			" on the hilt flash angrily as you wield the sacred"+
			" Sunblade.");
			tell_room(environment(ETO),"%^BOLD%^The %^RED%^rubies"+
			"%^WHITE%^ on the hilt of "+ETO->query_cap_name()+"'s"+
			" sword flash briefly.",ETO);
			set_item_bonus("magic resistance",-1);
            	set_item_bonus("attack bonus",0);
            	set_item_bonus("damage bonus",0);
         ETO->set_property("good item",1);
			return 1;

		default:
			tell_object(ETO,"Oh yeah, you've got some major problems"+
			" here pal.");
			return 0;
	}
}

int removeme()
{
	int align;

	align = ETO->query_alignment();
	switch(align) {
		case 1: case 4: case 7:
			tell_object(ETO,"%^YELLOW%^You feel less protected as"+
			" you release your grip on the sword.");
                        ETO->set_property("good item",-1);
			return 1;

		case 2: case 5: case 8:
			tell_object(ETO,"%^YELLOW%^The small %^RED%^rubies%^YELLOW%^"+
			" in the hilt of the sword glow faintly as you release"+
			" it.");
			tell_room(environment(ETO),"%^BOLD%^The small %^RED%^rubies"+
			"%^WHITE%^ in the hilt of "+ETO->query_cap_name()+"'s"+
			" sword glow faintly.",ETO);
                        ETO->set_property("good item",-1);
			return 1;

		case 3: case 6: case 9:
			tell_object(ETO,"%^YELLOW%^The sword seems very happy"+
			" to be rid of you.");
                        ETO->set_property("good item",-1);
			return 1;

		default:
			tell_object(ETO,"Well, well, well, how'd you manage"+
			" to get yourself into this mess?");
			return 0;
	}
}

int hitme(object targ)
{
	int align, talign;

	if(!objectp(targ)) return 1;

	align = ETO->query_alignment();
	talign = targ->query_alignment();

	switch(align) 
    {
		case 1: case 4: case 7:
            {
			    if(!random(50)) 
                {
				    tell_object(ETO,"%^RED%^The %^BOLD%^ruby%^RESET%^%^RED%^"+
				        " on the hilt begins to glow, the red light expands"+
				        " outwards to cover your body. You can almost sense"+
				        " a benign presence, then the light is gone and"+
				        " you feel rested.");
				    tell_room(environment(ETO),"%^RED%^The %^BOLD%^ruby%^RESET%^%^RED%^"+
				        " on "+ETO->query_cap_name()+"'s hilt begins to"+
				        " glow, the red light expands to bathe "+ETO->query_objective()+""+
				        " in it and then fades.",ETO);
				    ETO->do_damage("torso",-(random(6)+10));
				    return 1;
			    }
			    else 
                {
			        switch(talign) 
                    {
				    case 1: case 4: case 7:
                        {
					        if(!random(25)) 
                            {
						        tell_object(ETO,"%^YELLOW%^The %^RED%^rubies"+
						            "%^YELLOW%^ on the Sunblade flare angrily as you"+
						            " hit "+targ->query_cap_name()+".");
						        tell_object(targ,"%^YELLOW%^The %^RED%^rubies"+
						            "%^YELLOW%^ on "+ETO->query_cap_name()+"'s"+
						            " sword flare angrily as "+ETO->query_subjective()+""+
						            " hits you.");
						        tell_room(environment(ETO),"%^YELLOW%^The"+
						            " %^RED%^rubies%^YELLOW%^ on "+ETO->query_cap_name()+"'s"+
						            " sword flare angrily as "+ETO->query_subjective()+""+
						            " hits "+targ->query_cap_name()+".",({ETO,targ}));
						        ETO->do_damage("torso",random(3)+2);
						        return 1;
					        }
					        break;
                        }
				    case 2: case 5: case 8:
                        {
					        if(!random(15)) 
                            {
						        tell_object(ETO,"%^BOLD%^%^RED%^The edges of"+
						            " the Sunblade flicker to life with a red"+
						            " flame, burning "+targ->query_cap_name()+".");
						        tell_object(targ,"%^BOLD%^%^RED%^The edges of"+
						            " "+ETO->query_cap_name()+"'s sword burst"+
						            " into red flames that burn you as the sword"+
						            " strikes a blow.");
						        tell_room(environment(ETO),"%^BOLD%^%^RED%^The"+
						            " edges of "+ETO->query_cap_name()+"'s sword"+
						            " burst into red flames that burn "+targ->query_cap_name()+""+
						            " as the blade strikes "+targ->query_objective()+".",({ETO,targ}));
						        targ->do_damage("torso",random(6)+4);
						        return 1;
					        }
					        if(!random(10)) 
                            {
						        tell_object(ETO,"%^BOLD%^The sword seems to"+
						            " move even faster than you expected and you"+
						            " are able to guide it between a section of"+
						            " "+targ->query_cap_name()+"'s armor for a"+
						            " brutal hit.");
						        tell_object(targ,"%^BOLD%^"+ETO->query_cap_name()+"'s"+
						            " sword moves faster than possible, streaking"+
						            " in to score a brutal hit on a weak section"+
						            " where your armor joins together.");
						        tell_room(environment(ETO),"%^BOLD%^"+ETO->query_cap_name()+"'s"+
						            " sword moves impossibly fast, striking where"+
						            " two sections of armor join together for a"+
						            " brutal hit.",({ETO,targ}));
                                ETO->execute_attack();
						        targ->do_damage("torso",random(8)+5);                                
						        return 1;
					        }
					    break;
                        }

				    case 3: case 6: case 9:
                        {
					        if(!random(25)) 
                            {
                                //if(!"daemon/saving_d"->saving_throw(targ,"spell")) 
                                if(!"/daemon/saving_throw_d"->reflex_save(targ,(-1*(int)ETO->query_base_character_level())))
                                {
							        tell_object(ETO,"%^BOLD%^Your sword flashes"+
							            " with a bright light, blinding "+targ->query_cap_name()+".");
							        tell_object(targ,"%^BOLD%^"+ETO->query_cap_name()+"'s"+
							            " sword flashes with a bright light,"+
							            " blinding you!");
							        tell_room(environment(ETO),"%^BOLD%^"+ETO->query_cap_name()+"'s"+
							            " sword flashes with a bright light,"+
							            " blinding "+targ->query_cap_name()+".",({ETO,targ}));							        
                                    //targ->set_blind(1);
                                    targ->set_temporary_blinded(roll_dice(3,6));
							        return 1;
						        }
						        else 
                                {
							        tell_object(ETO,"%^BOLD%^Your sword"+
							            " flashes with a blinding light, but"+
							            " "+targ->query_cap_name()+" manages to"+
							            " resist the sword's power.");
							        tell_object(targ,"%^BOLD%^"+ETO->query_cap_name()+"'s"+
							            " sword flashes with a blinding light, but"+
							            " you manage to resist its spell, but the light still burns your soul!");
							        tell_room(environment(ETO),"%^BOLD%^"+ETO->query_cap_name()+"'s"+
							            " sword flashes with a blinding light.",({ETO,targ}));
                                    targ->do_damage("torso",roll_dice(1,8)+10);
							        return 1;
						        }
					        }

                            if(!random(10)) 
                            {
						        tell_object(ETO,"%^BOLD%^The sword seems to"+
						            " move even faster than you expected and you"+
						            " are able to guide it between a section of"+
						            " "+targ->query_cap_name()+"'s armor for a"+
						            " brutal hit.");
						        tell_object(targ,"%^BOLD%^"+ETO->query_cap_name()+"'s"+
						            " sword moves faster than possible, streaking"+
						            " in to score a brutal hit on a weak section"+
						            " where your armor joins together.");
						        tell_room(environment(ETO),"%^BOLD%^"+ETO->query_cap_name()+"'s"+
						            " sword moves impossibly fast, striking where"+
						            " two sections of armor join together for a"+
						            " brutal hit.",({ETO,targ}));
                                ETO->execute_attack();
						        targ->do_damage("torso",random(8)+5);                                
						        return 1;
					        }
					    
                            if(!random(8)) 
                            {
						        tell_object(ETO,"%^YELLOW%^The Sunblade begins"+
						            " to vibrate in your hands, it points towards"+
						            " "+targ->query_cap_name()+" and a ray of"+
						            " golden fire shoots forth from the tip and"+
						            " engulfs "+targ->query_objective()+"!");
						        tell_object(targ,"%^YELLOW%^"+ETO->query_cap_name()+""+
						            " points "+ETO->query_possessive()+" Sunblade"+
						            " at you and a golden flame erupts from the"+
						            " tip of the sword, shooting forth to engulf"+
						            " you!\n\nThe golden fire burns like nothing"+
						            " you have ever felt before!");
						        tell_room(environment(ETO),"%^YELLOW%^"+ETO->query_cap_name()+""+
						            " points "+ETO->query_possessive()+" Sunblade"+
						            " at "+targ->query_cap_name()+" and a golden"+
						            " flame springs forth from the tip of the sword"+
						            " to engulf "+targ->query_objective()+".",({ETO,targ}));
						        targ->do_damage("torso",random(10)+6);
                                targ->set_paralyzed(roll_dice(3,6),"%^YELLOW%^The %^MAGENTA%^sunfire%^YELLOW%^ "
                                    "is burning you alive!%^RESET%^");
						        return 1;
                            }
					    break;
                        }
                }
			break;
            }
		}

		case 2: case 5: case 8:
            {
			    switch(talign) 
                {
				    case 1: case 4: case 7:
                        {
					        if(!random(15)) 
                            {
						        tell_object(ETO,"%^BOLD%^%^RED%^The rubies"+
						            " flare angrily at your attack on "+targ->query_cap_name()+""+
						            " and the hilt burns your hand!");
						        tell_room(environment(ETO),"%^BOLD%^%^RED%^The rubies"+
						            " on "+ETO->query_cap_name()+"'s sword flare"+
						            " brightly and "+ETO->query_subjective()+""+
						            " cries out in pain.",ETO);
						        ETO->do_damage("torso",random(8)+2);
						        return 1;
					        }
					    break;
				    }

				    case 2: case 5: case 8: case 3: case 6: case 9:
                        {
					        if(!random(25)) 
                            {
						        tell_object(ETO,"%^YELLOW%^You slice your sword deeply"+
						            " into "+targ->query_cap_name()+" and the"+
						            " blade glows yellow, burning "+targ->query_objective()+".");
						        tell_object(targ,"%^YELLOW%^"+ETO->query_cap_name()+""+
						            " slices "+ETO->query_possessive()+" sword into"+
						            " you and the blade begins to glow yellow,"+
						            " burning your flesh!");
						        tell_room(environment(ETO),"%^YELLOW%^"+ETO->query_cap_name()+""+
						            " slices "+ETO->query_possessive()+" sword into"+
						            " "+targ->query_cap_name()+" and the blade"+
						            " glows yellow, burning "+targ->query_objective()+"!",({ETO,targ}));
						        targ->do_damage("torso",random(10)+3);
						        return 1;
					        }
					        if(!random(40)) 
                            {
						        tell_object(ETO,"%^BOLD%^The sword guides"+
						            " your hand in an intricate pattern, leaving"+
						            " lines of light in the air.\n"+targ->query_cap_name()+""+
						            " is dazzled by the pattern and you lunge"+
						            " hard at "+targ->query_objective()+", catching"+
						            " "+targ->query_objective()+" off guard.");
						        tell_object(targ,"%^BOLD%^"+ETO->query_cap_name()+""+
						            " weaves "+ETO->query_possessive()+" sword in"+
						            " an intricate pattern, light hangs in the"+
						            " air where "+ETO->query_possessive()+" blade"+
						            " was. The pattern is enchanting.\n"+
						            "%^YELLOW%^"+ETO->query_cap_name()+" lunges at you"+
						            " while you're off guard, dealing you a harsh"+
						            " blow!");
						        tell_room(environment(ETO),"%^BOLD%^"+ETO->query_cap_name()+""+
						            " weaves "+ETO->query_possessive()+" sword"+
						            " in an intricate pattern, leaving a trail of"+
						            " light behind. The pattern is breath taking.\n"+
						            "%^YELLOW%^"+ETO->query_cap_name()+" suddenly strikes at"+
						            " "+targ->query_cap_name()+" while "+targ->query_subjective()+""+
						            " is off guard!",({ETO,targ}));
						        targ->do_damage("torso",random(10)+6);
						        return 1;
					        }
					    break;
                        }
                }
			    break;
            }

		case 3: case 6: case 9:
            {
			switch(talign) 
            {
				case 1: case 4: case 7:
                    {
					if(!random(3)) 
                    {
						tell_object(ETO,"%^BOLD%^%^RED%^The %^YELLOW%^Sunblade%^RED%^"+
						    " screams as you strike at "+targ->query_cap_name()+","+
						    " the cry somehow tears painfully at your soul.");
						tell_object(targ,"%^BOLD%^%^RED%^As "+ETO->query_cap_name()+""+
						    " strikes at you, "+ETO->query_possessive()+""+
						    " %^YELLOW%^Sunblade%^RED%^ screams and "+ETO->query_subjective()+""+
						    " winces in pain.");
						tell_room(environment(ETO),"%^BOLD%^%^RED%^As"+
						    " "+ETO->query_cap_name()+" strikes out at "+targ->query_cap_name()+""+
						    " the %^YELLOW%^Sunblade%^RED%^ screams and"+
						    " "+ETO->query_subjective()+" winces in pain.",({targ,ETO}));
						ETO->do_damage("torso",random(10)+5);
						return 1;
					}
					break;
				}

				case 2: case 5: case 8:
                    {
					if(!random(15)) 
                    {
						tell_object(ETO,"%^ORANGE%^The sword moves"+
						    " reluctantly in your hands.");
						tell_room(environment(ETO),"%^ORANGE%^"+ETO->query_cap_name()+"'s"+
						    " sword moves slowly, almost as though it"+
						    " were being swung underwater.",ETO);
						return 1;
					}
					break;
				}

				case 3: case 6: case 9:
                    {
					if(!random(20)) 
                    {
						tell_object(ETO,"%^RED%^The %^YELLOW%^Sunblade"+
						    " %^RESET%^%^RED%^begins to burn a fiery red"+
						    " as it strikes "+targ->query_cap_name()+","+
						    " the flames move along the blade to the hilt,"+
						    " burning you as well.");
						tell_object(targ,"%^RED%^"+ETO->query_cap_name()+"'s"+
						    " sword strikes you and bursts into angry red"+
						    " flames that burn like the nine hells! They"+
						    " burn their way down the hilt and seem"+
						    " to hurt "+ETO->query_cap_name()+" as well.");
						tell_room(environment(ETO),"%^RED%^"+ETO->query_cap_name()+"'s"+
						    " %^YELLOW%^Sunblade%^RESET%^%^RED%^ bursts"+
						    " into angry red flames as it strikes "+targ->query_cap_name()+","+
						    " the flames spread down the hilt and burn"+
						    " "+ETO->query_cap_name()+" as well.",({ETO,targ}));
						targ->do_damage("torso",random(10)+10);
						ETO->do_damage("torso",random(10)+8);
						return 1;
					}
					break;
				}
			}
		}
	}
}
