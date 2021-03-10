//Added Auppenser, Sune, Beshaba, and Shaundakul - Cythera 8/05
//Added Silvanus - N, 3/13.
#include <std.h>
#include <priest.h>

inherit OBJECT;

#define ACTIVETEMPLES ({ "jarmila","kreysneothosies","lord shadow","nimnavanon","lysara","callamir","nilith","kismet","ryorik","varda","the faceless one"})
object ob;

void create() 
{
    ::create();
    set_name("godsfavor");
    set("id", ({ "remotexoli"}) );
    set_short("");
    set_long("");
    set_property("no animate", 1);
    set_weight(0);
}

void init() {
    ::init();
    add_action("now","now");
}


int clean_up()
{
    if(!objectp(TO)) { return 1; }
    if(objectp(ETO)) { return 1; }
    destruct(TO);
    return 1;
}


void dest_effect()
{
    destruct(TO);
}


void remove()
{
    if(objectp(PO))
    {
        if(!avatarp(PO) && (strsrch(base_name(PO),"_gods") == -1)) { return; }
    }
    destruct(TO);
}


int save_me(string file) {
    return 1;
}


int now(string str){
   string where, temple, diety;
   int mypower,startpower,endpower,bonus;
   object place;
   diety = TP->query_diety();

   if(member_array(diety,ACTIVETEMPLES) != -1) {
      temple = "Temple of "+capitalize(diety);
      diety = replace_string(diety," ","_");
      where = "/d/magic/temples/"+diety+"/"+diety;
   }
   else{
      tell_object(TP,"You need to follow a god to be saved by one.");
      dest_effect();
      return 0;
   }
   if (environment(TP)->query_property("no teleport")) {
      tell_object(TP,"Even "+diety+" is unable to save you from here.");
      dest_effect();
      return 0;
   }
//teleport proof stuff by ~Circe~ 6/20/08
//new property to be used for areas protected from teleport 
//but not foolproof
   place = ETP;
   if(where && 
      (where->query_property("teleport proof") ||
      place->query_property("teleport proof") ||
      !where->is_room())){
      startpower = place->query_property("teleport proof");
      endpower = where->query_property("teleport proof");
     bonus = TP->query_stats("wisdom");
      bonus = bonus -10;
      if((object *)TP->query_attackers() != ({})){
         mypower = (int)TP->query_level("cleric") + bonus + random(6);
      }else{
         mypower = (int)TP->query_level("cleric") + bonus + random(6) + 5;
//making it easier to teleport out if you aren't in combat
      }
      if((mypower < startpower) || (mypower < endpower)){
         tell_object(TP,"Even "+diety+" is unable to save you from here.");
         dest_effect();
         return 0;
      }
   }
   if(ETP->is_temple() && (string)ETP->query_diety() == diety){
      tell_object(TP,"You are already in your temple!");
      dest_effect();
      return 1;
   }
   switch(lower_case(diety)) {
      case "pan":
         tell_object(TP,"You must have a god to use this spell.");
         dest_effect();
         break;
      case "akadi":
         tell_object(TP,"%^BOLD%^%^WHITE%^You hear soothing whispers in"+
		" the wind and feel lighter than air as you become one with"+
		" the winds of Akadi and are swept away!");
         tell_room(environment(ETO), "%^BOLD%^%^WHITE%^A cyclone of wind"+
		" suddenly errupts around "+TPQCN+" and "+TP->QP+" "+
		"body seems to soften and is dispersed in a cloudlike whisp of"+
		" air before being swept away by the wind!", ({TP}));
         tell_room(find_object_or_load(where),"%^BOLD%^%^WHITE%^A hazy cyclone"+
		" suddenly sweeps into the area, dispersing as it arrives to reveal"+
		" the wispy shape of "+TPQCN+".",TP);
         TP->move_player(where);
         tell_object(TP,"%^BOLD%^%^WHITE%^The winds slow and you sigh wistfully"+
		" as your body begins to take shape again as you are released from"+
		" Akadi's embrace.");
         dest_effect();
      break;
      case "anhur":
         tell_object(TP,"%^BOLD%^%^RED%^You hear the steady beat of "+
            "the drums of war rise around you as a %^BLUE%^war banner "+
            "%^RED%^whips about on the wind, wrapping itself around you!%^RESET%^");
         tell_room(EETO, "%^BOLD%^%^RED%^The steady beat of the drums "+
            "of war rise suddenly in the air as a %^BLUE%^war banner "+
            "%^RED%^whips about on the wind, wrapping itself around "+
            ""+TPQCN+"!%^RESET%^", ({TP}));
         tell_room(find_object_or_load(where),"%^BOLD%^%^BLUE%^A "+
            "%^RED%^war banner%^BLUE%^ suddenly appears in midair, "+
            "whipping on the wind as it unfurls to reveal "+TPQCN+"!%^RESET%^",TP);
         TP->move_player(where);
         tell_object(TP,"%^BOLD%^%^BLUE%^The strong wind blows again, "+
            "ripping the %^RED%^war banner %^BLUE%^from you as it "+
            "leaves you at the altar of %^RED%^Anhur%^BLUE%^!%^RESET%^");
         dest_effect();
      break;
	case "auppenser":
         tell_object(TP,"%^BOLD%^%^CYAN%^Shards of %^WHITE%^c%^RED%^r%^YELLOW%^y"+
		"%^GREEN%^s%^BLUE%^t%^MAGENTA%^a%^RESET%^%^CYAN%^l%^MAGENTA%^s%^BOLD%^"+
		"%^CYAN%^ fly through the air and forms a protective coccon around you."+
		"   A %^RESET%^%^ORANGE%^bronze%^BOLD%^%^CYAN%^ light bursts forth "+
		"within the crystal and you feel yourself pulled away.");
         tell_room(environment(ETO),"%^BOLD%^%^CYAN%^Shards of %^WHITE%^c%^RED%^"+
		"r%^YELLOW%^y%^GREEN%^s%^BLUE%^t%^MAGENTA%^a%^RESET%^%^CYAN%^l"+
		"%^MAGENTA%^s%^BOLD%^%^CYAN%^ fly through the air and forms "+
		"a protective coccon around "+TPQCN+".   A %^RESET%^%^ORANGE%^"+
		"bronze%^BOLD%^%^CYAN%^ light bursts forth "+
		"within the crystal, taking it and "+TPQCN+" with it!",TP);
         tell_room(find_object_or_load(where),"%^BOLD%^%^CYAN%^A %^BOLD%^"+
		"%^WHITE%^c%^RED%^r%^YELLOW%^y%^GREEN%^s%^BLUE%^t%^MAGENTA%^a"+
		"%^RESET%^%^MAGENTA%^l%^BOLD%^%^CYAN%^ appears in a burst of "+
		"%^RESET%^%^ORANGE%^bronze%^BOLD%^%^CYAN%^ lights.  The crystal"+
		" cracks and falls apart, revealing "+TPQCN+"!",TP);
         TP->move_player(where);
         tell_object(TP,"%^BOLD%^%^CYAN%^You feel a %^RESET%^%^ORANGE%^bronze"+
		"%^BOLD%^%^CYAN%^ light wash over you and reflect off the facets "+
		"of the %^BOLD%^%^WHITE%^c%^RED%^r%^YELLOW%^y%^GREEN%^s%^BLUE%^t%^MAGENTA%^a"+
		"%^RESET%^%^MAGENTA%^l%^BOLD%^%^CYAN%^.  The crystal cracks and"+
		" falls apart, leaving you before the altar of Auppenser!");
         dest_effect();
      break;
	case "auril":
         tell_object(TP,"%^BOLD%^%^CYAN%^You feel your blood run like ice as "+
		"Auril's killing frost envelops you and all goes dark!");
         tell_room(environment(ETO), "%^BOLD%^%^CYAN%^A sheet of frost spreads"+
		" along "+TPQCN+"'s body, encasing "+TP->QO+" before"+
		" bursting violently outward leaving slowly descending snowflakes "+
		"where "+TP->QS+" once stood!",TP);
         tell_room(find_object_or_load(where),"%^BOLD%^%^CYAN%^A pillar of ice"+
		" climbs upward from the floor, cracks spreading across its length"+
		" before shattering to reveal a frost covered "+TPQCN+".",TP);
         TP->move_player(where);
         tell_object(TP,"%^BOLD%^%^CYAN%^You feel the cold touch of your goddess"+
		" stir you to life.  Flexing your limbs you burst free from your icy embrace.");
         dest_effect();
      break;
      case "bane":
         tell_object(TP,"%^BOLD%^%^GREEN%^Your vision flares green and your form"+
		" flickers as the %^BLACK%^Black hand %^GREEN%^reclaims you!");
         tell_room(environment(ETO),"%^BOLD%^%^GREEN%^Green fire bursts from"+
		" "+TPQCN+"'s eyes as "+TP->QP+" form shimmers %^BLACK%^wraithlike"+
		" %^GREEN%^before vanishing completely!",TP);
         tell_room(find_object_or_load(where),"%^BOLD%^%^BLACK%^A peel of thunder"+
		" echoes throughout the temple as %^GREEN%^shimmering green flames"+
		" %^BLACK%^burst to life before the altar revealing the kneeling "+
		"form of "+TPQCN+"!",TP);
         TP->move_player(where);
         tell_object(TP,"%^BOLD%^%^BLACK%^You feel the overwhelming presence of"+
		" the Black Hand within the blinding %^GREEN%^flames %^BLACK%^forcing"+
		" you to your knees.  The %^GREEN%^flames %^BLACK%^slowly flicker and"+
		" die, leaving you before the mighty likeness of your lord.");
         dest_effect();
      break;
	case "beshaba":
         tell_object(TP,"%^BOLD%^%^MAGENTA%^A whirling mass of %^BOLD%^%^BLACK%^"+
		"gloomwing moths%^BOLD%^%^MAGENTA%^ encircle you.  You feel "+
		"yourself being pulled away as a wild laughter echoes around you!");
         tell_room(environment(ETO),"%^BOLD%^%^MAGENTA%^A whirling mass of "+
		"%^BOLD%^%^BLACK%^gloomwing moths%^BOLD%^%^MAGENTA%^ encircles"+
		" "+TPQCN+", hiding "+TP->QCN+" from sight as a wild laughter "+
		"echoes around you.  The moths dissolve away and "+TPQCN+" is gone!",TP);
         tell_room(find_object_or_load(where),"%^BOLD%^%^RED%^A whirling mass of "+
		"%^BOLD%^%^BLACK%^gloomwing moths%^BOLD%^%^RED%^ appears in "+
		"the temple.  A crackling red burst of light shoots out of "+
		"the mass of moths.  The moths fades away and "+TPQCN+" appears!",TP);
         TP->move_player(where);
         tell_object(TP,"%^BOLD%^%^RED%^Your vision is clouded by some "+
		"%^BOLD%^%^BLACK%^whirling%^BOLD%^%^RED%^ shapes.  A burst of "+
		"crackling red light blinds you momentarily as the shapes fade"+
		" away.  Slowly you open your eyes and find yourself before Beshaba's altar!");
         dest_effect();
      break;
	case "cyric":
         tell_object(TP,"%^BOLD%^%^BLACK%^You hear a sinister whispering in "+
		"your ear as you fade from sight.");
         tell_room(environment(ETO),"%^RESET%^%^BLUE%^"+TPQCN+" dissolves in "+
		"a whirl of %^BOLD%^%^WHITE%^"+(TP->query_race())+" skulls, "+
		"%^RESET%^%^BLUE%^leaving nothing behind but two %^BOLD%^%^BLACK%^"+
		"black eyes %^RESET%^%^BLUE%^that fade slowly!",TP);
         tell_room(find_object_or_load(where),"%^BOLD%^%^BLACK%^A whirl of "+
		"%^WHITE%^"+(TP->query_race())+" skulls %^BLACK%^appears before "+
		"the altar and fades quickly, leaving "+TPQCN+" kneeling.",TP);
         TP->move_player(where);
         tell_object(TP,"%^RESET%^%^BLUE%^The strength of %^BOLD%^%^BLACK%^Cyric"+
		" %^RESET%^%^BLUE%^rips from your body, leaving you kneeling before "+
		"his altar with a vision of %^BOLD%^%^BLACK%^two black eyes %^RESET%^"+
		"%^BLUE%^searing into your mind.");
         dest_effect();
      break;
      case "grumbar":
         tell_object(TP,"%^RESET%^%^ORANGE%^You call the favor of Grumbar and feel"+
		" yourself sink into the earth as it welcomes you home.");
         tell_room(environment(ETO),"%^RESET%^%^ORANGE%^Rich brown earth rises at "+
		"the feet of "+TPQCN+", and "+TP->QS+" sinks quickly from sight!",TP);
         tell_room(find_object_or_load(where),"%^RESET%^%^ORANGE%^"+TPQCN+" bursts"+
		" forth from the earth and lands kneeling before the altar.",TP);
         TP->move_player(where);
         tell_object(TP,"%^RESET%^%^ORANGE%^The embrace of the earth releases you,"+
		" leaving you kneeling before the altar of your lord.");
         dest_effect();
      break;
      case "helm":
         tell_object(TP,"%^BOLD%^%^BLUE%^You see an unblinking eye before you and "+
		"feel the strong will of Helm envelope you, whisking you from harm!");
         tell_room(environment(ETO),"%^BOLD%^%^BLUE%^An unblinking eye appears in "+
		"the air before "+TPQCN+" and "+TP->QS+" is gone in a flash of "+
		"brilliant light!",TP);
         tell_room(find_object_or_load(where),"%^BOLD%^%^BLUE%^A %^YELLOW%^flash "+
		"%^BLUE%^of %^YELLOW%^light %^BLUE%^blinds you briefly!  As you open "+
		"your eyes again, you see "+TPQCN+" kneeling before the altar.",TP);
         TP->move_player(where);
         tell_object(TP,"%^BOLD%^%^BLUE%^The Guardian's watchful eye leaves you "+
		"kneeling before his altar, safe from harm.");
         dest_effect();
      break;
      case "istishia":
         tell_object(TP,"%^BOLD%^%^CYAN%^You suddenly stop breathing as you feel "+
		"your body become water and you melt away.");
         tell_room(environment(ETO),"%^BOLD%^%^CYAN%^"+TPQCN+"'s skin glitters "+
		"iridescently before "+TP->QS+" liquifies and fades from view!",TP);
         tell_room(find_object_or_load(where),"%^BOLD%^%^CYAN%^"+TPQCN+" suddenly"+
		" solidifies before the altar, gasping for breath!",TP);
         TP->move_player(where);
         tell_object(TP,"%^BOLD%^%^CYAN%^Your body returns with a jolt, and you "+
		"find yourself gasping for breath before the altar of Istishia!");
         dest_effect();
      break;
      case "kelemvor":
         tell_object(TP,"%^RESET%^You hear a wailing wind and your vision fades "+
		"as you feel yourself whisked away!");
         tell_room(environment(ETO),"A wailing wind rises as "+TPQCN+" suddenly"+
		" seems to be nothing more than a skull barely visible beneath a "+
		"deeply hooded robe.  The wind gusts violently, and "+TPQCN+" is gone!",TP);
         tell_room(find_object_or_load(where),""+TPQCN+" begins to manifest slowly,"+
		" surrounded by the transluscent image of a ghostly shroud.  The shroud"+
		" fades, leaving "+TPQCN+" kneeling before the altar!",TP);
         TP->move_player(where);
         tell_object(TP,"You feel the strength of Kelemvor coursing through you as you"+
		" appear kneeling before his altar.");
         dest_effect();
      break;
      case "kossuth":
         tell_object(TP,"%^BOLD%^%^RED%^Flames spring up around you, and you feel "+
		"yourself being whisked away!");
         tell_room(environment(ETO),"%^BOLD%^%^RED%^A pillar of flame rises at "+
		"once, immolating "+TPQCN+" at its center!",TP);
         tell_room(find_object_or_load(where),"%^BOLD%^%^RED%^A pillar of flame "+
		"drops from the sky, leaving "+TPQCN+" prostrate before the altar!",TP);
         TP->move_player(where);
         tell_object(TP,"%^BOLD%^%^RED%^Your breath rushes out of you as you land"+
		" prostrate before the altar of Kossuth, the flames dissipating around you.");
         dest_effect();
      break;
      case "lathander":
         tell_object(TP,"%^RESET%^%^ORANGE%^You feel yourself surrounded by an "+
		"almost tangible %^YELLOW%^ray %^RESET%^%^ORANGE%^of %^YELLOW%^sunlight"+
		" %^RESET%^%^ORANGE%^that leaves you insubstantial for a moment!");
         tell_room(environment(ETO),"%^RESET%^%^ORANGE%^A ray of %^YELLOW%^sunlight"+
		" %^RESET%^%^ORANGE%^rises from "+TPQCN+"'s feet and swirls upwards "+
		"around "+TP->QO+".  When it clears, "+TP->QS+" is gone!",TP);
         tell_room(find_object_or_load(where),"%^RESET%^%^ORANGE%^A %^YELLOW%^"+
		"swirling beam %^RESET%^%^ORANGE%^of %^YELLOW%^sunlight %^RESET%^"+
		"%^ORANGE%^races to the floor, leaving "+TPQCN+" in its wake!",TP);
         TP->move_player(where);
         tell_object(TP,"%^RESET%^%^ORANGE%^You feel yourself being whisked away,"+
		" and when your vision clears, you are standing before the altar"+
		" of Lathander!");
         dest_effect();
      break;
      case "loviatar":
         tell_object(TP,"%^RESET%^%^BLUE%^Several grinning %^BOLD%^%^BLACK%^imps"+
		" %^RESET%^%^BLUE%^appear before you, and you feel the blessed sting"+
		" of their lashes as you're dragged through a portal!");
         tell_room(environment(ETO),"%^RESET%^%^BLUE%^Several grinning "+
		"%^BOLD%^%^BLACK%^imps %^RESET%^%^BLUE%^appear and lash out "+
		"with whips, ensnaring "+TPQCN+" and dragging "+TP->QO+" through"+
		" an %^BOLD%^%^BLACK%^inky black portal!",TP);
         tell_room(find_object_or_load(where),"%^RESET%^%^BLUE%^A gaping "+
		"%^BOLD%^%^BLACK%^black portal %^RESET%^%^BLUE%^opens in the "+
		"temple, and grinning %^BOLD%^%^BLACK%^imps %^RESET%^%^BLUE%^shove"+
		" "+TPQCN+" through, leaving "+TP->QO+" prostrate before the altar!",TP);
         TP->move_player(where);
         tell_object(TP,"%^RESET%^%^BLUE%^The %^BOLD%^%^BLACK%^imps %^RESET%^"+
		"%^BLUE%^release their hold and shove you through the open %^BOLD%^"+
		"%^BLACK%^portal, %^RESET%^%^BLUE%^leaving you prostrate before "+
		"the altar of Loviatar!");
         dest_effect();
      break;
      case "malar":
         tell_object(TP,"%^BOLD%^%^BLACK%^You hear a guttural growl as jaws "+
		"suddenly close around you and a great black feline jerks you away!");
         tell_room(environment(ETO),"%^RESET%^%^RED%^A great %^BOLD%^%^BLACK%^"+
		"black feline %^RESET%^%^RED%^with %^BOLD%^bloody claws %^RESET%^"+
		"%^RED%^appears suddenly and grabs "+TPQCN+" in its great jaws "+
		"before disappearing with "+TP->QO+"!",TP);
         tell_room(find_object_or_load(where),"%^RESET%^%^RED%^A great %^BOLD%^"+
		"%^BLACK%^black feline %^RESET%^%^RED%^with %^BOLD%^bloody claws"+
		" %^RESET%^%^RED%^appears suddenly and drops "+TPQCN+" onto the "+
		"ground before the altar before the cat disappears again!",TP);
         TP->move_player(where);
         tell_object(TP,"%^BOLD%^%^BLACK%^The great jaws open, leaving you on"+
		" the ground before the altar of Malar before the cat disappears!");
         dest_effect();
      break;
      case "mask":
         tell_object(TP,"%^BOLD%^%^BLACK%^You hear a low chuckle and feel the"+
		" presence of Mask as you disappear into your own shadow!");
         tell_room(environment(ETO),"%^BOLD%^%^BLACK%^With a confident smirk,"+
		" "+TPQCN+" melds into "+TP->QP+" own shadow and vanishes from sight!",TP);
         tell_room(find_object_or_load(where),"%^BOLD%^%^BLACK%^You suddenly "+
		"notice "+TPQCN+" is kneeling before the altar.  Hmm...was "+
		""+TP->QS+" there before?",TP);
         TP->move_player(where);
         tell_object(TP,"%^BOLD%^%^BLACK%^You step smoothly from the shadows,"+
		" kneeling before the altar of Mask as if you've been there "+
		"all along.");
         dest_effect();
      break;
      case "mielikki":
         tell_object(TP,"%^BOLD%^%^GREEN%^A sudden wind answers your prayers, "+
		"bringing with it a swirl of leaves that whisk you away to safety!");
         tell_room(environment(ETO),"%^BOLD%^%^GREEN%^A brisk wind rises, "+
		"bringing a swirl of leaves centered around "+TPQCN+".  When the"+
		" wind dies and the leaves fall, "+TPQCN+" is gone!",TP);
         tell_room(find_object_or_load(where),"%^BOLD%^%^GREEN%^Winds whip "+
		"around you as a whirl of leaves enters the temple, spinning away"+
		" and leaving "+TPQCN+" before the altar!",TP);
         TP->move_player(where);
         tell_object(TP,"%^BOLD%^%^GREEN%^A warm voice brings whispered "+
		"blessings to your ears before you are left kneeling before the"+
		" altar of Mielikki!");
         dest_effect();
      break;
      case "mystra":
         tell_object(TP,"%^BOLD%^%^RED%^At your urgent prayers, a %^RESET%^"+
		"%^RED%^delicate red mist %^BOLD%^%^RED%^rolls into the area, "+
		"taking you away!");
         tell_room(environment(ETO),"%^RESET%^%^RED%^A delicate red mist "+
		"rolls into the area, blanketing all within its path.  When it"+
		" clears, "+TPQCN+" is gone!",TP);
         tell_room(find_object_or_load(where),"%^RESET%^%^RED%^A deep red "+
		"mist forms before the altar amid whispers of the arcane before"+
		" it disappates, leaving "+TPQCN+" behind!",TP);
         TP->move_player(where);
         tell_object(TP,"%^RESET%^%^RED%^The intricate words of ages old "+
		"spells come unbidden to your mind before they leave you standing"+
		" before the altar of Mystra!");
         dest_effect();
      break;
      case "torm":
         tell_object(TP,"%^BOLD%^%^CYAN%^You see a translucent protective "+
		"sphere form around you before you feel yourself being torn away!");
         tell_room(environment(ETO),"%^BOLD%^%^CYAN%^A protective sphere forms"+
		" around "+TPQCN+", and "+TP->QS+" disappears as you watch!",TP);
         tell_room(find_object_or_load(where),"%^YELLOW%^A brilliant flash of"+
		" light dazzles your eyes before you focus on "+TPQCN+" kneeling"+
		" before the altar!",TP);
         TP->move_player(where);
         tell_object(TP,"%^YELLOW%^Your eyes are dazzled by a brilliant light"+
		" before they clear and you find yourself kneeling before the "+
		"altar of Torm!");
         dest_effect();
      break;
      case "oghma":
         tell_object(TP,"%^BOLD%^%^BLUE%^Answering your fervent prayers, a "+
		"magnificent %^CYAN%^blue-green owl %^BLUE%^seemingly made of "+
		"pure energy swoops in on the wings of awe-inspiring music to "+
		"carry you away!");
         tell_room(environment(ETO),"%^BOLD%^%^BLUE%^A magnificent %^CYAN%^"+
		"blue-green owl %^BLUE%^seemingly made of pure energy swoops in "+
		"on the wings of awe-inspiring music to carry "+TPQCN+" away!",TP);
         tell_room(find_object_or_load(where),"%^BOLD%^%^BLUE%^An amazing owl"+
		" made of %^CYAN%^blue-green energy %^BLUE%^swoops in suddenly "+
		"and places "+TPQCN+" gently before the altar before flying out"+
		" again!",TP);
         TP->move_player(where);
         tell_object(TP,"%^BOLD%^%^BLUE%^The %^CYAN%^owl %^BLUE%^places you "+
		"gently before the altar of Oghma before swooping out of the "+
		"temple, leaving its song in your heart!");
         dest_effect();
      break;
      case "selune":
         tell_object(TP,"%^BOLD%^You whisper fervently to your goddess and "+
		"feel her loving embrace whisk you away to safety!");
         tell_room(environment(ETO),"%^BOLD%^"+TPQCN+" whispers an urgent "+
		"prayer and disappears suddenly, leaving behind a few moonmotes"+
		" fluttering to the ground!",TP);
         tell_room(find_object_or_load(where),"%^BOLD%^A few dazzling moonmotes"+
		" dance on the air in front of the altar before "+TPQCN+" suddenly"+
		" appears, shrouded in brilliant moonlight!",TP);
         TP->move_player(where);
         tell_object(TP,"%^BOLD%^Selune whispers soft blessings into your ears"+
		" as she returns you to the sanctity of her temple, leaving you "+
		"before the altar with a moonmotes dancing around you.");
         dest_effect();
      break;
      case "shar":
         tell_object(TP,"%^BOLD%^%^BLACK%^Your prayers bring the velvety caress"+
		" of Shar, who shields you in her darkness as you are spirited away!");
         tell_room(environment(ETO),"%^BOLD%^%^BLACK%^A shroud of tangible "+
		"darkness blossoms into existance, shielding "+TPQCN+" from view."+
		"  When the area lightens again, "+TPQCN+" is nowhere to be found!",TP);
         tell_room(find_object_or_load(where),"%^BOLD%^%^BLACK%^A tangible field"+
		" of darkness coalesces before the altar and solidifies into"+
		" "+TPQCN+"!",TP);
         TP->move_player(where);
         tell_object(TP,"%^BOLD%^%^BLACK%^The blessed caress of Shar leaves you "+
		"feeling a strong sense of loss as you appear before her altar.");
         dest_effect();
      break; 
	case "shaundakul":
         tell_object(TP,"%^CYAN%^A gust of wind blows through the area.  The winds"+
		" pick you up and carry you away!");
         tell_room(environment(ETO),"%^CYAN%^A gust of wind blows through the area."+
		"  The winds pick up "+TPQCN+", and carry "+TP->QO+" away!",TP);
         tell_room(find_object_or_load(where),"%^CYAN%^A gust of wind blows "+
		"into the temple and gently sets "+TPQCN+" down before the altar"+
		" of Shaundakul!",TP);
         TP->move_player(where);
         tell_object(TP,"%^CYAN%^The winds carry you along quickly, the terrain"+
		" and landscape below you whizzing by.  The winds begin to decrease"+
		" in intensity, gently lowering you before the altar of Shaundakul.");
         dest_effect();
      break;
      case "silvanus":
         tell_object(TP,"%^RESET%^%^GREEN%^From the ground beneath your feet, "+
            "vines suddenly snake up and around your form to steal you away!");
         tell_room(environment(ETO),"%^RESET%^%^GREEN%^Vines suddenly snake up "+
		"from the ground to entangle "+TPQCN+".  They disintegrate a matter "+
            "of seconds later, and "+TPQCN+" is gone!",TP);
         tell_room(find_object_or_load(where),"%^RESET%^%^GREEN%^A thrum of power "+
		"carries on the wind, as vines snake up from the earth and unfold to "+
		"reveal "+TPQCN+"!",TP);
         TP->move_player(where);
         tell_object(TP,"%^RESET%^%^ORANGE%^An oak leaf tumbles past you and to "+
            "the ground, as the vines unfold to leave you within the sanctuary of "+
            "the Oakfather once more.");
         dest_effect();
      break;
 	case "sune":
         tell_object(TP,"%^RED%^A whirling tendril of flames burst into "+
		"existance and starts to wrap around you.  The sweet perfume"+
		" of fragrant roses fills your senses as you feel the flames"+
		" pulling you inwards.");
         tell_room(environment(ETO),"%^RED%^A whirling tendril of flames"+
		" burst into existance and starts to wrap around "+TPQCN+".  "+
		"The fragrant perfume of roses fills the area as the flames "+
		"vanish in a flash, taking "+TP->QO+" with them!",TP);
         tell_room(find_object_or_load(where),"%^RED%^The fragrant aroma"+
		" of roses fills the temple as a mass of whirling flames burts"+
		" into existance.  The flames start to unwrap, leaving "+TPQCN+" "+
		"before the altar of Sune!",TP);
         TP->move_player(where);
         tell_object(TP,"%^RED%^Waves of bliss wash over your mind as the"+
		" fragrance of roses fills your senses.  The flames about you"+
		" start to unwrap, leaving you before the radiant beauty of "+
		"Sune Firehair's altar!");
         dest_effect();
      break;
	case "talos":
         tell_object(TP,"%^YELLOW%^A bolt of %^BLACK%^black lightning %^YELLOW%^"+
		"strikes from the sky, leaving you feeling the blissful energy of the storm!");
         tell_room(environment(ETO),"%^YELLOW%^A bolt of %^BLACK%^black lightning"+
		" %^YELLOW%^strikes "+TPQCN+", leaving nothing at all behind!",TP);
         tell_room(find_object_or_load(where),"%^YELLOW%^A bolt of %^BLACK%^black "+
		"lightning %^YELLOW%^strikes the floor of the temple, leaving "+TPQCN+" "+
		"before the altar!",TP);
         TP->move_player(where);
         tell_object(TP,"%^YELLOW%^The energy fades, and you feel a final pulse "+
		"that leaves you before the altar of Talos!");
         dest_effect();
      break;
      case "tempus":
         tell_object(TP,"%^RESET%^%^RED%^As you call for aid, you hear the din of "+
		"battle rise around you.  Suddenly, a spectral warhorse charges into the"+
		" area and speeds away with you before your vision fades!");
         tell_room(environment(ETO),"%^RESET%^%^RED%^The din of battle fills the air"+
		" as a spectral war horse rides into the area, speeding away with"+
		" "+TPQCN+" into nothingness!",TP);
         tell_room(find_object_or_load(where),"%^RESET%^%^RED%^The sound of hooves "+
		"rises over a sudden din of battle as a warhorse appears from nowhere and"+
		" lowers "+TPQCN+" to the ground before the altar!",TP);
         TP->move_player(where);
         tell_object(TP,"%^RESET%^%^RED%^Your vision clears once more, and you find"+
		" yourself being lowered to the ground before the altar of Tempus before"+
		" the horse fades again!");
         dest_effect();
      break;
      case "tymora":
         tell_object(TP,"%^BOLD%^%^MAGENTA%^You hear an innocent %^YELLOW%^golden giggle"+
		" %^MAGENTA%^and find yourself surrounded by a shimmering %^WHITE%^silver"+
		" sheen %^MAGENTA%^that speeds you away towards safety!");
         tell_room(environment(ETO),"%^BOLD%^%^MAGENTA%^You hear an innocent "+
		"%^YELLOW%^golden giggle %^MAGENTA%^as "+TPQCN+" just vanishes "+
		"from sight!",TP);
         tell_room(find_object_or_load(where),"%^BOLD%^%^MAGENTA%^A shimmering "+
		"%^WHITE%^silver coin %^MAGENTA%^appears before the altar and grows "+
		"into the image of "+TPQCN+" before it fades, leaving "+TP->QO+" behind!",TP);
         TP->move_player(where);
         tell_object(TP,"%^BOLD%^%^MAGENTA%^You appear before the altar of Tymora"+
		" as you hear a playful voice singing before it fades away!");
         dest_effect();
      break;
      case "tyr":
         tell_object(TP,"%^YELLOW%^As the prayer to Tyr leaves your lips, you hear"+
		" a resounding gong and are spirited away to safety!");
         tell_room(environment(ETO),"%^YELLOW%^"+TPQCN+" vanishes as the exultant "+
		"stroke of a gong resounds all around you accompanied by a wordless chorus"+
		" of chanting voices!",TP);
         tell_room(find_object_or_load(where),"%^YELLOW%^You hear the chanting of "+
		"unseen voices before a gong suddenly sounds and "+TPQCN+" appears before"+
		" the altar!",TP);
         TP->move_player(where);
         tell_object(TP,"%^YELLOW%^With the robust crash of a gong, you are suddenly"+
		" within the temple just before the altar of Tyr!");
         dest_effect();
         break;

      case "jarmila":
         tell_object(TP,"%^RESET%^%^ORANGE%^You feel yourself surrounded by an "+
		"almost tangible %^YELLOW%^ray %^RESET%^%^ORANGE%^of %^YELLOW%^sunlight"+
		" %^RESET%^%^ORANGE%^that leaves you insubstantial for a moment!");
         tell_room(environment(ETO),"%^RESET%^%^ORANGE%^A ray of %^YELLOW%^sunlight"+
		" %^RESET%^%^ORANGE%^rises from "+TPQCN+"'s feet and swirls upwards "+
		"around "+TP->QO+".  When it clears, "+TP->QS+" is gone!",TP);
         tell_room(find_object_or_load(where),"%^RESET%^%^ORANGE%^A %^YELLOW%^"+
		"swirling beam %^RESET%^%^ORANGE%^of %^YELLOW%^sunlight %^RESET%^"+
		"%^ORANGE%^races to the floor, leaving "+TPQCN+" in its wake!",TP);
         TP->move_player(where);
         tell_object(TP,"%^RESET%^%^ORANGE%^You feel yourself being whisked away,"+
		" and when your vision clears, you are standing before the altar"+
		" of Jarmila!");
         dest_effect();
         break;
      case "lysara":
         tell_object(TP,"%^CYAN%^The sweet %^BOLD%^%^MAGENTA%^scent %^RESET%^%^CYAN%^of %^BOLD%^%^MAGENTA%^li%^RED%^%^MAGENTA%^l%^RED%^i%^MAG"+
                        "ENTA%^es %^RESET%^%^CYAN%^fills the %^BOLD%^air%^RESET%^%^CYAN%^, and you hear a %^BOLD%^%^BLACK%^bell %^RESET%^%^CY"+
                        "AN%^begin to %^BOLD%^toll%^RESET%^%^CYAN%^, as a %^BOLD%^%^WHITE%^mist %^RESET%^%^CYAN%^begins to form behind you."+
                        " The faint outline of %^BOLD%^%^BLACK%^g%^RESET%^r%^BOLD%^%^BLACK%^av%^RESET%^e%^BOLD%^%^BLACK%^st%^RESET%^o%^BOLD%^"+
                        "%^BLACK%^ne%^RESET%^s %^CYAN%^and %^BOLD%^%^BLACK%^m%^RESET%^%^CYAN%^a%^BOLD%^%^BLACK%^u%^RESET%^%^CYAN%^s%^BOLD%^%^"+
                        "BLACK%^o%^RESET%^%^CYAN%^l%^BOLD%^%^BLACK%^e%^RESET%^%^CYAN%^u%^BOLD%^%^BLACK%^m%^RESET%^%^CYAN%^s can be seen within"+
                        " the %^BOLD%^%^WHITE%^mist%^RESET%^%^CYAN%^. You feel the %^BOLD%^%^WHITE%^mist %^RESET%^%^CYAN%^wrap around you in a"+
                        " %^BOLD%^comforting %^RESET%^%^CYAN%^embrace, suffusing your %^BOLD%^%^MAGENTA%^soul %^RESET%^%^CYAN%^with %^BOLD%^%^W"+
                        "HITE%^calm %^RESET%^%^CYAN%^and %^BOLD%^peace%^RESET%^%^CYAN%^.");
		tell_room(environment(ETO),"%^CYAN%^The %^BOLD%^%^MAGENTA%^aroma %^RESET%^%^CYAN%^of %^BOLD%^%^MAGENTA%^li%^RED%^l%^MAGENTA%^i%^RED%^e"+
                                   "%^MAGENTA%^s %^RESET%^%^CYAN%^fills the %^BOLD%^air%^RESET%^%^CYAN%^, and you can hear a %^BOLD%^%^BLACK%^be"+
                                   "ll %^RESET%^%^CYAN%^begin to toll, as a %^BOLD%^%^WHITE%^mist %^RESET%^%^CYAN%^begins to form behind "+TPQCN+""+
                                   ". A faint outline of %^BOLD%^%^BLACK%^g%^RESET%^r%^BOLD%^%^BLACK%^av%^RESET%^e%^BOLD%^%^BLACK%^st%^RESET%^o%^BO"+
                                   "LD%^%^BLACK%^n%^RESET%^e%^BOLD%^%^BLACK%^s %^RESET%^%^CYAN%^and %^BOLD%^%^BLACK%^m%^RESET%^%^CYAN%^a%^BOLD%^%^BL"+
                                   "ACK%^u%^RESET%^%^CYAN%^s%^BOLD%^%^BLACK%^o%^RESET%^%^CYAN%^l%^BOLD%^%^BLACK%^e%^RESET%^%^CYAN%^u%^BOLD%^%^BLACK%^"+
                                   "m%^RESET%^%^CYAN%^s can be seen within the %^BOLD%^%^WHITE%^mist %^RESET%^%^CYAN%^as it begins to %^BOLD%^wrap %^RE"+
                                   "SET%^%^CYAN%^around "+TPQCN+", pulling him into it.",TP);
         tell_room(find_object_or_load(where),"%^CYAN%^A %^BOLD%^%^WHITE%^mist %^RESET%^%^CYAN%^begins to form in the center of the %^BOLD%^t%^RESET%^%^"+
                                              "CYAN%^e%^BOLD%^m%^RESET%^%^CYAN%^p%^BOLD%^l%^RESET%^%^CYAN%^e, the faint outline of %^BOLD%^%^BLACK%^gr%^R"+
                                              "ESET%^a%^BOLD%^%^BLACK%^v%^RESET%^e%^BOLD%^%^BLACK%^st%^RESET%^o%^BOLD%^%^BLACK%^n%^RESET%^e%^BOLD%^%^BLACK"+
                                              "%^s %^RESET%^%^CYAN%^and "+TPQCN+" beginning to form. "+TPQCN+" steps out of the %^BOLD%^%^WHITE%^mist%^RESE"+
                                              "T%^%^CYAN%^, with only the faint %^BOLD%^%^MAGENTA%^scent %^RESET%^%^CYAN%^of %^BOLD%^%^MAGENTA%^l%^RED%^i%^M"+
                                              "AGENTA%^l%^RED%^i%^MAGENTA%^es %^RESET%^%^CYAN%^is left behind.",TP);
         TP->move_player(where);
         tell_object(TP,"%^CYAN%^The feeling of %^BOLD%^%^WHITE%^calm %^RESET%^%^CYAN%^and %^BOLD%^peace %^RESET%^%^CYAN%^begins to leave you as the %^BOLD%^"+
                        "embrace %^RESET%^%^CYAN%^of the %^BOLD%^%^WHITE%^mist %^BLACK%^evaporates%^RESET%^%^CYAN%^, to leave you standing in the temple of %"+
                        "^BOLD%^L%^RESET%^%^CYAN%^y%^BOLD%^s%^RESET%^%^CYAN%^a%^BOLD%^r%^RESET%^%^CYAN%^a");
         dest_effect();
         break;   
      case "nimnavanon":
         tell_object(TP,"%^RESET%^%^GREEN%^As %^WHITE%^you %^GREEN%^end the spell, calling on the %^BOLD%^%^WHITE%^aid %^RESET%^%^GREEN%^of"+
                        " %^BOLD%^Nimnavanon%^RESET%^%^GREEN%^, %^BOLD%^v%^RESET%^%^GREEN%^i%^BOLD%^n%^RESET%^%^GREEN%^e%^BOLD%^s %^RESET%^"+
                        " %^GREEN%^and %^ORANGE%^s%^GREEN%^hr%^ORANGE%^u%^GREEN%^b%^ORANGE%^s %^GREEN%^begins to %^YELLOW%^grow %^RESET%^%^"+
                        "GREEN%^from the %^ORANGE%^ground %^GREEN%^around you. Within seconds, you are covered in a sheltered %^WHITE%^coco"+
                        "on %^GREEN%^of %^BOLD%^p%^RESET%^%^GREEN%^l%^BOLD%^a%^RESET%^%^GREEN%^n%^BOLD%^t%^RESET%^%^GREEN%^s and are drawn i"+
                        "nto the ground.");
         tell_room(environment(ETO),"%^RESET%^%^GREEN%^"+TPQCN+" calls to the %^BOLD%^%^WHITE%^aid %^RESET%^%^GREEN%^of %^BOLD%^Nimnavanon%^RESET%^%^GREEN%^"+
                                    ", and shrubs and %^BOLD%^v%^RESET%^%^GREEN%^i%^BOLD%^n%^RESET%^%^GREEN%^e%^BOLD%^s %^RESET%^%^GREEN%^begins to %^YELLOW%"+
                                    "^grow %^RESET%^%^GREEN%^from the %^ORANGE%^ground %^GREEN%^to cover his entire body, before they pull the p%^BOLD%^l%^RE"+
                                    "SET%^%^GREEN%^a%^BOLD%^n%^RESET%^%^GREEN%^tl%^BOLD%^i%^RESET%^%^GREEN%^k%^BOLD%^e %^RESET%^cocoon %^GREEN%^into the %^OR"+
                                    "ANGE%^ground.",TP);
         tell_room(find_object_or_load(where),"%^RESET%^%^GREEN%^Suddenly, a %^WHITE%^cocoon %^GREEN%^of %^BOLD%^p%^RESET%^%^GREEN%^l%^BOLD%^a%^RESET%^%^GREEN%^n%^"+
                                              "BOLD%^t%^RESET%^%^GREEN%^s in the shapes of different s%^ORANGE%^h%^GREEN%^ru%^ORANGE%^b%^GREEN%^s and %^BOLD%^v%^RE"+
                                              "SET%^%^GREEN%^i%^BOLD%^n%^RESET%^%^GREEN%^es %^BOLD%^g%^RESET%^%^GREEN%^row from the %^ORANGE%^earth%^GREEN%^.  And,"+
                                              " as they seem to withdraw, they leave "+TPQCN+" standing in front of the %^BOLD%^Altar %^RESET%^%^GREEN%^of %^BOL"+
                                              "D%^Nimnavanon!",TP);
         TP->move_player(where);
         tell_object(TP,"%^RESET%^%^GREEN%^As the the sh%^ORANGE%^r%^GREEN%^u%^ORANGE%^b%^GREEN%^s and %^BOLD%^"+
                        "v%^RESET%^%^GREEN%^i%^BOLD%^n%^RESET%^%^GREEN%^e%^BOLD%^s %^RESET%^%^GREEN%^lets go of"+
                        " your body, you find yourself in the %^BOLD%^Temple %^RESET%^%^GREEN%^of %^BOLD%^Nimnavanon!");
         dest_effect();    
         break;
      case "lord_shadow":
         tell_object(TP,"%^BOLD%^%^BLACK%^You end y%^WHITE%^o%^BLACK%^u%^WHITE%^r d%^RESET%^%^RED%^ark %^WHITE%^chanting%^BOLD%^%^BLACK%^,"+
                        " and you feel the bl%^RESET%^a%^BOLD%^%^BLACK%^c%^RESET%^k%^BOLD%^%^BLACK%^nes%^RESET%^s %^BOLD%^%^BLACK%^around you"+
                        " grow th%^RESET%^%^ORANGE%^i%^BOLD%^%^BLACK%^ck%^RESET%^%^ORANGE%^e%^BOLD%^%^BLACK%^r and th%^RESET%^%^ORANGE%^i%^BOLD"+
                        "%^%^BLACK%^ck%^RESET%^%^ORANGE%^e%^BOLD%^%^BLACK%^r, %^WHITE%^w%^BLACK%^r%^RESET%^a%^BOLD%^%^BLACK%^p%^WHITE%^p%^BLACK%"+
                        "^i%^RESET%^n%^BOLD%^%^BLACK%^g around you like the %^WHITE%^chill %^RESET%^%^CYAN%^embrace %^BOLD%^%^BLACK%^of d%^RESET"+
                        "%^%^RED%^e%^BOLD%^%^BLACK%^a%^RESET%^%^RED%^t%^BOLD%^%^BLACK%^h. You can feel your %^RESET%^%^RED%^life %^BOLD%^%^BLACK%^stop,"+
                        " your %^RED%^heart %^BLACK%^cease beating, and you are unable to %^CYAN%^draw %^BLACK%^breath. Dark spots form in your %^ORA"+
                        "NGE%^vision%^BLACK%^, and you can only think of one thing, the %^WHITE%^greatness %^BLACK%^of L%^RESET%^o%^BOLD%^%^BLACK%^rd Sh%^"
                        "RESET%^a%^BOLD%^%^BLACK%^d%^RESET%^o%^BOLD%^%^BLACK%^w.");
         tell_room(environment(ETO),"%^BOLD%^%^BLACK%^A %^RESET%^%^MAGENTA%^terrible %^BOLD%^%^BLACK%^m%^RESET%^a%^BOLD%^%^BLACK%^ss begins to form around "+TPQCN+"."+
                                    " C%^RESET%^%^GREEN%^r%^BOLD%^%^BLACK%^a%^RESET%^%^GREEN%^w%^BOLD%^%^BLACK%^l%^RESET%^%^GREEN%^i%^BOLD%^%^BLACK%^ng s%^RESET%^h%^"+
                                    "BOLD%^%^BLACK%^ad%^RESET%^o%^BOLD%^%^BLACK%^w%^RESET%^s %^BOLD%^%^BLACK%^of the deepest t%^RESET%^%^MAGENTA%^e%^BOLD%^%^BLACK%^r"+
                                    "r%^RESET%^%^MAGENTA%^o%^BOLD%^%^BLACK%^r begin to wrap around "+TPQCN+". You can see how a %^MAGENTA%^scream %^BLACK%^almost for"+
                                    "ms, and then "+TPQCN+" appears to %^WHITE%^freeze %^BLACK%^in d%^RESET%^%^RED%^e%^BOLD%^%^BLACK%^a%^RESET%^%^RED%^t%^BOLD%^%^BLA"+
                                    "CK%^h's %^CYAN%^icy %^WHITE%^grip%^BLACK%^. The s%^RESET%^h%^BOLD%^%^BLACK%^ad%^RESET%^o%^BOLD%^%^BLACK%^w%^RESET%^s %^BOLD%^%^"+
                                    "BLACK%^seem to %^RESET%^%^MAGENTA%^devour %^BOLD%^%^BLACK%^"+TPQCN+", and within a %^RESET%^%^RED%^h%^BOLD%^%^BLACK%^e%^RESET%^"+
                                    "%^RED%^ar%^BOLD%^%^BLACK%^t%^RESET%^%^RED%^be%^BOLD%^%^BLACK%^a%^RESET%^%^RED%^t%^BOLD%^%^BLACK%^, "+TPQCN+" is no more.",TP);
         tell_room(find_object_or_load(where), "%^BOLD%^%^BLACK%^The sound of m%^RESET%^%^CYAN%^o%^BOLD%^%^BLACK%^u%^RESET%^%^CYAN%^r%^BOLD%^%^BLACK%^n%^RESET%^%^"+
                                               "CYAN%^f%^BOLD%^%^BLACK%^u%^RESET%^%^CYAN%^l %^WHITE%^keening %^BOLD%^%^BLACK%^starts to fill the %^WHITE%^temple%"+
                                               "^BLACK%^, followed by a m%^RESET%^a%^BOLD%^%^BLACK%^ss of d%^RESET%^a%^BOLD%^%^BLACK%^rk%^RESET%^n%^BOLD%^%^BLACK%"+
                                               "^es%^RESET%^s %^BOLD%^%^BLACK%^and t%^RESET%^%^MAGENTA%^e%^BOLD%^%^BLACK%^nd%^RESET%^%^MAGENTA%^r%^BOLD%^%^BLACK%"+
                                               "^i%^RESET%^%^MAGENTA%^l%^BOLD%^%^BLACK%^s of s%^RESET%^m%^BOLD%^%^BLACK%^o%^RESET%^k%^BOLD%^%^BLACK%^e. From the"+
                                               " m%^RESET%^a%^BOLD%^%^BLACK%^ss of sh%^RESET%^ad%^BOLD%^%^BLACK%^ows "+TPQCN+" takes a deep %^CYAN%^breath%^BLACK%^"+
                                               ", and mutters ""%^MAGENTA%^%^RESET%^Thank you, Lord Shadow%^BOLD%^%^MAGENTA%^",TP);
         TP->move_player(where);
         tell_object(TP,"%^BOLD%^%^BLACK%^Suddenly, your %^ORANGE%^vision %^BLACK%^clears, your %^RED%^heart %^BLACK%^pumps and your %^CYAN%^lungs %^BLACK%^fill"+
                        " with %^WHITE%^air%^BLACK%^. You look around and find yourself in the %^WHITE%^Temple %^BLACK%^of L%^RESET%^o%^BOLD%^%^BLACK%^rd Sh%^RE"+
                        "SET%^a%^BOLD%^%^BLACK%^d%^RESET%^o%^BOLD%^%^BLACK%^w");
         dest_effect();  
         break;
  case "nilith":
         tell_object(TP,"%^ORANGE%^Y%^BOLD%^%^BLACK%^ou "+
		 "f%^RESET%^%^ORANGE%^e%^BOLD%^%^BLACK%^e%^RESET%^%^ORANGE%^l "+
		 "%^BOLD%^%^BLACK%^a cold a%^RESET%^%^ORANGE%^u%^BOLD%^%^BLACK%^ra upon "+
		 "yo%^RESET%^%^ORANGE%^u %^BOLD%^%^BLACK%^as a din of unea%^RESET%^%^ORANGE%^r"
		 "%^BOLD%^%^BLACK%^th%^RESET%^%^ORANGE%^l%^BOLD%^%^BLACK%^y w%^RESET%^%^ORANGE%^h"
		 "%^BOLD%^%^BLACK%^ispers s%^RESET%^%^ORANGE%^u%^BOLD%^%^BLACK%^rroun%^RESET%^%^ORANGE%^d "
		 "%^BOLD%^%^BLACK%^you, as a grey mi%^RESET%^%^ORANGE%^s%^BOLD%^%^BLACK%^t "
		 "ene%^RESET%^%^ORANGE%^v%^BOLD%^%^BLACK%^lopes you a%^RESET%^%^ORANGE%^n%^BOLD%^%^BLACK%^d "
		 "p%^RESET%^%^ORANGE%^u%^BOLD%^%^BLACK%^lls you to so%^RESET%^%^ORANGE%^m%^BOLD%^%^BLACK%^ew"+
		 "here else%^RESET%^");
         tell_room(environment(ETO),"%^BOLD%^%^BLACK%^S%^RESET%^%^ORANGE%^h%^BOLD%^%^BLACK%^im"+
		 "%^RESET%^%^ORANGE%^m%^BOLD%^%^BLACK%^er%^RESET%^%^ORANGE%^i%^BOLD%^%^BLACK%^ng"
		 "sp%^RESET%^%^ORANGE%^e%^BOLD%^%^BLACK%^ct%^RESET%^%^ORANGE%^e%^BOLD%^%^BLACK%^ral "+
		 "%^RESET%^%^ORANGE%^e%^BOLD%^%^BLACK%^nti%^RESET%^%^ORANGE%^t%^BOLD%^%^BLACK%^ies "+
		 "%^RESET%^%^ORANGE%^s%^BOLD%^%^BLACK%^w%^RESET%^%^ORANGE%^i%^BOLD%^%^BLACK%^rl ar"+
		 "%^RESET%^%^ORANGE%^o%^BOLD%^%^BLACK%^un%^RESET%^%^ORANGE%^d%^WHITE%^ "+TPQCN+"%^BOLD%^%^BLACK%^and"+
		 "%^RESET%^%^ORANGE%^en%^BOLD%^%^BLACK%^gu%^RESET%^%^ORANGE%^l%^BOLD%^%^BLACK%^f them."+
		 "As the mist d%^RESET%^%^ORANGE%^i%^BOLD%^%^BLACK%^s%^RESET%^%^ORANGE%^s%^BOLD%^%^BLACK%^a%^RESET%^%^ORANGE%^p %^BOLD%^%^BLACK%^at%^RESET%"+
         "^%^ORANGE%^e%^BOLD%^%^BLACK%^s,%^RESET%^ "+TP->QS+" %^BOLD^&^&BLACK^&is %^WHITE%^gone!%^RESET%^",TP);
         tell_room(find_object_or_load(where),"%^ORANGE%^s%^BOLD%^%^BLACK%^pec"+
		 "%^RESET%^%^ORANGE%^t%^BOLD%^%^BLACK%^ra%^RESET%^%^ORANGE%^l %^BOLD%^%^BLACK%^en"+
		 "%^RESET%^%^ORANGE%^t%^BOLD%^%^BLACK%^it%^RESET%^%^ORANGE%^i%^BOLD%^%^BLACK%^es "+
		 "swir%^RESET%^%^ORANGE%^l %^BOLD%^%^BLACK%^up fr%^RESET%^%^ORANGE%^o%^BOLD%^%^BLACK%^m "+
		 "the fl%^RESET%^%^ORANGE%^o%^BOLD%^%^BLACK%^or, le%^RESET%^%^ORANGE%^a%^BOLD%^%^BLACK%^vi"+
		 "%^RESET%^%^ORANGE%^n%^BOLD%^%^BLACK%^g %^RESET%^%^ORANGE%^i%^BOLD%^%^BLACK%^n "+TPQCN+" i"+
		 "%^BOLD%^%^BLACK%^n it's w%^RESET%^%^ORANGE%^a%^BOLD%^%^BLACK%^ke !",TP);
         TP->move_player(where);
         tell_object(TP,"%^ORANGE%^T%^BOLD%^%^BLACK%^he m"+
		 "%^RESET%^%^ORANGE%^i%^BOLD%^%^BLACK%^st ob%^RESET%^%^ORANGE%^s"+
		 "%^BOLD%^%^BLACK%^cur%^RESET%^%^ORANGE%^e%^BOLD%^%^BLACK%^s your vision, and you feel a "+
		 "%^RESET%^%^ORANGE%^c%^BOLD%^%^BLACK%^old tug on your soul. Wh%^RESET%^%^ORANGE%^e"+
		 "%^BOLD%^%^BLACK%^n the mist disappates, you find y%^RESET%^%^ORANGE%^o%^BOLD%^%^BLACK%^ur"+
		 "%^RESET%^%^ORANGE%^s%^BOLD%^%^BLACK%^elf in the temple of N%^RESET%^i%^BOLD%^l%^RESET%^i"+
		 "%^BOLD%^t%^BLACK%^h%^RESET%^");
         dest_effect();
         break;
   case "kismet":
         tell_object(TP,"%^BOLD%^You end your prayer to %^MAGENTA%^Kismet%^WHITE%^, and a %^BLACK%^s%^WHITE%^h%^BLACK%^i%^RESET%^m%"+
                        "^BOLD%^m%^BLACK%^e%^RESET%^r%^BOLD%^%^BLACK%^i%^WHITE%^n%^RESET%^g %^BOLD%^%^CYAN%^p%^RESET%^%^CYAN%^e%^BO"+
                        "LD%^nt%^RESET%^%^CYAN%^a%^BOLD%^gr%^RESET%^%^CYAN%^a%^BOLD%^m %^WHITE%^starts to %^ORANGE%^glow %^WHITE%^b"+
                        "eneath your feat and around you. In a b%^RESET%^r%^BOLD%^ight %^CYAN%^flash %^WHITE%^of %^ORANGE%^light %^WHITE%^you %^BLACK%^vanish");
         tell_room(environment(ETO),"%^BOLD%^A %^ORANGE%^glowing %^CYAN%^p%^RESET%^%^CYAN%^e%^BOLD%^nt%^RESET%^%^CYAN%^a%^BOLD%^gr"+
                                    "%^RESET%^%^CYAN%^a%^BOLD%^m %^WHITE%^starts to form %^RESET%^%^CYAN%^beneath %^BOLD%^%^WHITE%^and aro"+
                                    "und "+TPQCN+" , and in a %^CYAN%^flash %^WHITE%^of %^ORANGE%^bright lights%^WHITE%^, he %^BLACK%^vanishes!",TP);
         tell_room(find_object_or_load(where),"%^BOLD%^A %^ORANGE%^bright %^CYAN%^flash %^WHITE%^of %^RESET%^light %^BOLD%^expands from the"+
                                              " center of the %^MAGENTA%^t%^RESET%^%^MAGENTA%^e%^BOLD%^m%^RESET%^%^MAGENTA%^p%^BOLD%^l%^RES"+
                                              "ET%^%^MAGENTA%^e%^BOLD%^%^WHITE%^, and when the %^ORANGE%^light %^WHITE%^vanishes "+TPQCN+" "+
                                              " is %^BLACK%^left %^WHITE%^behind.",TP);
         TP->move_player(where);
         tell_object(TP,"%^BOLD%^You are %^CYAN%^pulled %^WHITE%^by the %^MAGENTA%^w%^RESET%^%^MAGENTA%^e%^BOLD%^a%^RESET%^%^MAGENTA%^v%^BOLD%^e%^WHITE%^,"+
                        " and within a %^RED%^h%^RESET%^%^RED%^e%^BOLD%^art%^RESET%^%^RED%^b%^BOLD%^e%^RESET%^%^RED%^a%^BOLD%^t %^WHITE%^you %^CYAN%^m%^RE"+
                        "SET%^%^CYAN%^a%^BOLD%^te%^RESET%^%^CYAN%^r%^BOLD%^ia%^RESET%^%^CYAN%^l%^BOLD%^iz%^RESET%^%^CYAN%^e %^BOLD%^%^WHITE%^within the Te"+
                        "mple of %^MAGENTA%^K%^RESET%^%^MAGENTA%^i%^BOLD%^sm%^RESET%^%^MAGENTA%^e%^BOLD%^t");
         dest_effect();
         break; 
      case "callamir":
         tell_object(TP,"%^BOLD%^%^CYAN%^You throw a pair of %^WHITE%^dice %^CYAN%^to the ground and they come up as %^WHITE%^two sixes%^CYAN%^."+
                        " With a smile on your %^RED%^lips %^CYAN%^your body begins to become %^RESET%^i%^CYAN%^n%^WHITE%^s%^CYAN%^u%^WHITE%^b%^"+
                        "CYAN%^s%^WHITE%^t%^CYAN%^a%^WHITE%^nt%^CYAN%^i%^WHITE%^a%^CYAN%^l %^BOLD%^and you %^BLACK%^vanish %^CYAN%^from %^ORANGE%^sight!");
         tell_room(environment(ETO),"%^BOLD%^%^CYAN%^"+TPQCN+" tosses a pair of %^WHITE%^dice %^CYAN%^onto the ground, and as they %^RESET%^%^MA"+
                                    "GENTA%^roll %^BOLD%^%^CYAN%^to a halt, they show %^WHITE%^two sixes%^CYAN%^. With that, his body begins to %"+
                                    "^RESET%^%^CYAN%^d%^WHITE%^i%^CYAN%^s%^WHITE%^a%^CYAN%^p%^WHITE%^p%^CYAN%^e%^WHITE%^a%^CYAN%^r %^BOLD%^from %^ORANGE%^sight!",TP);
         tell_room(find_object_or_load(where),"%^BOLD%^%^CYAN%^A %^ORANGE%^bright %^BLUE%^light %^CYAN%^flares to %^WHITE%^life%^CYAN%^, and from"+
                                              " within the %^ORANGE%^light%^CYAN%^, first a pair of %^WHITE%^dice %^CYAN%^roll over the temple fl"+
                                              "oor, showing %^WHITE%^two sixes%^CYAN%^.  Almost immediately afterwards, "+TPQCN+"  steps out from"+
                                              " within the %^ORANGE%^light%^CYAN%^, looking around with a %^MAGENTA%^smile%^CYAN%^.",TP);
         TP->move_player(where);
         tell_object(TP,"%^BOLD%^%^CYAN%^You feel the pull of C%^WHITE%^a%^CYAN%^ll%^WHITE%^a%^CYAN%^m%^WHITE%^i%^CYAN%^r as your %^BLACK%^tr%"+
                        "^RESET%^a%^BOLD%^%^BLACK%^nsp%^RESET%^o%^BOLD%^%^BLACK%^rt%^RESET%^e%^BOLD%^%^BLACK%^d %^CYAN%^over a vast distance."+
                        " As you come to a %^ORANGE%^halt%^CYAN%^, you see the %^WHITE%^temple %^CYAN%^of C%^WHITE%^a%^CYAN%^ll%^WHITE%^a%^CY"+
                        "AN%^m%^WHITE%^i%^CYAN%^r and on the floor, %^WHITE%^two dice %^CYAN%^with the sixes up.");
         dest_effect();
         break;    
	case "ryorik":
         tell_object(TP,"%^YELLOW%^A bolt of %^BLACK%^black lightning %^YELLOW%^"+
		"strikes from the sky, leaving you feeling the blissful energy of the storm!");
         tell_room(environment(ETO),"%^YELLOW%^A bolt of %^BLACK%^black lightning"+
		" %^YELLOW%^strikes "+TPQCN+", leaving nothing at all behind!",TP);
         tell_room(find_object_or_load(where),"%^YELLOW%^A bolt of %^BLACK%^black "+
		"lightning %^YELLOW%^strikes the ground of the shrine, leaving "+TPQCN+" "+
		"before the altar!",TP);
         TP->move_player(where);
         tell_object(TP,"%^YELLOW%^The energy fades, and you feel a final pulse "+
		"that leaves you before the altar of Ryorik!");
         dest_effect();
      break;        
   case "varda":
         tell_object(TP,"%^RESET%^%^RED%^As you call for aid, you hear the din of "+
		"battle rise around you. Suddenly, a spectral warhorse charges into the"+
		" area and speeds away with you before your vision fades!");
         tell_room(environment(ETO),"%^RESET%^%^RED%^The din of battle fills the air"+
		" as a spectral war horse rides into the area, speeding away with"+
		" "+TPQCN+" into nothingness!",TP);
         tell_room(find_object_or_load(where),"%^RESET%^%^RED%^The sound of hooves "+
		"rises over a sudden din of battle as a warhorse appears from nowhere and"+
		" lowers "+TPQCN+" to the ground before the altar!",TP);
         TP->move_player(where);
         tell_object(TP,"%^RESET%^%^RED%^Your vision clears once more, and you find"+
		" yourself being lowered to the ground before the altar of Varda before"+
		" the horse fades again!");
         dest_effect();
      break;      
  case "the_faceless_one":
         tell_object(TP,"%^BOLD%^%^BLACK%^You hear a sinister whispering in "+
		"your ear as you fade from sight.");
         tell_room(environment(ETO),"%^RESET%^%^BLUE%^"+TPQCN+" dissolves in "+
		"a whirl of %^BOLD%^%^WHITE%^%^MAGENTA%^v%^BOLD%^i%^RESET%^%^MAGENTA%^o%^BOLD%^l%^RESET%^%^MAGENTA%^et f%^"
        "BOLD%^l%^RESET%^%^MAGENTA%^o%^BOLD%^w%^RESET%^%^MAGENTA%^e%^BOLD%^r p%^RESET%^%^MAGENTA%^e%^BOLD%^t%^"
        "RESET%^%^MAGENTA%^a%^BOLD%^ls%^RESET%^ %^RESET%^%^BLUE%^leaving nothing behind but two %^BOLD%^%^BLACK%^"+
		"black eyes %^RESET%^%^BLUE%^that fade slowly!",TP);
         tell_room(find_object_or_load(where),"%^BOLD%^%^BLACK%^A whirl of "+
		"%^MAGENTA%^v%^BOLD%^i%^RESET%^%^MAGENTA%^o%^BOLD%^l%^RESET%^%^MAGE"+
        "NTA%^et f%^BOLD%^l%^RESET%^%^MAGENTA%^o%^BOLD%^w%^RESET%^%^MAGENTA%"+
        "^e%^BOLD%^r p%^RESET%^%^MAGENTA%^e%^BOLD%^t%^RESET%^%^MAGENTA%^a%^BOLD%^l"
        "s %^BOLD%^%^BLACK%^appears before the altar and fades quickly, leaving "+TPQCN+" kneeling.",TP);
         TP->move_player(where);
         tell_object(TP,"%^RESET%^%^BLUE%^The strength of %^BOLD%^%^BLACK%^The Faceless One"+
		" %^RESET%^%^BLUE%^rips from your body, leaving you kneeling before "+
		"his altar with a vision of %^BOLD%^%^BLACK%^two black eyes %^RESET%^"+
		"%^BLUE%^searing into your mind.");
         dest_effect();
      break;
   case "kreysneothosies":
         tell_object(TP,"%^BOLD%^%^CYAN%^You see a translucent protective "+
		"sphere form around you before you feel yourself being torn away!");
         tell_room(environment(ETO),"%^BOLD%^%^CYAN%^A protective sphere forms"+
		" around "+TPQCN+", and "+TP->QS+" disappears as you watch!",TP);
         tell_room(find_object_or_load(where),"%^YELLOW%^A brilliant flash of"+
		" light dazzles your eyes before you focus on "+TPQCN+" kneeling"+
		" before the altar!",TP);
         TP->move_player(where);
         tell_object(TP,"%^YELLOW%^Your eyes are dazzled by a brilliant light"+
		" before they clear and you find yourself kneeling before the "+
		"altar of Kreysneothosies!");
         dest_effect();
      break;   
         
         
         
      break;
      default:
         tell_object(TP,"You are suddenly whisked away to the "+where+" as you call to "+diety+".");
         tell_room(environment(ETO),""+TPQCN+" calls to "+diety+" and suddenly disappears!",TP);
         tell_room(find_object_or_load(where),""+TPQCN+" suddenly appears before the altar!",TP);
         TP->move_player(where);
         dest_effect();
         break;
         
   }
   return 1;
}