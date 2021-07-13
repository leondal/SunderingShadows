//Object for the deku haunted house - my intention was so that 
//random encounters are basically more that - random - and the area 
//will appear empty, except for boss type monsters and the sub-basement/roof areas
//which should hopefully add to the creepy feeling of it - Saide

#include <std.h>
#include <daemons.h>
#include "../inherits/area_stuff.h"
#define NUMBERS ({ "zero", "one", "two", "three", "four", "five", "six","seven", "eight", "nine", "ten" })
#define NOATTACK ({HHROOMS+"rt23", HHROOMS+"brr1", HHROOMS+"brr2", HHROOMS+"brr3", HHROOMS+"ffr1", HHROOMS+"ffr2", HHROOMS+"ffr3",\
HHROOMS+"ffr4", HHROOMS+"ffr5", HHROOMS+"ffr6", HHROOMS+"ffr7", HHROOMS+"ffr8", HHROOMS+"ffr9",\
HHROOMS+"sfr1", HHROOMS+"sfr2", HHROOMS+"sfr3",\
HHROOMS+"sfr4", HHROOMS+"sfr5", HHROOMS+"sfr6", HHROOMS+"sfr7", HHROOMS+"sfr8"})

inherit OBJECT;

int delay;
void do_random_effect(int which);
void do_random_courtyard_effect();
void do_random_basement_effect();
void do_random_first_floor_effect();
void do_random_second_floor_effect();

void create() 
{
    ::create();
    set_name("haunted curse");
    set_id(({"saide_haunting_object"}));
    set_short("");
    set_long("");
    set_property("no animate",1);
    set_weight(0);
    set_heart_beat(1);
}

void uncurse_me()
{
    if(!objectp(TO)) return;
    if(!objectp(ETO)) return;
    if(!objectp(EETO)) return;
	
    tell_object(ETO, "%^BOLD%^%^WHITE%^You feel "+
    "at ease as the unseen gaze finally "+
    "lifts!%^RESET%^");
    TO->remove();
    return;
}

void place_encounters2(string file, string where, string what, string dir)
{
    string *tmp_array, *tmp_array2, loc;
    object MyOb;
    //tell_object(ETO, "dir + what = "+dir+what);
    //tell_object(ETO, "where = "+ where +" file = "+file);
    if(!stringp(where)) return;
    if(!stringp(what)) return;
    if(!stringp(file)) return;
    if(!stringp(dir)) return;
    
    tmp_array = SAVE_D->query_array(file);
    tmp_array2 = SAVE_D->query_array(where);
    if(!sizeof(tmp_array)) 
    {
        if(!sizeof(tmp_array2)) 
        {       
            if(catch(MyOb = new(dir+what))) return;
        }
        else
        {
            if(catch(MyOb = new(dir+what))) return;
            loc = tmp_array2[0];
        }
    }
    else if(sizeof(tmp_array)) 
    {
        if(!objectp(tmp_array[0]))
        {
            if(sizeof(tmp_array2)) 
            {
                if(catch(MyOb = new(dir+what))) return;
                loc = tmp_array2[0];
            }
            else
            {
                if(catch(MyOb = new(dir+what))) return;
            }
        }
        else if(!objectp(environment(tmp_array[0]))) 
        {
            MyOb = tmp_array[0];
            if(sizeof(tmp_array2)) 
            {
                loc = tmp_array2[0];
            }
        }
    }
    if(objectp(MyOb)) 
    {
        //tell_object(ETO, "MyOb = "+identify(MyOb)+" loc = "+loc);
        MyOb->pick_room(loc);
    }
    return;
}

void place_encounters()
{
    string *tmp_array, tmp;
    int respawn_time;
    TO->remove_property("place_encounters");
    TO->set_property("place_encounters", time() + 60);
    tmp_array = SAVE_D->query_array("hhouse_first_floor_boss");
    if(!sizeof(tmp_array)) 
    {
        tmp_array = get_dir(HHROOMS+"ffr*.c");
        tmp = tmp_array[random(sizeof(tmp_array))];
        SAVE_D->set_value("hhouse_first_floor_boss", HHROOMS+tmp);
    }
    tmp_array = SAVE_D->query_array("hhouse_second_floor_boss");
    if(!sizeof(tmp_array)) 
    {
        tmp_array = get_dir(HHROOMS+"sfr*.c");
        tmp = tmp_array[random(sizeof(tmp_array))];
        SAVE_D->set_value("hhouse_second_floor_boss", HHROOMS+tmp);
    }
        
    tmp_array = SAVE_D->query_array("basement_assassin_died");
    if(sizeof(tmp_array)) 
    {
        respawn_time = tmp_array[0];
    }
    if(!intp(respawn_time)) respawn_time = 0;
    if(time() > respawn_time) 
    {
        tmp_array = SAVE_D->query_array("hhouse_basement_assassin");
        if(!sizeof(tmp_array)) new(HHMON+"assassin")->place_me();
        else if(sizeof(tmp_array)) 
        {
            if(!objectp(tmp_array[0])) 
            {
                SAVE_D->remove_array("hhouse_basement_assassin");
                new(HHMON+"assassin")->place_me();
            }
            else if(!objectp(environment(tmp_array[0]))) 
            {
                tmp_array[0]->place_me();
            }
        }
        place_encounters2("hhouse_basement_assassin", "hhouse_basement_assassin_location", "assassin", HHMON);
    }
    place_encounters2("hhouse_entry_ob", "hhouse_entry_ob_location", "entry_ob", HHOB);
    place_encounters2("hhouse_entry_ob2", "hhouse_entry_ob2_location", "entry_ob2", HHOB);
    place_encounters2("hhouse_entry_ob3", "hhouse_entry_ob3_location", "entry_ob3", HHOB);    
    return;
}


void curse_me()
{
    if(!objectp(TO)) return;
    if(!objectp(ETO)) return;
    if(!objectp(EETO)) return;
    if(ETO->query_true_invis()) return;
    tell_object(ETO, "%^BOLD%^%^BLACK%^A feeling of "+
    "%^BOLD%^%^RED%^d%^BOLD%^%^BLACK%^r%^BOLD%^%^RED%^e"+
    "%^BOLD%^%^BLACK%^a%^BOLD%^%^RED%^d%^BOLD%^%^BLACK%^ "+
    "almost overwhelms you as you sense the %^BOLD%^%^RED%^"+
    "GAZE%^BOLD%^%^BLACK%^ "+
    "of something unseen settle upon you!%^RESET%^");

    if(!ETO->query_invis())
    {
        tell_room(EETO, ETOQCN+"%^BOLD%^%^BLACK%^ suddenly "+
        "seems startled!%^RESET%^", ETO);
    }
}


//handles all effects, specific floors use a specic value (which) 
//some effects are universal, such as warnings, and ghosts - 
//phantom weapons occur in the basement and on the second floor

void do_random_effect(int which)
{
    string tlim;
    object mon;
    int amt;
    object *wpns, wpn;
    if(!objectp(TO)) return;
    if(!objectp(ETO)) return;
    if(!objectp(EETO)) return;
    switch (which) 
    {
        //0..2 = random messages
        case 0:
            tell_object(ETO, "%^BOLD%^%^CYAN%^Someone whispers to you:%^RESET%^ "+
            "You are gonna die, you are gonna die!! You are gonna die and they "+
            "will %^BOLD%^%^RED%^NEVER EVER FIND YOUR BROKEN CORPSE!%^RESET%^");	
            if(!ETO->query_invis()) 
            {
                tell_room(EETO, "%^BOLD%^%^CYAN%^Someone whispers something to "+
                ETOQCN+".%^RESET%^", ETO);
            }
            break;
        case 1:
            tell_object(ETO, "%^BOLD%^%^RED%^A disembodied voice %^BOLD%^%^YELLOW%^"+
            "SCREAMS%^BOLD%^%^RED%^ at you: %^RESET%^TURN BACK NOW!!!!!%^RESET%^");

            tell_room(EETO, "%^BOLD%^%^RED%^A disembodied voice %^BOLD%^%^YELLOW%^"+
            "SCREAMS%^BOLD%^%^RED%^ at "+ETOQCN+":%^RESET%^ TURN BACK NOW!!!!!!%^RESET%^", ETO);
            break;

            //Ghosts
        case 2:
            tell_room(EETO, "%^BOLD%^%^CYAN%^A faint whisper is carried by the wind:%^RESET%^ "+
            "do it.... absorb all of the %^BOLD%^WHITE%^LIFE%^RESET%^ from "+
            ETOQCN+" so that I might grow stronger!%^RESET%^");

            tell_object(ETO, "%^BOLD%^%^RED%^A sudden prickling on the back of "+
            "your neck makes you think that you are not alone.. and a %^BOLD%^%^GREEN%^"+
            "SHRILL%^RESET%^ scream confirms it!%^RESET%^");
				
            amt = 2 + random(2);
			
            tell_room(EETO, "%^BOLD%^%^RED%^You watch in horror as %^BOLD%^"+
            "%^CYAN%^"+NUMBERS[amt]+ " ghosts%^BOLD%^%^RED%^, their faces locked in "+
            "an eternal grimace, materialize behind "+ETOQCN+"%^BOLD%^%^RED%^!%^RESET%^", ETO);

            while(amt--)
            {
                mon = new(HHMON+"malevolent_ghost");
                mon->move(EETO);
            }
            if(objectp(mon)) mon->absorb_life(ETO);
			
            break;
			
		//Courtyard - Vines	
		case 3:
			
            amt = 2 + random(2);

            tell_room(EETO, "%^BOLD%^%^WHITE%^A %^BOLD%^%^RED%^BOOMING%^BOLD%^%^WHITE%^ voice "+
            "%^BOLD%^%^YELLOW%^T%^BOLD%^%^BLACK%^H%^BOLD%^%^YELLOW%^U%^BOLD%^%^BLACK%^N%^BOLD%^%^YELLOW%^"+
            "D%^BOLD%^%^BLACK%^E%^BOLD%^%^YELLOW%^R%^BOLD%^%^BLACK%^S %^BOLD%^%^WHITE%^: %^RESET%^"+
            "I want "+ETOQCN+"%^BOLD%^%^RED%^ DEAD!%^RESET%^");

            tell_object(ETO, "%^BOLD%^%^GREEN%^Suddenly, before you really %^BOLD%^%^RED%^COMPREHEND"+
            "%^BOLD%^%^GREEN%^ what is happening "+NUMBERS[amt]+ " of the vines spring to life! They "+
            "%^BOLD%^%^BLACK%^TEAR%^BOLD%^%^GREEN%^ away from the walls of the house and "+
            "lash out at you!%^RESET%^");
			
            tell_room(EETO, "%^BOLD%^%^GREEN%^Suddenly, before you really %^BOLD%^%^RED%^COMPREHEND"+
            "%^BOLD%^%^GREEN%^ what is happening "+NUMBERS[amt]+ " of the vines spring to life! They "+
            "%^BOLD%^%^BLACK%^TEAR%^BOLD%^%^GREEN%^ away from the walls of the house and lash out at "+
            ETOQCN+"%^BOLD%^%^GREEN%^!%^RESET%^", ETO);

            while(amt--)
			{
                mon = new(HHMON+"monstrous_vine");
                mon->move(EETO);
            }
            if(objectp(mon)) mon->lash_out(ETO);
            break;

        //Courtyard - lightning
        case 4:
			
            tell_object(ETO, "%^BOLD%^%^WHITE%^With a %^BOLD%^%^GREEN%^DEFEANING%^BOLD%^%^RED%^"+
            " BOOM%^BOLD%^%^WHITE%^ a brilliant bolt of %^BOLD%^%^YELLOW%^l"+
            "%^BOLD%^%^RED%^i%^BOLD%^%^YELLOW%^g%^BOLD%^%^RED%^h%^BOLD%^"+	
            "%^YELLOW%^t%^BOLD%^%^RED%^n%^BOLD%^%^YELLOW%^i%^BOLD%^%^RED%^"+
            "n%^BOLD%^%^YELLOW%^g%^BOLD%^%^WHITE%^ zaps from the roof of the "+
            "house toward you!%^RESET%^");
			
            tell_room(EETO, "%^BOLD%^%^WHITE%^With a %^BOLD%^%^GREEN%^DEFEANING%^BOLD%^%^RED%^"+
            " BOOM%^BOLD%^%^WHITE%^ a brilliant bolt of %^BOLD%^%^YELLOW%^l"+
            "%^BOLD%^%^RED%^i%^BOLD%^%^YELLOW%^g%^BOLD%^%^RED%^h%^BOLD%^"+
            "%^YELLOW%^t%^BOLD%^%^RED%^n%^BOLD%^%^YELLOW%^i%^BOLD%^%^RED%^"+
            "n%^BOLD%^%^YELLOW%^g%^BOLD%^%^WHITE%^ zaps from the roof of the "+
            "house toward "+ETOQCN+"%^BOLD%^%^WHITE%^!%^RESET%^", ETO);

            if(ETO->reflex_save(25)) 
            {
                tell_object(ETO, "%^BOLD%^%^BLACK%^Incredibly you manage to "+
                "move out of the way just in time and the bolt of %^BOLD%^%^YELLOW%^l"+
                "%^BOLD%^%^RED%^i%^BOLD%^%^YELLOW%^g%^BOLD%^%^RED%^h%^BOLD%^"+
                "%^YELLOW%^t%^BOLD%^%^RED%^n%^BOLD%^%^YELLOW%^i%^BOLD%^%^RED%^"+
                "n%^BOLD%^%^YELLOW%^g%^BOLD%^%^BLACK%^ slams into the ground!%^RESET%^");
				
                tell_room(EETO, "%^BOLD%^%^BLACK%^Incredibly "+ETOQCN+"%^BOLD%^"+
                "%^BLACK%^ manages to move out of the way just in time and the bolt of "+
                "%^BOLD%^%^YELLOW%^l%^BOLD%^%^RED%^i%^BOLD%^%^YELLOW%^g%^BOLD%^%^RED%^h%^BOLD%^"+
                "%^YELLOW%^t%^BOLD%^%^RED%^n%^BOLD%^%^YELLOW%^i%^BOLD%^%^RED%^"+
                "n%^BOLD%^%^YELLOW%^g%^BOLD%^%^WHITE%^ slams into the ground!%^RESET%^", ETO);
            }
            else
            {
                tlim = ETO->return_target_limb();
                tell_object(ETO, "%^BOLD%^%^RED%^The bolt of %^BOLD%^%^YELLOW%^l"+
                "%^BOLD%^%^RED%^i%^BOLD%^%^YELLOW%^g%^BOLD%^%^RED%^h%^BOLD%^"+		
                "%^YELLOW%^t%^BOLD%^%^RED%^n%^BOLD%^%^YELLOW%^i%^BOLD%^%^RED%^"+
                "n%^BOLD%^%^YELLOW%^g%^BOLD%^%^RED%^ slams into your "+tlim+
                ", %^BOLD%^%^BLACK%^SEARING%^BOLD%^%^RED%^ your flesh!%^RESET%^");
				
                tell_room(EETO, "%^BOLD%^%^RED%^The bolt of %^BOLD%^%^YELLOW%^l"+
                "%^BOLD%^%^RED%^i%^BOLD%^%^YELLOW%^g%^BOLD%^%^RED%^h%^BOLD%^"+		
                "%^YELLOW%^t%^BOLD%^%^RED%^n%^BOLD%^%^YELLOW%^i%^BOLD%^%^RED%^"+
                "n%^BOLD%^%^YELLOW%^g%^BOLD%^%^RED%^ slams into "+ETOQCN+		
                "%^BOLD%^%^RED%^'s "+tlim+" %^BOLD%^%^BLACK%^SEARING"+
                "%^BOLD%^%^RED%^ "+ETO->QP+" flesh!%^RESET%^", ETO);

                ETO->cause_typed_damage(ETO,tlim,roll_dice(22,6),"electricity");
            }
            break;
        //Courtyard - Moss
        case 5:
			
            tell_object(ETO, "%^RESET%^%^GREEN%^The moss on the ground suddenly "+
            "begins grabbing at your feet!%^RESET%^");

            tell_room(EETO, "%^RESET%^%^GREEN%^The moss on the ground suddenly "+
            "begins grabbing at "+ETOQCN+"%^RESET%^%^GREEN%^'s feet!%^RESET%^", ETO);
				
            if(ETO->reflex_save(24))
            {
                tell_object(ETO, "%^BOLD%^%^BLACK%^You manage to maneuver out of the "+
                "way of the %^RESET%^%^GREEN%^groping moss%^BOLD%^%^BLACK%^"+
                " and it quickly settles back down!%^RESET%^");
			
                tell_room(EETO, ETOQCN+"%^BOLD%^%^BLACK%^ manages to maneuvers out of the "+
                "way of the %^RESET%^%^GREEN%^groping moss%^BOLD%^%^BLACK%^"+ 
                " and it quickly settles back down!%^RESET%^", ETO);
            }
            else
            {
                tell_object(ETO, "%^BOLD%^%^GREEN%^The %^RESET%^%^GREEN%^groping moss"+
                "%^BOLD%^%^GREEN%^ quickly swallows your feet and pulls you to "+
                "the ground!%^RESET%^");
				
                tell_room(EETO, "%^BOLD%^%^GREEN%^The %^RESET%^%^GREEN%^groping moss"+
                "%^BOLD%^%^GREEN%^ quickly swallows "+ETOQCN+"%^BOLD%^%^GREEN%^'s "+
                "feet and pulls "+ETO->QO+" to the ground!%^RESET%^", ETO);

                ETO->set_tripped(8, "%^RESET%^%^GREEN%^You are held fast by the "+
                "moss!%^RESET%^");
            }
            break;
		
        //First floor - skeletons
        case 6:
            if(strsrch(base_name(EETO), "iw") != -1 || strsrch(base_name(EETO), "ffr") != -1) 
            {
                do_random_effect(random(2));
                return;
            }
            tell_room(EETO, "%^BOLD%^%^RED%^A %^BOLD%^%^YELLOW%^GUTTURAL%^BOLD%^%^RED%^"+
            " voice screams in RAGE:%^RESET%^ ARISE My MINIONS and %^BOLD%^%^BLACK%^DESTROY"+
            "%^RESET%^ "+ETOQCN+"!%^RESET%^");
            amt = 2 + random(2);

            tell_room(EETO, "%^BOLD%^%^WHITE%^You watch in amazement as "+NUMBERS[amt]+
            " %^BOLD%^%^BLACK%^%^BOLD%^%^WHITE%^G%^BOLD%^%^BLACK%^"+
            "l%^BOLD%^%^WHITE%^e%^BOLD%^%^BLACK%^a%^BOLD%^%^WHITE%^m"+
            "%^BOLD%^%^BLACK%^i%^BOLD%^%^WHITE%^n%^BOLD%^%^BLACK%^g "+
            "%^BOLD%^%^WHITE%^black skeletons instantly assemble "+
            "from the hordes of bone here "+
            "and attack!%^RESET%^");

            while(amt--)
            {
                mon = new(HHMON+"giant_skeleton");
                mon->move(EETO);
            }
            mon->destroy(ETO);
            break;

        //first floor - spikes
        case 7:
            tell_room(EETO, "%^BOLD%^%^WHITE%^An %^BOLD%^%^GREEN%^I%^BOLD%^%^BLACK%^"+
            "N%^BOLD%^%^GREEN%^S%^BOLD%^%^BLACK%^A%^BOLD%^%^GREEN%^N%^BOLD%^%^BLACK%^E"+
            "%^BOLD%^WHITE%^ laughter echoes all around you!%^RESET%^");

            tell_object(ETO, "%^RESET%^%^ORANGE%^Numerous spikes suddenly spring forth "+
            "from beneath your feet!%^RESET%^");

            tell_room(EETO, "%^RESET%^%^ORANGE%^Numerous spikes suddenly spring forth "+
            "from beneath "+ETOQCN+"%^RESET%^%^ORANGE%^'s feet!%^RESET%^", ETO);

            if(ETO->reflex_save(22)) 
            {
                tell_object(ETO, "%^BOLD%^%^RED%^You react instinctively and "+
                "manage to avoid the spikes!%^RESET%^");

                tell_room(EETO, ETOQCN+"%^BOLD%^%^RED%^ lets "+ETO->QP+
                " reflexes take over and manages to avoid the spikes!%^RESET%^", ETO);				
            }
            else
            {
                tell_object(ETO, "%^BOLD%^%^MAGENTA%^You are unable to move in "+
                "time and the spikes %^BOLD%^%^RED%^IMPALE%^BOLD%^%^MAGENTA%^ "+
                "you!%^RESET%^");

                tell_room(EETO, ETOQCN+"%^BOLD%^%^MAGENTA%^ is unable to move in "+
                "time and the spikes %^BOLD%^%^RED%^IMPALE%^BOLD%^%^MAGENTA%^ "+
                ETO->QO+"!%^RESET%^", ETO);
				
                ETO->cause_typed_damage(ETO, ETO->return_target_limb(), roll_dice(6, 10), "piercing");
            }
			
            tell_room(EETO, "%^RESET%^%^ORANGE%^The %^BOLD%^%^GREEN%^I%^BOLD%^%^BLACK%^"+
            "N%^BOLD%^%^GREEN%^S%^BOLD%^%^BLACK%^A%^BOLD%^%^GREEN%^N%^BOLD%^%^BLACK%^E"+
            "%^RESET%^%^ORANGE%^ laughter fades away and the spikes "+
            "%^BOLD%^%^RED%^VANISH%^RESET%^%^ORANGE%^ with it!%^RESET%^");	
            break;
        //first floor - noxious gas

        case 8:
            tell_object(ETO, "%^BOLD%^%^GREEN%^A cloud of %^BOLD%^%^YELLOW%^N"+
            "%^BOLD%^%^GREEN%^O%^BOLD%^%^YELLOW%^X%^BOLD%^%^GREEN%^I%^BOLD%^%^GREEN%^"+
            "O%^BOLD%^%^YELLOW%^U%^BOLD%^%^GREEN%^S gas suddenly surrounds you!%^RESET%^");

            tell_room(EETO, ETOQCN+"%^BOLD%^%^GREEN%^'s head is suddenly "+
            "surrounded by a cloud of %^BOLD%^%^YELLOW%^N"+
            "%^BOLD%^%^GREEN%^O%^BOLD%^%^YELLOW%^X%^BOLD%^%^GREEN%^I%^BOLD%^%^GREEN%^"+
            "O%^BOLD%^%^YELLOW%^U%^BOLD%^%^GREEN%^S gas!%^RESET%^", ETO);

            tell_object(ETO, "%^BOLD%^%^CYAN%^A voice whispers to you:%^RESET%^ "+
            "breath it in, breath in %^BOLD%^%^RED%^DEATH%^BOLD%^%^CYAN%^!! "+
            "IT IS ALL THAT AWAITS YOU!%^RESET%^");

            POISON_D->ApplyPoison(ETO, "any", ETO, "inhaled");
		
            tell_room(EETO, "%^BOLD%^%^BLUE%^A %^BOLD%^%^CYAN%^CHILLING%^BOLD%^"+
            "%^BLUE%^ wind sweeps through the area and the %^BOLD%^%^YELLOW%^N"+
            "%^BOLD%^%^GREEN%^O%^BOLD%^%^YELLOW%^X%^BOLD%^%^GREEN%^I%^BOLD%^%^GREEN%^"+
            "O%^BOLD%^%^YELLOW%^U%^BOLD%^%^GREEN%^S gas cloud dissipates!%^RESET%^");
            break;

        //basement && second floor - phantom weapons	
        case 9:
            tell_object(ETO, "%^BOLD%^%^CYAN%^A voice, barely able to contain "+
            "its laughter, whispers to you:%^RESET%^ I have another trick that "+
            "you should see!!!");

            tell_room(EETO, "%^BOLD%^%^BLACK%^A small portion of the air "+
            "begins glowing a %^BOLD%^%^RED%^deep red%^BOLD%^%^BLACK%^ and it "+
            "%^BOLD%^%^RED%^RIPS%^BOLD%^%^BLACK%^ open!%^RESET%^");

            tell_room(EETO, "%^BOLD%^%^RED%^Two weapons are thrown "+
            "through the hole into this world!%^RESET%^");

            tell_room(EETO, "%^BOLD%^%^BLUE%^The weapons begin moving on their "+
            "own! Posssessed by a malevolent life of their own they "+
            "turn toward "+ETOQCN+"%^BOLD%^%^BLUE%^!%^RESET%^", ETO);

            tell_object(ETO, "%^BOLD%^%^BLUE%^The weapons begin moving on their "+
            "own! Possessed by a malevolent life of their own they turn "+
            "toward you!%^RESET%^");

            wpns = ETO->query_wielded();
            if(sizeof(wpns)) 
            {
                wpn = wpns[random(sizeof(wpns))];
                wpns -= ({wpn});
            }
            mon = new(AOMON +"phantom_weapon");
            mon->possess_this(wpn);
            mon->move(EETO);
            mon->kill_ob(ETO);
            if(sizeof(wpns)) wpn = wpns[0];
            mon = new(AOMON +"phantom_weapon");
            mon->possess_this(wpn);
            mon->move(EETO);
            mon->kill_ob(ETO);
            break;
		
        //basement - hellhounds	
        case 10:
			
            tell_room(EETO, "%^BOLD%^%^RED%^A sudden and %^BOLD%^%^YELLOW%^S"+
            "%^BOLD%^%^GREEN%^H%^BOLD%^%^YELLOW%^R%^BOLD%^%^GREEN%^I%^BOLD%^"+
            "%^YELLOW%^L%^BOLD%^%^GREEN%^L %^BOLD%^%^RED%^whistling "+
            "bursts forth from the very air around you!%^RESET%^");

            tell_room(EETO, "%^BOLD%^%^BLACK%^A hoarse voice croaks:%^RESET%^ "+
            "Come forth, come now, and %^BOLD%^%^RED%^FEED%^RESET%^ on "+
            ETOQCN+"!%^RESET%^");

            amt = 2 + random(2);
            tell_room(EETO, "%^BOLD%^%^RED%^"+capitalize(NUMBERS[amt])+"%^BOLD%^%^RED%^ hellhounds "+
            "charge in from out of nowhere and run straight toward "+ETOQCN+
            "%^BOLD%^%^RED%^!%^RESET%^", ETO);

            tell_object(ETO, "%^BOLD%^%^RED%^"+capitalize(NUMBERS[amt])+"%^BOLD%^%^RED%^ hellhounds "+
            "charge in from out of nowhere and run straight toward you!%^RESET%^");

            while(amt--)
            {
                mon = new(HHMON+"hellhound");
                mon->move(EETO);
            }
            mon->bite(ETO);
            break;
			
        //basement - bolt of blackness  
        case 11:
			
            tell_room(EETO, "%^BOLD%^%^MAGENTA%^The very air around you "+
            "is suddenly %^BOLD%^%^BLACK%^CHARGED%^BOLD%^%^MAGENTA%^ with "+
            "power!%^RESET%^");

            amt = 2 + random(4);
				
            tell_room(EETO, "%^BOLD%^%^BLACK%^"+capitalize(NUMBERS[amt]) + " bolts of "+
            "pure %^BOLD%^%^WHITE%^darkness%^BOLD%^%^BLACK%^ erupt from out "+
            "of nowhere and streak toward "+ETOQCN+"%^BOLD%^%^BLACK%^!%^RESET%^", ETO);

            tell_object(ETO, "%^BOLD%^%^BLACK%^"+capitalize(NUMBERS[amt]) + " bolts of "+
            "pure %^BOLD%^%^WHITE%^darkness%^BOLD%^%^BLACK%^ erupt from out of "+
            "nowhere and streak toward you!%^RESET%^");

            if(ETO->reflex_save(22)) 
            {
                tell_object(ETO, "%^BOLD%^%^RED%^You stumble quickly out of the "+
                "way of the bolts and they %^BOLD%^%^BLACK%^EXPLODE%^BOLD%^%^RED%^"+
                " in a brilliant flash of light!%^RESET%^");

                tell_room(EETO, ETOQCN+"%^BOLD%^%^RED%^ stumbles quickly out of "+
                "way of the bolts and they %^BOLD%^%^BLACK%^EXPLODE%^BOLD%^%^RED%^ "+
                "in a brilliant flash of light!%^RESET%^", ETO);
            }
            else
            {
                tell_object(ETO, "%^BOLD%^%^WHITE%^All "+NUMBERS[amt] + " bolts "+
                "of %^BOLD%^%^BLACK%^DARKNESS%^BOLD%^%^WHITE%^ explode into your "+
                "torso and your are temporarily blinded by the brilliant flash of "+
                "light!%^RESET%^");

                tell_room(EETO, "%^BOLD%^%^WHITE%^All "+NUMBERS[amt] + " bolts "+
                "of %^BOLD%^%^BLACK%^DARKNESS%^BOLD%^%^WHITE%^ explode into "+
                ETOQCN+"%^BOLD%^%^WHITE%^'s chest in a brilliant flash of "+
                "light!%^RESET%^", ETO);
				
                ETO->set_temporary_blinded(10);
                ETO->cause_typed_damage(ETO, "torso", roll_dice(amt, 20), "negative energy");
            }
            tell_room(EETO, "%^BOLD%^%^RED%^An angry voice %^BOLD%^%^WHITE%^T"+
            "%^BOLD%^%^YELLOW%^H%^BOLD%^%^WHITE%^U%^BOLD%^%^YELLOW%^N%^BOLD%^%^WHITE%^"+
            "D%^BOLD%^%^YELLOW%^E%^BOLD%^%^WHITE%^R%^BOLD%^%^YELLOW%^S%^BOLD%^%^RED%^: "+
            "%^RESET%^I am only getting started!!!");
            break;
	
        //second floor - shadow
        case 12:
            tell_object(ETO, "%^BOLD%^%^CYAN%^A quiet voice whispers to you:%^RESET%^ "+
            "I will make your very shadow my servant and once your body is broken "+
            "I will make you serve me!%^RESET%^");
			
            tell_object(ETO, "%^BOLD%^%^RED%^The hair on the back of your neck "+
            "stands up as you sense something is incredibly wrong.....%^RESET%^");
			
            tell_room(EETO, "%^BOLD%^%^BLUE%^Before your very eyes, "+ETOQCN+
            "%^BOLD%^%^BLUE%^'s shadow %^BOLD%^%^RED%^RISES%^BOLD%^%^BLUE%^"+
            " up behind "+ETO->QO+"%^BOLD%^%^BLUE%^ and attacks!%^RESET%^", ETO);

            mon = new(HHMON+"hulking_shadow");
            mon->shadow_me(ETO);
            mon->move(EETO);
            mon->dark_bolt(ETO);
            break;
		
        //second floor - psionic blast
        case 13:
            tell_object(ETO, "%^BOLD%^%^MAGENTA%^Something is very very "+
            "wrong....%^RESET%^");
            tell_object(ETO, "%^BOLD%^%^GREEN%^Your life flashes before your "+
            "eyes and nothing you have done seems good enough....%^RESET%^");
			
            tell_room(EETO, ETOQCN+"%^BOLD%^%^WHITE%^ looks almost as if "+
            ETO->QS+"%^BOLD%^%^WHITE%^ is in a trance.%^RESET%^", ETO);
			
            if(ETO->will_save(22)) 
            {
                tell_object(ETO, "%^BOLD%^%^RED%^You recognize your "+
                "strange thoughts as some type of psionic "+
                "intrusion into your mind and are able to snap out of "+
                "it!%^RESET%^");

                tell_room(EETO, ETOQCN+"%^BOLD%^%^RED%^ shakes "+ETO->QP+		
                " head and seems to come back to reality!%^RESET%^", ETO);
            }
            else
            {
                tell_object(ETO, "%^BOLD%^%^BLUE%^You're a coward, a "+
                "failure, and nothing you have done has been "+
                "worth it... your life is simply a %^BOLD%^%^RED%^waste"+
                "%^BOLD%^%^BLUE%^...");

                tell_object(ETO, "%^BOLD%^%^BLACK%^An %^BOLD%^%^GREEN%^"+
                "A%^BOLD%^%^BLACK%^G%^BOLD%^%^GREEN%^O%^BOLD%^%^BLACK%^"+
                "N%^BOLD%^%^GREEN%^I%^BOLD%^%^BLACK%^Z%^BOLD%^%^GREEN%^I"+
                "%^BOLD%^%^BLACK%^N%^BOLD%^%^GREEN%^G %^BOLD%^%^BLACK%^"+
                "pain swells inside your head and erupts!%^RESET%^");

                tell_room(EETO, ETOQCN+"%^BOLD%^%^RED%^ SCREAMS%^BOLD%^%^BLACK%^"+
                " in obvious pain, falling to "+ETO->QP+" knees!%^RESET%^", ETO);

                ETO->cause_typed_damage(ETO, "head", roll_dice(12,12), "mental");

                ETO->set_paralyzed(20, "%^BOLD%^%^RED%^You are trying to pick "+
                "yourself up!%^RESET%^");
            }
            tell_room(EETO, "%^BOLD%^%^BLUE%^A manical laughter echoes all "+
            "around you!%^RESET%^");
            break;		
    }
}
	
//Effects that occur in the courtyard area of the house
void do_random_courtyard_effect()
{
    if(!objectp(TO)) return;
    if(!objectp(ETO)) return;
    if(!objectp(EETO)) return;
    switch(random(5)) 
    {
        case 0: 
            do_random_effect(random(2));
            break;
        case 1:
            do_random_effect(2);
            break;
        case 2:
            do_random_effect(3);
            break;
        case 3:
            do_random_effect(4);
            break;			
        case 4:
            do_random_effect(5);
            break;
    }
}

//Effects that occur on the first floor of the house - Saide
void do_random_first_floor_effect()
{
    if(!objectp(TO)) return;
    if(!objectp(ETO)) return;
    if(!objectp(EETO)) return;
    switch(random(5)) 
    {
        case 0:
            do_random_effect(random(2));
            break;
        case 1:
            do_random_effect(6);
            break;
        case 2:
            do_random_effect(7);			
            break;
        case 3:
            do_random_effect(2);			
            break;
        case 4:
            do_random_effect(8);
            break;
    }
}

//Effects that occur in the basement of the house - not including the sub-basement - Saide
void do_random_basement_effect()
{
    if(!objectp(TO)) return;
    if(!objectp(ETO)) return;
    if(!objectp(EETO)) return;
    switch(random(5)) 
    {
        case 0:
            do_random_effect(random(2));
            break;
        case 1:
            do_random_effect(9);
            break;
        case 2:
            do_random_effect(10);
            break;			
        case 3:
            do_random_effect(11);
            break;
        case 4:
            do_random_effect(2);			
            break;
    }
}

//Effects that occur on the second floor of the house - Saide
void do_random_second_floor_effect()
{
    if(!objectp(TO)) return;
    if(!objectp(ETO)) return;
    if(!objectp(EETO)) return;
    switch(random(5)) 
    {
        case 0:
            do_random_effect(random(2));
            break;
        case 1:
            do_random_effect(2);			
            break;
        case 2:
            do_random_effect(9);
            break;
        case 3:
            do_random_effect(12);
            break;	
        case 4:
            do_random_effect(13);
            break;
    }
}



int set_delay(int x) { delay = x; }

void heart_beat()
{
    object ob;
    string tmp, *tmp2;
    if(!objectp(TO)) return;
    if(!objectp(ETO)) return;
    if(!objectp(EETO)) return;
    if(!living(ETO)) return;
    if(present("saide_haunting_object 2", ETO)) 
    {
        TO->remove();
        return;
    }
    if(strsrch(base_name(EETO), HHPATH) == -1)
    {
        uncurse_me();
        return;
    }
    if(ETO->query_true_invis()) return;
    if(ETO->query_property("inactive")) return;
    //in order to not really fuck parties, going to make it so that
    //only one haunting object is active in any room at a time - should
    //be relatively random which object - Saide
    if(objectp(ob = EETO->query_property("active_haunting_object")))
    {
        if(ob != TO) 
        {
            if((int)EETO->query_property("next_haunting_change") < time()) return;
            else
            { 
                EETO->remove_property("next_haunting_change");
                EETO->remove_property("active_haunting_object");
                if(random(2)) 
                {
                    EETO->set_property("active_haunting_object", TO);
                    EETO->set_property("next_haunting_change", time() + 120 + random(61));
                }
            }
        }
    }
    else
    {
        if(!random(2)) 
        {
            EETO->set_property("active_haunting_object", TO);
            EETO->set_property("next_haunting_change", time() + 120 + random(61));
        }
        else return;
    }
    delay--;
    
    if(delay > 0) return;
    delay = 61 + random(120);
    if(member_array(base_name(EETO), NOATTACK) != -1) return;
    
    if(strsrch(base_name(EETO), CYROOMS) != -1)
    {
        do_random_courtyard_effect();
    }
    else if(strsrch(base_name(EETO), FFROOMS) != -1)
    {
        do_random_first_floor_effect();
    }
    else if(strsrch(base_name(EETO), SFROOMS) != -1)
    {	
        do_random_second_floor_effect();
    }
    else if(strsrch(base_name(EETO), BROOMS) != -1)
    {
        do_random_basement_effect();
    }
    else do_random_effect(2);

    return;	  
}

