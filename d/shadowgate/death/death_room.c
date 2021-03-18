//Adapted from Grendel's code by Circe
//4/5/04 New death sequence

#include <std.h>
#include <rooms.h>
#include <daemons.h>

inherit "/d/shadowgate/death/death_inherit.c";

mapping visitors;

void init()
{
    ::init();
    if (!wizardp(this_player())) {
        add_action("filter_act", "", 1);
    }
    if ((int)TP->query_hp() < 1) {
        TP->set_hp(1);
    }
    //going to shorten the death sequence if
    //it is not a pkill - Saide, November 2016
    if (!TP->query("just_been_pkilled")) {
        if (TP->is_vampire()) {
            tell_object(TP, "\n%^BOLD%^CYAN%^You turn into dark mist and let the wind carry you into the darkness... After a while of wandering, you hear a faint song...\n");
            call_out("end_death0_vampire", 5, TP);
            return;
        }else if (TP->is_undead() ||
                  TP->is_class("pale_lord") ||
                  TP->is_class("gravecaller")
            ) {
            tell_object(TP, "\n%^BOLD%^WHITE%^Your existence has ended. The time has come to pay for breaking the covenant. You briefly see a large, open space... Then it fades as you struggle the stream of souls, and turn to elsewhere...\n");
            call_out("end_death0_undead", 5, TP);
            return;
        }else if (TP->query("subrace") == "feytouched" ||
                  TP->query("race") == "faery" ||
                  TP->query("race") == "satyr" ||
                  TP->query("race") == "nymph" ||
                  TP->query("race") == "dryad") {
            tell_object(TP, "%^BOLD%^%^BLACK%^Your final breath is ripped from your lungs, and you feel yourself falling, falling, falling into the earth. The %^RESET%^%^ORANGE%^hard ground %^BOLD%^%^BLACK%^embraces you like an old lover, warm, familiar. %^RESET%^Home%^BOLD%^%^BLACK%^. %^RESET%^\n");
            call_out("end_death0_feytouched", 5, TP);
            return;
        }else {
            tell_object(TP, "\n%^BOLD%^%^WHITE%^You find yourself standing in a large, open space with %^RESET%^mists %^BOLD%^%^WHITE%^that obscure any distance. Rising up before you is a simple oaken chair with a high back, upon which is seated a somber and serene woman. %^BLACK%^Dark hair %^WHITE%^frames her ageless face, while a robe of gray rests about her shoulders like a pall. Her fingers rest upon the chair's arm, and you note the three %^BLACK%^m%^RESET%^i%^BOLD%^%^WHITE%^s%^RESET%^m %^BOLD%^%^BLACK%^a%^RESET%^t%^BOLD%^%^WHITE%^c%^RESET%^h %^BOLD%^%^BLACK%^e%^RESET%^d %^BOLD%^%^WHITE%^rings she wears. As her %^RESET%^%^CYAN%^steady gaze %^BOLD%^%^WHITE%^falls upon you, you realise that this must be the Lady of Fate - Lysara. In agony, you try to recall all you have done that might warrant the deity's attention, and you squirm as you wait to hear what she will say. Finally, she speaks...\n");
            call_out("end_death", 8, TP);
            WHICH_CALL_OUT = "end_death";
            return;
        }
        return;
    }
    if (TP->query_property("trial")) {
        call_out("begin_trial", 4, TP);
        WHICH_CALL_OUT = "begin_trial";
        TP->set("long", 0);
        return;
    }
    call_out("begin_death", 4, TP);
    WHICH_CALL_OUT = "begin_death";
    TP->set("long", 0);
}

void create(){
    ::create();
    set_property("light", 2);
    set_property("indoors",1);
    set_terrain(WOOD_BUILDING);
    set_travel(DIRT_ROAD);
    set_property("no teleport", 1);
    set_short("The void between life and death");
    set_long( (:this_object(), "d_long":) );
    skip_obvious();
    visitors = ([]);
}

string d_long() { return ""; }

int filter_act(string str)
{
    string verb;
    verb = query_verb();

    switch(verb)
    {
    case "tell":
    case "reply":
        //to allow speak with dead to work while you're a ghost
        //even if you aren't in the afterlife - Saide
	  if(sizeof(TP->query_property("allowed tell")))
	  {
		return 0;
	  }
    case "say":
    case "shout":
        write("You let out a haunting wail\n");
        break;
    case "accept":
    case "cancel":
        raise_player(verb);
        break;
    default:
        write("The dead are incapable of such acts.\n");
        break;
    }
    return 1;
}

void begin_death(object tp)
{

    if(( avatarp(tp) && !tp->query_property("long death"))){
	tell_object(tp, "%^BOLD%^%^CYAN%^Well, you ended up "+
         "here in death land.  It's a good thing you're "+
         "immortal because it just saved you from a lengthy "+
         "spiel.  Well, get back in there and get cracking!  "+
         "I'm sure you can think of something productive to do.");
         if(wizardp(tp)) {
            tell_object(tp,"P.S.  If you want to see the whole death sequence, add "+
            "the property 'long death' to yourself.%^RESET%^\n");
         }
	if(tp->query_ghost())
        tp->set_hp(tp->query_max_hp());
        tp->remove_paralyzed();
	    tp->move_player("/d/shadow/room/city/church");
	return;
    }
    tell_object(tp, "%^BOLD%^%^BLUE%^You feel yourself shifting "+
       "on the winds, lifeless and empty.  Soft sighs and endless "+
       "murmurs fill your ears, bringing with them a fear of "+
       "endless misery and wasted lives.  You float, lost upon a "+
       "sea unseen, and a growing uneasiness comes over you.%^RESET%^\n");
    call_out("do_death1", 6, tp);
    WHICH_CALL_OUT = "do_death1";
    attempt_raise();
}

void do_death1(object tp){
    if(!objectp(tp)) return;
    if(!present(tp, TO)) return;

    tell_object(tp, "You feel the nothingness around you begin "+
       "to take form.\n\n%^GREEN%^Suddenly, you are aware..."+
       "aware of yourself, your surroundings, and your dire "+
       "situation.  You are walking down an abandoned road, "+
       "with a hideous green wall rising on both sides and "+
       "closing in behind you, pushing you forward.  As you "+
       "look, you realize the wall is made of twisted faces "+
       "and maimed bodies, all stacked on top of each other.  "+
       "A feeling of terror floods your soul, and you run!%^RESET%^\n");
    call_out("do_death2", 12, tp);
    WHICH_CALL_OUT = "do_death2";
    attempt_raise();
    return;
}

void do_death2(object tp){
    if(!objectp(tp)) return;
    if(!present(tp, TO)) return;

    tell_object(tp, "%^MAGENTA%^With your eyes tightly "+
       "closed, you run for endless miles, feeling a cold, "+
       "damp fog around you.  With your arms outstretched, "+
       "you feel something just ahead.  To your dismay, "+
       "it feels wet and chills you to the bone, much like "+
       "you imagine the wall around you would.  You stand "+
       "for a moment, lost, before you hear something new..."+
       "a quiet, stern voice, though you cannot make out any "+
       "words.  The fog seems to lift, and you feel yourself "+
       "being moved.  The world around you changes, and you "+
       "slowly open your eyes.%^RESET%^\n");
    call_out("do_death3", 10, tp);
    WHICH_CALL_OUT = "do_death3";
    attempt_raise();
    return;
}

void do_death3(object tp){
    if(!objectp(tp)) return;
    if(!present(tp, TO)) return;

    tell_object(TP, "%^BOLD%^%^WHITE%^You find yourself "+
       "standing in a large, open space with %^RESET%^mists "+
       "%^BOLD%^%^WHITE%^that obscure any distance.  Rising up "+
       "before you is a simple oaken chair with a high back, upon which is seated a somber "+
       "and serene woman.  %^BLACK%^Dark hair %^WHITE%^frames her "+
       "ageless face, while a robe of gray rests about her shoulders "+
       "like a pall.  Her fingers rest upon the chair's arm, and you "+
       "note the three %^BLACK%^m%^RESET%^i%^BOLD%^%^WHITE%^s%^RESET%^m"+
       "%^BOLD%^%^BLACK%^a%^RESET%^t%^BOLD%^%^WHITE%^c%^RESET%^h"+
       "%^BOLD%^%^BLACK%^e%^RESET%^d %^BOLD%^%^WHITE%^rings she wears.  "+
       "As her %^RESET%^%^CYAN%^steady gaze %^BOLD%^%^WHITE%^falls upon "+
       "you, you realise that this must be the Lady of Fate - Lysara.  "+
       "In agony, you try to recall all you have done that might warrant "+
       "the deity's attention, and you squirm as you wait to hear "+
       "what she will say.  Finally, she speaks...\n");

    call_out("tris1", 10, tp);
    WHICH_CALL_OUT = "tris1";
    attempt_raise();
    return;
}

void tris1(object tp){
    object tmp;
    if(!objectp(tp)) return;
    if(!present(tp, TO)) return;
	if(PERMA_DEATH_D->is_perma_deathed(tp->query_name()))
	{
            tell_object(tp,"%^RESET%^%^MAGENTA%^Her lips do not move, but her ageless voice "+
            "echoes around you%^RESET%^: "+capitalize(tp->query_true_name())+
            ", you are here because I sense that your time is not yet "+
            "over, and your destiny is still incomplete.  I will take "+
            "the time to consider your life "+
            "and perhaps find value there.\n%^RESET%^");
		tell_object(tp, "%^BOLD%^%^RED%^You are suddenly "+
		"whisked away to the %^BOLD%^%^WHITE%^Afterlife%^BOLD%^"+
		"%^RED%^ where you must await final judgement.%^RESET%^");
		"/daemon/messaging_d"->first_death_message( "PKill Death",
		capitalize(tp->query_name())+"%^BOLD%^%^WHITE%^ "+
		"has been tossed into the afterlife, while "+
		tp->query_subjective()+" awaits the decision of the "+
		"gods.%^RESET%^",all_inventory(environment(tp)), ({ tp }) );

		tmp = new(DEATH_ROOM);
		if(tp->query_property("death_room")) tp->remove_property("death_room");
		tp->set_property("death_room", tmp);
		tp->move(tmp);
		//I figure this shit is easier than trying to edit a bunch of
		//stuff to make it so they can interact while in the afterlife - Saide
		//just set them back to a ghost when they leave the room again
		//tp->set_ghost(0);
		tp->remove_paralyzed();
		tp->describe_current_room(1);
		return;
	}
    tell_object(tp,"%^RESET%^%^MAGENTA%^Her lips do not move, but her ageless voice "+
       "echoes around you%^RESET%^: "+capitalize(tp->query_true_name())+
       ", you are here because I sense that your time is not yet "+
       "over, and your destiny is still incomplete.\n%^RESET%^");
    call_out("bane1", 7, tp);
    WHICH_CALL_OUT = "bane1";
    attempt_raise();
    return;
}

void begin_trial(object tp){
    if(!objectp(tp)) return;
    if(!present(tp, TO)) return;

    tell_object(tp, "You find yourself back in the empty hallway of the afterlife, and know that your "+
    "time of judgement has come.\n");
    call_out("bane1", 7, tp);
    TP->remove_property("trial");
    WHICH_CALL_OUT = "bane1";
    attempt_raise();
    return;
}

void bane1(object tp){
    if(!objectp(tp)) return;
    if(!present(tp, TO)) return;

    tell_object(tp,"Shades of your past come "+
       "to life, sending images of the things you have seen "+
       "and done dancing around you.  Actions for good and for "+
       "ill, each in turn, drift past you like long-forgotten memories.\n\n");
    if(tp->query_lowest_level() < 6) {
	call_out("newbie1", 8, tp);
    WHICH_CALL_OUT = "newbie1";
    attempt_raise();
    } else {
	call_out("do_death6", 8, tp);
    WHICH_CALL_OUT = "do_death6";
    attempt_raise();
    }
    return;
}

void newbie1(object tp){
    if(!objectp(tp)) return;
    if(!present(tp, TO)) return;

    tell_object(tp, "%^RESET%^%^MAGENTA%^Her lips do not move, but her ageless voice "+
       "echoes around you%^RESET%^:  I see that you have only begun in "+
       "this life of adventure.  You are still prone to make "+
       "mistakes, and - with hope - learn from them.  I "+
       "urge you... do not throw your life away needlessly.  "+
       "Look forward cautiously, and learn from all you do.  "+
       "Next time, you might not find me so willing to return you...\n");
    call_out("end_death",8, tp);
    WHICH_CALL_OUT = "end_death";
    attempt_raise();
    return;
}

void do_death6(object tp)
{
    mixed* deaths;
    int times;

    if (!objectp(tp)) {
        return;
    }
    if (!present(tp, TO)) {
        return;
    }

    deaths = tp->query_deaths();
    times = sizeof(deaths);

    tell_object(tp, "%^RESET%^%^MAGENTA%^Her lips do not move, but her ageless voice " +
                "echoes around you%^RESET%^:  " + capitalize(tp->query_true_name()) + ", " +
                "you have passed through these halls " + times + " times.%^RESET%^\n");
    if (times <= 25) {
        tell_object(tp, "%^RESET%^%^MAGENTA%^Her lips do not move, but her ageless voice " +
                    "echoes around you%^RESET%^:  I do hope you are learning from " +
                    "the things you do.  Your life has whatever value you " +
                    "give it.  If you do not treasure it, there is " +
                    "nothing left for you.%^RESET%^\n");
    }
    if ((times > 25) && (times < 50)) {
        tell_object(tp, "%^RESET%^%^MAGENTA%^Her lips do not move, but her ageless voice " +
                    "echoes around you%^RESET%^:  If you continue throwing your " +
                    "life away rashly, it will become harder to " +
                    "return to that life in the future.%^RESET%^\n");
    }
    if ((times >= 50) && (times < 100)) {
        tell_object(tp, "%^RESET%^%^MAGENTA%^Her lips do not move, but her ageless voice " +
                    "echoes around you%^RESET%^:  Do you " +
                    "have place any value on your life at all?  This is " +
                    "becoming a trend.%^RESET%^\n");
    }
    if (times > 100) {
        tell_object(tp, "%^RESET%^%^MAGENTA%^Her lips do not move, but her ageless voice " +
                    "echoes around you%^RESET%^:  Why should I let you " +
                    "go back...again?  Will you do anything other than " +
                    "throw your life away?%^RESET%^\n");
    }
    call_out("end_death", 6, tp);
    WHICH_CALL_OUT = "end_death";
    attempt_raise();
    return;
}

void do_death7(object tp){
    string deity;
    deity = tp->query_diety();
    if(!objectp(tp)) return;
    if(!present(tp, TO)) return;

    tell_object(tp,"The vision of Lysara begins to fade.\n");
    switch(deity){
       case "callamir":  tell_object(tp,"%^BOLD%^%^WHITE%^The "+
                       "darkness around you gives way to a "+
                       "pleasant light.  You feel weightless "+
                       "and almost giddy, and from all "+
                       "sides you hear an innocent %^YELLOW%^"+
                       "giggle %^WHITE%^welcoming you home.\n");
                    break;
       case "jarmila":  tell_object(tp,"%^BOLD%^%^BLACK%^A deep "+
                       "darkness surrounds you, leaving you "+
                       "%^RESET%^%^MAGENTA%^hopeless %^BOLD%^%^BLACK%^"+
                       "for the briefest moment.  Then suddenly, "+
                       "brilliant rays of the %^RESET%^%^MAGENTA%^s"+
                       "%^RED%^u%^BOLD%^%^RED%^n%^MAGENTA%^r%^RESET%^"+
                       "%^ORANGE%^i%^YELLOW%^s%^WHITE%^e %^YELLOW%^"+
                       "surround you, warming you and filling you "+
                       "with a sense of peace.\n");
                    break;
       case "kismet":  tell_object(tp,"%^BOLD%^%^BLUE%^A lively "+
                       "tune fills your ears, bringing with "+
                       "it the spark of creativity and the "+
                       "promise of knowledge to be discovered.  "+
                       "You find yourself in an endless library "+
                       "filled with tomes and scrolls as far as "+
                       "the eye can see, with music swirling in "+
                       "the air.\n");
                    break;
       case "kreysneothosies":  tell_object(tp,"%^BOLD%^%^BLUE%^The "+
                       "darkness around you is "+
                       "somber and complete.  Rather than feeling "+
                       "frightened or alone, however, you feel a "+
                       "strong sense of duty and pride.  Before "+
                       "you appears a simple vision, that of "+
                       "a sword crossing a sheaf of wheat.\n");
                    break;
       case "lord shadow":  tell_object(tp,"%^BOLD%^%^BLACK%^As the "+
                       "vision fades, the darkness around "+
                       "you gathers, slowly thickening "+
                       "and becoming complete.  A commanding voice "+
                       "gives a low chuckle, and you feel a rigid "+
                       "sense of belonging.\n");
                    break;
       case "lysara":  tell_object(tp,"The room arounds you fades "+
                       "to gray, and you begin to feel a great sense "+
                       "of loss tempered by an uplifting sense of "+
                       "purpose.  You begin to feel at ease in "+
                       "the realm of your Lady.\n");
                    break;
       case "nimnavanon": tell_object(tp,"%^RESET%^%^GREEN%^A gentle "
                       "%^CYAN%^breeze%^GREEN%^ rises on the air as "
                       "you imagine the softness of %^BOLD%^moss "
                       "%^RESET%^%^GREEN%^beneath your feet.  You "
                       "hear the creak of an ancient %^ORANGE%^oak "
                       "tree%^GREEN%^ before a calm, ponderous voice "
                       "begins to speak.\n");
                    break;
       case "the faceless one":  tell_object(tp,"The darkness around you is complete "+
                       "and unbroken, leaving you alone in the silence.  "+
                       "A soft, flickering light begins to scatter "+
                       "the darkness, creating %^BOLD%^%^BLACK%^"+
                       "dancing shadows %^RESET%^all around you.  "+
                       "Faint, echoing laughter touches your ears and you "+
                       "cannot help but smile.\n");
                    break;
       case "varda":  tell_object(tp,"%^RESET%^%^RED%^All around "+
                       "you are the sounds of battle.  Swords "+
                       "ring off armor amid the grunts and "+
                       "yells of soldiers fighting.  A sense of "+
                       "purpose swells in your heart, and you "+
                       "long to join your allies and foes alike in "+
                       "the thrill of battle.\n");
                    break;
       default:  tell_object(tp,"%^BOLD%^%^BLACK%^Darkness "+
                    "swirls around you, hiding Lysara from "+
                    "view.  You watch with dread as the %^RESET%^"+
                    "%^GREEN%^wall of souls %^BOLD%^%^BLACK%^seems "+
                    "to be forming around you once more.  It closes "+
                    "in around you, cutting off your air.\n\n");
                 break;
   }
    call_out("do_death8", 8, tp);
    WHICH_CALL_OUT = "do_death8";
    attempt_raise();
    return;
}

void do_death8(object tp){
    string deity;
    deity = tp->query_diety();

    if(!objectp(tp)) return;
    if(!present(tp, TO)) return;
    switch(deity){
       case "callamir":  tell_object(tp,"%^RESET%^%^MAGENTA%^A cheerful "+
                       "voice pipes with gaiety%^RESET%^:  "+
                       "%^BOLD%^%^MAGENTA%^Now, I know "+tp->QS+" "+
                       "didn't mean what happened..."+tp->QS+" "+
                       "just tried that when I wasn't looking.  "+
                       "Give "+tp->QO+" the good fortune to return, "+
                       "please?\n");
                    break;
       case "jarmila":  tell_object(tp,"%^RESET%^%^MAGENTA%^A voice "+
                       "speaks with the strength of hope%^RESET%^:  "+
                       "%^YELLOW%^This harbinger of dawn has much "+
                       "work left to do in my name.  I implore you to "+
                       "please send "+tp->QO+" back so "+tp->QS+" "+
                       "may continue.\n");
                    break;
       case "kismet":  tell_object(tp,"%^RESET%^%^MAGENTA%^A vibrant "+
                       "voice sings charmingly%^RESET%^:  "+
                       "%^BOLD%^The world needs those who inspire "+
                       "and enlighten!  If you would "+
                       "be so kind as to return "+tp->QO+", I "+
                       "am sure "+tp->QS+" will do well.\n");
                    break;
       case "kreysneothies":  tell_object(tp,"%^RESET%^%^MAGENTA%^An even "+
                       "voice dictates%^RESET%^:  %^BOLD%^%^WHITE%^"+
                       "In looking over the acts committed by "+
                       ""+capitalize(tp->query_true_name())+", I see "+
                       "no reason why "+
                       ""+tp->QS+" should stay here at rest.  "+
                       "There is much left to do, and it is only "+
                       "just that "+tp->QS+" returns to do it.\n");
                    break;
       case "lord shadow":  tell_object(tp,"%^RESET%^%^MAGENTA%^A commanding "+
                       "voice demands%^RESET%^:  "+
                       "%^BOLD%^This soul is bound to me and "+
                       "has much darkness and fear yet to spread in my "+
                       "name.  Release "+tp->QO+" to the world.\n");
                    break;
       case "lysara":  tell_object(tp,"%^RESET%^%^MAGENTA%^Lysara "+
                       "intones sternly%^RESET%^:  "+
                       "You know it is the place of my followers to "+
                       "grant those who are dying eternal rest.  Here, "+
                       "I am faced with a dilemma.  Your soul "+
                       "clearly longs to return, yet... should I allow "+
                       "this breach?\n");
                    break;
       case "nimnavanon":  tell_object(tp,"%^MAGENTA%^A calm, ponderous voice "
                       "speaks amidst the rustle of leaves%^RESET%^"+
                       ":%^GREEN%^ This one seeks to restore balance to the "
                       "realms in my name.  Please send "+tp->QO+" back so "
                       ""+tp->QS+" can continue to be a much-needed source "
                       "of balance in a turbulent world.\n");
                    break;
       case "the faceless one":  tell_object(tp,"%^RESET%^%^MAGENTA%^A chorus "+
                       "of maddening voices whisper%^RESET%^:  "+
                       "%^BOLD%^%^BLACK%^This servant of deception "+
                       "has much left to do in the realms in "+
                       "my name... "+tp->QS+" must be returned.\n");
                    break;
       case "varda":  tell_object(tp,"%^RESET%^%^MAGENTA%^A dauntless "+
                       "voice states%^RESET%^:  %^BOLD%^%^RED%^"+
                       "The field of battle is riddled with dangers.  "+
                       "So long as "+tp->QS+" faced them all "+
                       "fearlessly, I say return "+tp->QO+" to "+
                       "the glory "+tp->QS+" has earned.\n");
                    break;
       default:  tell_object(tp,"%^RESET%^%^GREEN%^The hideous wall "+
                    "begins to wrap itself around you, draining you "+
                    "of all heat and thought.  In agony, you look "+
                    "up, but find nothing there - no light, no heat..."+
                    "not a single soul watching.\n\n");
                 break;
    }
    call_out("do_death9",5, tp);
    WHICH_CALL_OUT = "do_death9";
    attempt_raise();
    return;
}

void do_death9(object tp){
    string deity;
    deity = tp->query_diety();

    if(!objectp(tp)) return;
    if(!present(tp, TO)) return;

    if(deity == "lysara"){
       tell_object(tp,"Lysara is silent for a moment, clearly "+
          "in thought.  She leaves you to remember all of the things "+
          "you have done and question the state of your soul... should "+
          "you be allowed to return?\n");
    call_out("do_death10", 8, tp);
    WHICH_CALL_OUT = "do_death10";
    attempt_raise();
    return;
    }
    if(!tp->query_diety() || (string)tp->query_diety() == "pan" || (string)tp->query_diety() == "godless"){
       tell_object(tp,"%^BOLD%^%^BLACK%^The darkness closes around "+
          "you as your flesh begins to tingle.  You feel a burning, "+
          "much like %^GREEN%^acid%^BLACK%^, and you cry out in "+
          "%^RED%^pain%^BLACK%^.  The only answer is the insane "+
          "mumblings and screams of those souls around you, sharing "+
          "a like torment.\n\n");
       call_out("no_god", 12, tp);
       WHICH_CALL_OUT = "no_god";
       attempt_raise();
       return;
    }
    tell_object(tp,"All is silent for a moment before, finally, you "+
       "hear a voice.\n");
    tell_object(tp,"%^RESET%^%^MAGENTA%^Lysara intones sternly"+
       "%^RESET%^: "+
       "Yes, yes, I know your request, but this is my realm.  "+
       "None should leave without good cause.\n");
    tell_object(tp,"She sighs lightly and thinks a long moment.");
    tell_object(tp,"%^RESET%^%^MAGENTA%^Lysara intones sternly"+
       "%^RESET%^: "+
       "Very well...will you assure me that this servant will be "+
       "faithful to you and do your bidding?\n");
    call_out("do_death10", 8, tp);
    WHICH_CALL_OUT = "do_death10";
    attempt_raise();
    return;
}

void no_god(object tp){

    if(!objectp(tp)) return;
    if(!present(tp, TO)) return;
    tell_object(tp,"%^BOLD%^%^BLACK%^You feel the %^GREEN%^wall "+
       "%^BLACK%^pulling you in, deeper and deeper.  Grotesque "+
       "visions fill your mind - images of %^RESET%^%^RED%^demons "+
       "%^BOLD%^%^BLACK%^and %^RESET%^%^RED%^devils %^BOLD%^"+
       "%^BLACK%^emerging from the lower planes, ripping "+
       "half-consumed souls from the wall to serve them in "+
       "endless agony.\n\n");
    call_out("no_god2", 12, tp);
    WHICH_CALL_OUT = "no_god2";
    attempt_raise();
    return;
}

void no_god2(object tp){

    if(!objectp(tp)) return;
    if(!present(tp, TO)) return;
    tell_object(tp,"%^BOLD%^%^BLACK%^With dismay, you see "+
       "one of the foul beasts coming straight toward you, "+
       "his %^RED%^barbed skin %^BLACK%^glistening with "+
       "%^RED%^blood%^BLACK%^.  You close your eyes, but "+
       "he is still there, reaching, clawing...\n\n");
    call_out("no_god3", 12, tp);
    WHICH_CALL_OUT = "no_god3";
    attempt_raise();
    return;
}

void no_god3(object tp){

    if(!objectp(tp)) return;
    if(!present(tp, TO)) return;
    tell_object(tp,"%^BOLD%^%^BLACK%^The %^RED%^devil %^BLACK%^"+
       "pulls a soul from the wall just beside you, one "+
       "half-consumed, a %^GREEN%^sickly green %^BLACK%^"+
       "the color of putrid swamp vapors.  The twisted soul "+
       "is riddled with holes, little more now than a "+
       "sensor for %^RED%^pain%^BLACK%^.  The soul's screams "+
       "flood your mind, making you shudder to the core.\n\n");
    call_out("do_death10", 12, tp);
    WHICH_CALL_OUT = "do_death10";
    attempt_raise();
    return;
}

void do_death10(object tp){
    string deity;
    deity = tp->query_diety();

    if(!objectp(tp)) return;
    if(!present(tp, TO)) return;
    switch(deity){
       case "callamir":  tell_object(tp,"%^RESET%^%^MAGENTA%^A cheerful "+
                       "voice pipes with gaiety%^RESET%^:  "+
                       "%^BOLD%^%^MAGENTA%^I bring good fortune "+
                       "to my followers and in turn, they bring "+
                       "faith in me.  Why would "+tp->QS+" ever "+
                       "thrust me aside?\n");
                    break;
       case "jarmila":  tell_object(tp,"%^RESET%^%^MAGENTA%^A voice "+
                       "speaks with the strength of hope%^RESET%^:  "+
                       "%^YELLOW%^Through rebirth, my will is done.  "+
                       "By knowing the glory of renewal, "+tp->QS+" "+
                       "will be better able to serve me.\n");
                    break;
       case "kismet":  tell_object(tp,"%^RESET%^%^MAGENTA%^A vibrant "+
                       "voice sings charmingly%^RESET%^:  "+
                       "%^BOLD%^I am sure "+tp->QS+" will spend "+
                       ""+tp->QP+" time gathering and spreading "+
                       "knowledge.  "+
                       "The world needs those with creativity and "+
                       "ingenuity!  Please return "+tp->QO+" to "+
                       "my service.\n");
                    break;
       case "kreysneothosies":  tell_object(tp,"%^RESET%^%^MAGENTA%^An even "+
                       "voice dictates%^RESET%^:  %^BOLD%^%^WHITE%^"+
                       "All of my followers know that acts are "+
                       "punished or rewarded as they deserve.  "+
                       "I do not think "+tp->QS+" would be so "+
                       "foolish as to abandon me.\n");
                    break;
       case "lord shadow":  tell_object(tp,"%^RESET%^%^MAGENTA%^A commanding "+
                       "voice demands%^RESET%^:  "+
                       "%^BOLD%^%^BLACK%^Oh, "+tp->QS+" will serve "+
                       "me.  There can be no doubt about that.\n");
                    break;
       case "lysara":  tell_object(tp,"%^RESET%^%^MAGENTA%^Lysara "+
                       "intones sternly%^RESET%^:  "+
                       "I can allow you to return only to continue "+
                       "my good work.  Seek out those in need of "+
                       "rest and aid them through to the other side.\n");
                    break;
       case "nimnavanon":  tell_object(tp,"%^MAGENTA%^A calm, ponderous voice "
                       "speaks amidst the rustle of leaves%^RESET%^"+
                       ":%^GREEN%^ The denizens of the world are ever-active "
                       "in causing turmoil and strife.  I am assured that "
                       ""+tp->QS+" will continue to seek to temper madness with harmony.\n");
                    break;
       case "the faceless one":  tell_object(tp,"%^RESET%^%^MAGENTA%^A chorus "+
                       "of maddening voices whisper%^RESET%^:  "+
                       "%^BOLD%^%^BLACK%^Oh, now...I think "+tp->QS+" "+
                       "knows better than to betray me.\n");
                    break;
       case "varda":  tell_object(tp,"%^RESET%^%^MAGENTA%^A dauntless "+
                       "voice states%^RESET%^:  %^BOLD%^%^RED%^"+
                       "One of mine will never turn aside from the "+
                       "field of battle.  I know "+tp->QS+" will "+
                       "serve me well.\n");
                    break;
       default:  tell_object(tp,"%^RESET%^Miraculously, all stops "+
                    "for a moment, and you hear a voice from above.\n\n"+
                    "%^MAGENTA%^Lysara intones sternly%^RESET%^:  "+
                    "This is the fate that awaits you, should you "+
                    "remain faithless and lost.  This wall "+
                    "dissolves souls, eating away at them until "+
                    "nothing remains.\n\n");
                    call_out("no_god4", 10, tp);
                    WHICH_CALL_OUT = "no_god4";
                    attempt_raise();
                    return;
    }
    call_out("end_death", 10, tp);
    WHICH_CALL_OUT = "end_death";
    attempt_raise();
    return;
}

void no_god4(object tp){
    if(!objectp(tp)) return;
    if(!present(tp, TO)) return;
       tell_object(tp,"She sighs quietly and looks at you "+
          "sternly.\n\n");
       tell_object(tp,"%^RESET%^%^MAGENTA%^Lysara intones "+
          "sternly%^RESET%^:  Do you see now what you have in "+
          "store for you?  This is not a game...this is your "+
          "soul you are playing with.\n\n");
       tell_object(tp,"She studies you quietly before "+
          "speaking.\n\n");
    call_out("end_death", 10, tp);
    WHICH_CALL_OUT = "end_death";
    attempt_raise();
    return;
}

void end_death(object tp)
{
    if(!objectp(tp)) return;
    if(!present(tp, TO)) return;
    tell_object(tp, "%^RESET%^%^MAGENTA%^Her lips do not move, but her ageless voice "+
       "echoes around you%^RESET%^:  The turn of fate's wheel does not decree that "+
       "your time is yet finished.  But do not take this in arrogance.  All things "+
       "have an ending, and yours will come far more swiftly should you be careless "+
       "with this opportunity.\n\n");
    call_out("end_death2", 8, tp);
    WHICH_CALL_OUT = "end_death2";
    attempt_raise();
    return;
}

void end_death2(object tp)
{
    string deity;
    if (!objectp(tp)) {
        return;
    }
    if (!present(tp, TO)) {
        return;
    }
    deity = tp->query_diety();
    switch (deity) {
    case "lysara":
        tell_object(tp, "%^RESET%^%^MAGENTA%^Her unwavering gaze weighs upon your soul as " +
                    "she speaks%^RESET%^:  The mark of my own divine power is upon you, which will " +
                    "protect you from the worst effects of restoration.  Remain true to my " +
                    "calling, for the final fate of the faithless is only the wall...\n\n");
        break;
    case "pan": case "godless":
        tell_object(tp, "%^RESET%^%^MAGENTA%^Her unwavering gaze weighs upon your soul as " +
                    "she speaks%^RESET%^:  Brace yourself, for with no patron to protect your soul, you " +
                    "will find yourself terribly weakened in being restored to life.  I suggest you consider " +
                    "your choices carefully, for the final fate of the faithless is only the wall...\n\n");
        break;
    default:
        tell_object(tp, "%^RESET%^%^MAGENTA%^Her unwavering gaze weighs upon your soul as " +
                    "she speaks%^RESET%^:  I sense the mark of " + capitalize(deity) + " upon you, which will " +
                    "protect you from the worst effects of restoration.  Remain true to your patron and your " +
                    "calling, for the final fate of the faithless is only the wall...\n\n");
        break;
    }
    call_out("end_death3", 8, tp);
    WHICH_CALL_OUT = "end_death3";
    attempt_raise();
    return;
}

void end_death3(object tp)
{
    if (!objectp(tp)) {
        return;
    }
    if (!present(tp, TO)) {
        return;
    }

    tell_object(tp, "A mist forms " +
                "over your eyes.  When you open them again, you are in a " +
                "strange room filled with portals.\n\n");
    if (tp->query_highest_level() < 7) {
        tp->move_player("/d/shadowgate/death/death_exit_offestry");
    }else {
        tp->move_player("/d/shadowgate/death/death_exit");
    }
    return;
}

void end_death0_feytouched(object tp)
{
    if(!objectp(tp)) return;
    if(!present(tp, TO)) return;
    tell_object(TP,"%^BOLD%^%^WHITE%^The burdens of your world s%^RESET%^p%^BOLD%^%^BLACK%^ir%^RESET%^a%^BOLD%^l away, replaced by something so much more. More %^GREEN%^v%^RESET%^%^GREEN%^i%^MAGENTA%^b%^BOLD%^ra%^RESET%^%^MAGENTA%^n%^GREEN%^c%^BOLD%^y%^WHITE%^, more %^ORANGE%^li%^RESET%^g%^ORANGE%^h%^BOLD%^t%^WHITE%^, more %^MAGENTA%^m%^RESET%^%^MAGENTA%^a%^BOLD%^gic%^WHITE%^, as you fall freely now, faster, as weightless as %^RESET%^s%^BOLD%^%^BLACK%^t%^WHITE%^ar%^RESET%^s%^BOLD%^hi%^BLACK%^n%^RESET%^e%^BOLD%^.%^RESET%^\n");
    call_out("end_death1_feytouched", 5, tp);
}
void end_death1_feytouched(object tp)
{
    if(!objectp(tp)) return;
    if(!present(tp, TO)) return;
    tell_object(TP,"%^RESET%^%^CYAN%^The %^BOLD%^pulse %^RESET%^%^CYAN%^of the new land beats to the rhythm of your own. %^WHITE%^\n");
    call_out("end_death2_feytouched", 5, tp);
}
void end_death2_feytouched(object tp)
{
    if(!objectp(tp)) return;
    if(!present(tp, TO)) return;
    tell_object(TP,"%^RESET%^%^MAGENTA%^Pulse. Filling you with life untainted.%^WHITE%^\n");
    call_out("end_death3_feytouched", 5, tp);
}
void end_death3_feytouched(object tp)
{
    if(!objectp(tp)) return;
    if(!present(tp, TO)) return;
    tell_object(TP,"%^BOLD%^%^MAGENTA%^Pulse. Filling you with magic unfettered. %^RESET%^\n");
    call_out("end_death4_feytouched", 5, tp);
}
void end_death4_feytouched(object tp)
{
    if(!objectp(tp)) return;
    if(!present(tp, TO)) return;
    tell_object(TP,"%^BOLD%^%^CYAN%^Pulse. Boundaries constructed in a lifetime a world away begin to unravel. You try to cling to the memories but feel them splintering apart.%^RESET%^\n");
    call_out("end_death5_feytouched", 10, tp);
}
void end_death5_feytouched(object tp)
{
    if(!objectp(tp)) return;
    if(!present(tp, TO)) return;
    tell_object(TP,"%^BOLD%^%^GREEN%^With a jolt, you find yourself standing in a verdant, primitive %^RESET%^%^GREEN%^forest %^BOLD%^surrounded by tangled trees, their %^RESET%^%^ORANGE%^branches %^BOLD%^%^GREEN%^lost to the %^RESET%^mists %^BOLD%^%^GREEN%^far overhead. You are awestruck in the presence of this living, breathing place. An entity as ancient as the beginning of time. %^RESET%^\n");
    call_out("end_death6_feytouched", 5, tp);
}
void end_death6_feytouched(object tp)
{
    if(!objectp(tp)) return;
    if(!present(tp, TO)) return;
    tell_object(TP,"%^RESET%^%^GREEN%^A million eyes watch you. The rustling of the leaves speak your name... a greeting. Or is it a %^BOLD%^warning%^RESET%^%^GREEN%^? %^WHITE%^\n");
    call_out("end_death7_feytouched", 5, tp);
}
void end_death7_feytouched(object tp)
{
    if(!objectp(tp)) return;
    if(!present(tp, TO)) return;
    tell_object(TP,"%^RESET%^%^CYAN%^The %^BOLD%^pulse %^RESET%^%^CYAN%^of the world continues to beat against your very essence, shattering edges. And this bright land without limitations begins to %^BOLD%^%^BLACK%^consume %^RESET%^%^CYAN%^your senses...%^WHITE%^\n");
    call_out("end_death8_feytouched", 5, tp);
}
void end_death8_feytouched(object tp)
{
    if(!objectp(tp)) return;
    if(!present(tp, TO)) return;
    tell_object(TP,"%^BOLD%^%^WHITE%^Your surroundings start to b%^RESET%^lu%^BOLD%^%^BLACK%^r %^WHITE%^until you feel as if your heart might burst with %^GREEN%^v%^RESET%^%^GREEN%^it%^BOLD%^al%^RESET%^%^GREEN%^it%^BOLD%^y%^WHITE%^, and your mind might %^BLACK%^crack %^WHITE%^into pieces, or overflow with the %^RESET%^%^RED%^c%^BOLD%^%^MAGENTA%^ol%^RESET%^%^RED%^o%^MAGENTA%^r%^BOLD%^s of m%^RESET%^%^MAGENTA%^a%^BOLD%^gi%^RESET%^%^RED%^c%^BOLD%^%^WHITE%^, or become one with the %^CYAN%^wild s%^RESET%^%^CYAN%^o%^BOLD%^ng %^WHITE%^of an %^GREEN%^u%^RESET%^%^GREEN%^n%^ORANGE%^t%^BOLD%^%^GREEN%^am%^RESET%^%^GREEN%^e%^BOLD%^d %^RESET%^%^ORANGE%^w%^GREEN%^o%^BOLD%^rl%^RESET%^%^GREEN%^d%^BOLD%^%^WHITE%^.%^RESET%^\n");
    call_out("end_death9_feytouched", 15, tp);
}
void end_death9_feytouched(object tp)
{
    if(!objectp(tp)) return;
    if(!present(tp, TO)) return;
    tell_object(TP,"%^BOLD%^%^BLACK%^From within yourself, a voice:%^RESET%^\n
%^RESET%^%^ORANGE%^\"You do not belong here. Not yet.\"%^WHITE%^\n");
    call_out("end_death3", 5, tp);
    WHICH_CALL_OUT = "end_death3";
}

void end_death0_undead(object tp)
{
    if(!objectp(tp)) return;
    if(!present(tp, TO)) return;
    tell_object(TP,"\n%^BOLD%^BLACK%^WEAK.\n");
    call_out("end_death1_undead",5,tp);
}
void end_death1_undead(object tp)
{
    if(!objectp(tp)) return;
    if(!present(tp, TO)) return;
    tell_object(TP,"\n%^BOLD%^BLACK%^YOU ARE WEAK.\n");
    call_out("end_death2_undead",5,tp);
}
void end_death2_undead(object tp)
{
    if(!objectp(tp)) return;
    if(!present(tp, TO)) return;
    tell_object(TP,"\n%^BOLD%^BLACK%^PATHETIC.\n");
    call_out("end_death3_undead",5,tp);
}
void end_death3_undead(object tp)
{
    if(!objectp(tp)) return;
    if(!present(tp, TO)) return;
    tell_object(TP,"\n%^BOLD%^BLACK%^I HAVE %^WHITE%^NO TIME%^BLACK%^ FOR YOUR FOOLISHNESS.\n");
    call_out("end_death4_undead",5,tp);
}
void end_death4_undead(object tp)
{
    if(!objectp(tp)) return;
    if(!present(tp, TO)) return;
    tell_object(TP,"\n%^BOLD%^BLACK%^GO AWAY.\n");
    call_out("end_death3", 5, TP);
    WHICH_CALL_OUT = "end_death3";
}

void end_death0_vampire(object tp)
{
    if(!objectp(tp)) return;
    if(!present(tp, TO)) return;
    tell_object(TP,"\n%^CYAN%^Come with me in the twilight of a summer night for a while\n");
    call_out("end_death1_vampire",5,tp);
}
void end_death1_vampire(object tp)
{
    if(!objectp(tp)) return;
    if(!present(tp, TO)) return;
    tell_object(TP,"\n%^CYAN%^Tell me of a story never ever told in the past\n");
    call_out("end_death2_vampire",5,tp);
}
void end_death2_vampire(object tp)
{
    if(!objectp(tp)) return;
    if(!present(tp, TO)) return;
    tell_object(TP,"\n%^CYAN%^Take me back to the land where my yearnings were born\n");
    call_out("end_death3_vampire",5,tp);
}
void end_death3_vampire(object tp)
{
    if(!objectp(tp)) return;
    if(!present(tp, TO)) return;
    tell_object(TP,"\n%^CYAN%^The key to open the door is in your hand\n");
    call_out("end_death4_vampire",5,tp);
}
void end_death4_vampire(object tp)
{
    if(!objectp(tp)) return;
    if(!present(tp, TO)) return;
    tell_object(TP,"\n%^CYAN%^Now fly me there\n");
    call_out("end_death3", 5, TP);
    WHICH_CALL_OUT = "end_death3";
}
