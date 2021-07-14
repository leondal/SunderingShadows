//    "/cmds/mortal/_advance.c"   ShadowGate Mudlib
//    Last modifyed by Firedragon 12/21/96
// moved Deku trainers up to level 15, added new areas for several from additions of past few years *Styx*  11/6/04
// added/rearranged a few more training areas, added a hint of seeking out the swords quest for the message of denial for level 20 *Styx* 1/23/06
// removed deku from the L15 trainers (after saide's upgrades), moved laerad into the 25 bracket and archemond's down to 20. Nienne, 09/07.
//removed Tharis forest and the Dark Forest from the list, as both of these areas are buggy and nearly impossible except for certain classes.  ~Circe~ 6/08
//added new deku haunted house to level 25 areas - except for the basement - it changes so I didn't want to scare everyone off :P - Saide


#include <daemons.h>
#include <living.h>
#include <std.h>
#include <dirs.h>
#include <objects.h>
#include <psions.h>
#include <bloodlines.h>
#include <mysteries.h>
#include "/d/shadowgate/genetics.h"

#define MAX_TEST_LEVEL 60
#define MAX_LEVEL 50

#define QLEVEL 20

#define FIVE ({"/d/newbie/rooms/forest/", "/d/newbie/rooms/hill/",\
"/d/newbie/rooms/ruins/", "/d/newbie/rooms/keep/keep3*",\
"/d/newbie/rooms/drow/rooms/dn*"})

#define TEN ({"/d/shadow/room/mountain/", "/d/koenig/fields/room/",\
"/d/koenig/caves/", "/d/koenig/streams/", "/d/darkwood/camps/rooms/orcamp/",\
"/d/shadow/room/meadows/plains*", "/d/shadow/room/mountain/cave6*",\
"/d/shadow/room/cave/cavern*", "/d/tharis/conforest/rooms/", "/d/shadow/room/feyren/rooms/ffout*"})

#define FIFTEEN ({ "/d/shadow/room/kildare/rooms/nest*", "/d/shadow/room/kildare/rooms/ptrail*",\
"/d/darkwood/yntala/rooms/", "/d/darkwood/yntala/rooms/meadow*",\
"/d/darkwood/yntala/rooms/uw*", "/d/darkwood/yntala/rooms/forest*", "/d/shadow/room/feyren/rooms/" })

#define TWENTY ({ "/d/deku/mausoleum/rooms/", "/d/deku/fortress/",  "/d/deku/keep/rooms/",\
"/d/barriermnts/ruins/room/b*", "/d/deku/keep/rooms/dungeon*",\
"/d/laerad/parnelli/asgard/sewer/rooms/",\
"/d/islands/pirates/rooms/ship*", "/d/islands/pirates/rooms/cave*",\
"/d/antioch/valley/rooms/dt*", "/d/islands/dallyh/forest/rooms/"})

#define TWENTYFIVE ({"/d/laerad/parnelli/forest/",\
"/d/laerad/wasteland/", "/d/laerad/plains/", "/d/antioch/ruins/rooms/ruins*",\
"/d/laerad/parnelli/systyquah/",\
"/d/dagger/derro/rooms/c*", "/d/deku/sanctuary/tower/",\
"/d/deku/sanctuary/sewer/sewer*",})

#define THIRTY ({"/d/islands/tonerra/path/path*", "/d/dagger/drow/rooms/",\
"/d/islands/tonerra/mountain/mount5*",\
"/d/islands/common/aramanth/room*",\
"/d/barriermnts/bpeak/rooms/", "/d/islands/dinosaur/rooms/",\
"/d/deku/hhouse/rooms/ff*", "/d/deku/hhouse/rooms/sf*",\
"/d/deku/hhouse/rooms/rt*", "/d/deku/hhouse/rooms/cy*"})

#define THIRTYFIVE ({"/d/dagger/drow/rooms/", "/d/attaya/beach*",\
"/d/laerad/cavern1/", "/d/dagger/marsh/swamp/rooms/",\
"/d/antioch/ruins/portal/", "/d/islands/argentrock/rooms/argpath2*"})

#define FOURTY ({"/d/dagger/ogres/rooms/", "/d/attaya/beach*", "/d/attaya/jun*", "/d/attaya/cliff*", "/d/laerad/cavern1/", "/d/laerad/cavern2/", "/d/islands/argentrock/rooms/argpath2*",\
"/d/tharis/barrow/room/pi*",})

#define FOURTYFIVE ({"/d/dagger/drow/rooms/", "/d/attaya/beach*", "/d/attaya/jungle/jun*", "/d/dagger/marsh/swamp/rooms/", "/d/attaya/cliff*", "/d/attaya/base/base*", "/d/attaya/base/wall*", "/d/islands/dallyh/marsh/rooms/" })

#define FIFTY ({ "/d/attaya/beach*", "/d/attaya/jun*", "/d/attaya/cliff*", "/d/attaya/base/base*", "/d/attaya/base/wall*", "/d/dagger/marsh/tower/rooms/", "/d/islands/common/eldebaro/newrooms/",\
"/d/islands/common/eldebaro/newrooms/room*",\
"/d/islands/common/eldebaro/newrooms/tomb*","/d/islands/common/eldebaro/newrooms/sand_dune*" })

#define PLACES ([5:FIVE,10:TEN,15:FIFTEEN,20:TWENTY,25:TWENTYFIVE,30:THIRTY,35:THIRTYFIVE,40:FOURTY,45:FOURTYFIVE,50:FIFTY,55:FIFTY,60:FIFTY,65:FIFTY,70:FIFTY,75:FIFTY,80:FIFTY,85:FIFTY,90:FIFTY,95:FIFTY,100:FIFTY])

#define TRNROOM "/d/shadow/obj/special/trainerroom"
string pick_room(); // To pick a room for them to be in.
// This makes things a bit clearer. - g


int cost(string myclass, int lottc)
{
    return 0;
}

int do_multiclass(object ob,string myclass) {
    int level;
    level = (int)ob->query_base_character_level();
    ob->set_class(myclass);
    ob->set("lvl_"+level+"_class",myclass);
    ob->set("active_class",myclass);
//InitInnate() is necessary for Shadowdancers and maybe others ~Circe~ 7/30/19
    ob->InitInnate();
    ob->init_spellcaster();
    ob->remove_property("multiclassing");
}

int can_multiclass(object ob,string myclass) {
    mapping stats_needed;
    string *bad_races,*bad_classes,*bad_gods,*classes,race,subrace,file,*stats,deity;
    int i,level,alignment,*bad_alignments;

    if(!objectp(ob)) return 0;

// let's pick up some character info & check that they're at a bracket to multiclass.
    race                = (string)ob->query_race();
    subrace             = (string)ob->query("subrace");
    alignment           = (int)ob->query_alignment();
    deity               = (int)ob->query_diety();
    level               = (int)ob->query_base_character_level();
    classes             = (string *)ob->query_classes();
    classes            += ({ myclass });
    if(!sizeof(classes)) { return 1; }

    if(level == 10 && ob->query("lvl_10_class")) {
        tell_object(ob,"%^RED%^You may not multiclass again until level 20.");
        return 0;
    }
    if(level == 20 && ob->query("lvl_20_class")) {
        tell_object(ob,"%^RED%^You may not multiclass again until level 30.");
        return 0;
    }
    if(level == 30 && ob->query("lvl_30_class")) {
        tell_object(ob,"%^RED%^You may not multiclass again until level 40.");
        return 0;
    }
    if(level == 40 && ob->query("lvl_40_class")) {
        tell_object(ob,"%^RED%^You may not multiclass again until level 50.");
        return 0;
    }
    if(level == 50 && ob->query("lvl_50_class")) {
        tell_object(ob,"%^RED%^You may not multiclass again until level 60.");
        return 0;
    }
    if(level == 60 && ob->query("lvl_60_class")) {
        tell_object(ob,"%^RED%^You may not multiclass again until level 70.");
        return 0;
    }
    if(level == 70 && ob->query("lvl_70_class")) {
        tell_object(ob,"%^RED%^You may not multiclass again until level 80.");
        return 0;
    }
    if(level == 80 && ob->query("lvl_80_class")) {
        tell_object(ob,"%^RED%^You may not multiclass again until level 90.");
        return 0;
    }
    if(level == 90 && ob->query("lvl_90_class")) {
        tell_object(ob,"%^RED%^You may not multiclass again.");
        return 0;
    }
    if(level%10) {
        tell_object(ob,"%^BOLD%^You can only advance in a different class at 10 level increments, such as level 10, level 20, level 30, etc.");
        return 0;
    }

// first, check that their race & subrace is ok for the new class. The class files do not discern the subrace options for each class so we need to use the race file!
    file                = DIR_RACES+"/"+race+".c";
    if(!file_exists(file)) {
        tell_object(ob,"%^BOLD%^Your race seems to not exist, please contact an immortal/wiz.");
        return 0;
    }

    bad_classes         = (string *)file->restricted_classes(subrace);

    if(member_array(myclass,bad_classes) != -1) {
        tell_object(ob,"%^BOLD%^Your race has a thematic restriction on being a "+myclass+".");
        return 0;
    }

    file                = DIR_CLASSES+"/"+myclass+".c";
    if(!file_exists(file)) {
      tell_object(ob,"%^BOLD%^We don't know how to make you a "+myclass+" please contact an immortal/wiz.");
      return 0;
    }

    if(file->is_prestige_class())
    {
        {
            string clss;
            string tmp;

            foreach(clss in ob->query_classes())
            {
                tmp = DIR_CLASSES+"/"+clss+".c";
                if(tmp->is_prestige_class())
                {
                    tell_object(ob,"You can't take two prestige classes at the same time.");
                    return 0;
                }
            }
        }

        if(file->requires_base_class_set() && !file->has_base_class_set(ob))
        {
            tell_object(ob,"%^BOLD%^%^WHITE%^The class "+myclass+" requires that you choose a base class in order to "
                "advance into it.  You must select one of your exising classes that meets the requirements "
                "for a base class for the prestige class "+myclass+".  Please enter the name of the "
                "class that you would like as your base class:\n");
            ob->set_property("adding base class",1);
            input_to("add_base_class", ob, myclass);
            return 0;
        }

        if(!file->prerequisites(ob))
        {
            tell_object(ob,"%^BOLD%^You do not meet all the prerequisites to be a "+myclass+".\n"
                "Please double check the help file.");
            tell_object(ob,file->requirements());
            file->remove_base_class(ob);
            return 0;
        }
    }
    bad_classes         = (string *)file->restricted_classes(ob);
    bad_alignments      = (int *)file->restricted_alignments(ob);
    bad_gods            = (string *)file->restricted_gods(ob);
    stats_needed        = (mapping)file->stat_requirements(ob);
    stats               = keys(stats_needed);


    for(i=0;i<sizeof(classes);i++)
    {
        if(member_array(classes[i],bad_classes) != -1)
        {
            tell_object(ob,"%^BOLD%^Your existing classes prevent you from becoming a "+myclass+".");
            file->remove_base_class(ob);
            return 0;
        }
    }

    if(member_array(alignment,bad_alignments) != -1)
    {
        tell_object(ob,"%^BOLD%^You are not allowed to be a "+myclass+" with your alignment.");
        file->remove_base_class(ob);
        return 0;
    }

    if(member_array(deity,bad_gods) != -1)
    {
        tell_object(ob,"%^BOLD%^You cannot be a "+myclass+" while following your deity.");
        file->remove_base_class(ob);
        return 0;
    }

    for(i=0;i<sizeof(stats);i++)
    {
        if((int)ob->query_stats(stats[i]) < stats_needed[stats[i]])
        {
            tell_object(ob,"%^BOLD%^You do not meet the stat requirements to become a "+myclass+".");
            file->remove_base_class(ob);
            return 0;
        }
    }
    return 1;
}


void add_base_class(string str, object obj, string the_class)
{
    object class_ob;

    if(!objectp(obj)) { return; }

    if(!stringp(str))
    {
        tell_object(obj, "You must enter one of your existing classes as the base "
            "class requirement for "+the_class+"\n");
        return;
    }

    if(!obj->is_class(str))
    {
        tell_object(obj, str+" doesn't seem to be one of your classes.\n");
        return 1;
    }

    class_ob = find_object_or_load(DIR_CLASSES+"/"+the_class+".c");

    if(!objectp(class_ob))
    {
        tell_object(obj, "There seems to be something wrong with the "+the_class+" file, please contact a wiz.\n");
        return 1;
    }

    if(!class_ob->set_base_class(obj, str))
    {
        tell_object(TP,"You can't set your base class for "+the_class+" to "+str+", please check the help files "
            "and make sure "+the_class+" allows "+str+" as a base class.  If it does, please notify a wiz.\n");
        return 1;
    }

    tell_object(TP,"%^RESET%^%^BOLD%^%^YELLOW%^Setting your base class for %^MAGENTA%^"+the_class+"%^YELLOW%^ "
        "to %^MAGENTA%^"+str+"%^YELLOW%^.  You will need to type %^MAGENTA%^advance "+the_class+"%^YELLOW%^ again "
        "in order to complete the advancement process.%^RESET%^\n");
    return 1;
}

int add_class_feats(object ob,string myclass)
{
    string *feats,*paths,file,myspec;
    mapping featsmap;
    int i,*mapkeys,mylev;

    if(!ob->query("new_class_type")) { return 0; }
    tell_object(ob,"Attempting to add class feats as a "+myclass+".");

    file = ""+DIR_CLASSES+"/"+myclass+".c";
    if(!file_exists(file)) { return 0; }

    myspec = (string)ob->query_combat_spec(myclass); // new combat spec code, N 1/14.
    if(myclass == "monk") myspec = (string)ob->query("monk way");
    featsmap = (mapping)file->class_featmap(myspec, ob);
    mapkeys = keys(featsmap);
    feats = ({});
    mylev = (int)ob->query_base_class_level(myclass);
    if(!mylev && ob->is_class(myclass)) mylev = 1;
    for(i=0;i<sizeof(mapkeys);i++) {
      if(mylev >= mapkeys[i]) feats += featsmap[mapkeys[i]];
    }

    for(i=0;i<sizeof(feats);i++)
    {
        FEATS_D->update_usable(ob);
        if(FEATS_D->add_my_feat(ob,"class",feats[i]))
        {
            tell_object(ob,"%^YELLOW%^Adding class feat %^BLUE%^"+feats[i]+"%^YELLOW%^");
        }
    }

    paths = (string *)file->search_paths();
    for(i=0;i<sizeof(paths);i++)
    {
        if(member_array(paths[i],(string *)ob->query_search_path()) == -1)
        {
            tell_object(ob,"%^YELLOW%^Adding command paths for class "+myclass+".");
            ob->add_search_path(paths[i]);
        }
    }
    ob->set("active_class",myclass);
    return 1;
}

int pick_psion_discipline(string str,object ob)
{
    string *schools = ({ "egoist","kineticist","nomad","seer","shaper","telepath" });
    string school;

    if(!objectp(ob)) { return 0; }

    if(!ob->is_class("psion")) { return 0; }
    if(ob->query_discipline()) { return 0; }
    switch(str)
    {
    case "egoist":      school = "egoist";      break;
    case "kineticist":  school = "kineticist";  break;
    case "nomad":       school = "nomad";       break;
    case "seer":        school = "seer";        break;
    case "shaper":      school = "shaper";      break;
    case "telepath":    school = "telepath";    break;
    case "abort": return 1;
    default:

        tell_object(ob,"  %^YELLOW%^Discipline Name");
        tell_object(ob,"  %^BLUE%^-------------");
        tell_object(ob,"   egoist\n   kineticist\n   nomad\n   seer\n   shaper\n   telepath\n");
        tell_object(ob,"%^BOLD%^Please enter your psionic discipline");
        tell_object(ob,"%^RED%^Type <abort> to exit if you need to "
            "look at help files before making your choice.");
        input_to("pick_psion_discipline",ob);
        return 1;
    }

    ob->set_discipline(school);
    tell_object(ob,"%^CYAN%^Ok, Thou hast chosen to become a "+capitalize(school)+".");
    return 1;
}

int pick_fighter_style(string str,object ob)
{
    string *styles = ({ "peasant","swashbuckler","thug","soldier","dervish" });
    string style;

    if(!objectp(ob)) { return 0; }
    if(!ob->is_class("fighter")) { return 0; }
    if(ob->query_fighter_style()) { return 0; }

    switch(str)
    {
    case "peasant":         style = "peasant";      break;
    case "swashbuckler":    style = "swashbuckler"; break;
    case "thug":            style = "thug";         break;
    case "soldier":         style = "soldier";      break;
    case "dervish":         style = "dervish";      break;
    case "abort": return 1;
    default:

        tell_object(ob,"  %^YELLOW%^Style Type");
        tell_object(ob,"  %^BLUE%^-------------");
        tell_object(ob,"\n   peasant\n   swashbuckler\n   thug\n   soldier\n   dervish\n" );
        tell_object(ob,"%^RED%^Type <abort> to exit if you need to "
            "look at help files before making your choice.");
        tell_object(ob,"%^BOLD%^Please enter your Style of Fighting:");
        input_to("pick_fighter_style",ob);
        return 1;
    }

    ob->set_fighter_style(style);
    tell_object(ob,"%^BOLD%^%^BLUE%^You learned the ways of fighting within "
        "the "+capitalize(style)+" style.");
    return 1;
}

int pick_warlock_heritage(string str,object ob) {
    string *heritages, heritage, mymessage;
    int align, i;

    if(!objectp(ob)) return 0;
    if(!ob->is_class("warlock")) return 0;
    if(ob->query("warlock heritage")) return 0;

    align = ob->query_alignment();
    switch(align) {
      case 7: heritages = (({ "celestial", "fey" })); break;
      case 8: heritages = (({ "celestial", "fey", "abyssal", "astral" })); break;
      case 9: heritages = (({ "fey", "abyssal", "gloom" })); break;
      case 5: heritages = (({ "astral", "gloom", "fey" })); break;
      case 6: heritages = (({ "abyssal", "gloom", "infernal", "astral" })); break;
      case 3: heritages = (({ "gloom", "infernal" })); break;
      default: tell_object(ob,"You have an alignment that does not work for a warlock! Please contact a wiz."); return 1; break;
    }
    switch(str)     {
      case "celestial":  heritage = "celestial";  break;
      case "fey":        heritage = "fey";        break;
      case "abyssal":    heritage = "abyssal";    break;
      case "astral":     heritage = "occult";      break;
      case "gloom":      heritage = "gloom";      break;
      case "infernal":   heritage = "infernal";   break;
      case "abort": return 1;
      default:
        tell_object(ob,"  %^YELLOW%^Warlock heritages");
        tell_object(ob,"  %^BLUE%^-------------");
        mymessage = "";
        for(i=0;i<sizeof(heritages);i++) mymessage += "   "+heritages[i]+"\n";

        tell_object(ob,mymessage);
        tell_object(ob,"%^BOLD%^Please enter your warlock heritage.");
        tell_object(ob,"%^RED%^Type <abort> to exit if you need to look at help files before making your choice.");
        input_to("pick_warlock_heritage",ob);
        return 1;
    }
    if(member_array(str,heritages) == -1) {
      tell_object(ob,"You cannot select that warlock heritage with your alignment.");
      return 1;
    }

    ob->set("warlock heritage",heritage);
    tell_object(ob,"%^CYAN%^Ok, you have chosen for you heritage to be "+capitalize(heritage)+".");
    return 1;
}

int pick_sorc_bloodline(string str,object ob) {
    string *bloodlines, bloodline, mymessage;
    int i;

    if(!objectp(ob)) return 0;
    if(!ob->is_class("sorcerer")) return 0;
    if(ob->query_bloodline()) return 0;

    if(str=="abort")
        return 1;

    if(member_array(str,keys(BLOODLINE_DESC))!=-1)
    {
        bloodline = str;
    }
    else
    {
        tell_object(ob,"  %^YELLOW%^Bloodlines");
        mymessage = "";
        foreach(bloodline in keys(BLOODLINE_DESC))
        {
            mymessage+="  "+bloodline+"\n";
        }

        tell_object(ob,mymessage);
        tell_object(ob,"%^BOLD%^Enter your bloodline.");
        tell_object(ob,"%^RED%^Type <abort> to exit if you need to look at help files before making your choice.");
        input_to("pick_sorc_bloodline",ob);
        return 1;
    }

    ob->set_bloodline(bloodline);
    tell_object(ob,"%^CYAN%^You have chosen for you bloodline to be "+capitalize(bloodline)+".");
    return 1;
}

int pick_oracle_mystery(string str,object ob) {
    string *mysteries, mystery, mymessage;
    int i;

    if(!objectp(ob)) return 0;
    if(!ob->is_class("oracle")) return 0;
    if(ob->query_mystery()) return 0;

    if(str=="abort")
        return 1;

    if(member_array(str,keys(MYSTERY_SKILLS))!=-1)
    {
        mystery = str;
    }
    else
    {
        tell_object(ob,"  %^YELLOW%^Mysteries");
        mymessage = "";
        foreach(mystery in keys(MYSTERY_SKILLS))
        {
            mymessage+="  "+mystery+"\n";
        }

        tell_object(ob,mymessage);
        tell_object(ob,"%^BOLD%^Enter your mystery.");
        tell_object(ob,"%^RED%^Type <abort> to exit if you need to look at help files before making your choice.");
        input_to("pick_oracle_mystery",ob);
        return 1;
    }

    ob->set_mystery(mystery);
    tell_object(ob,"%^CYAN%^You have chosen for you mystery to be "+capitalize(mystery)+".");
    return 1;
}

int initiate_psychic_powers(object ob){
   int psylvl, mymax, newmax;
   string myclass;
   if(!objectp(ob)) { return 0; }
    if(!ob->is_class("psion") && !ob->is_class("psywarrior")) { return 0; }
   mymax = 0;
   mymax += ob->query_max_mp();
   if(ob->is_class("psywarrior")){
      myclass = "psywarrior";
   }else if(ob->is_class("psion")){
      myclass = "psion";
   }else{
      return 0;
   }
   psylvl = ob->query_prestige_level(myclass);
   if(!psylvl){ return 0; }
   psylvl--;
   if(psylvl < 0) psylvl = 0;
   switch(myclass){
      case "psywarrior" : newmax = PWPOINTS[psylvl];
                          break;
      case "psion" :      newmax = PSIONPOINTS[psylvl];
                          break;
      default:            return 0;
   }
//When/if psychic characters get bonus points for intelligence, be sure to add here
   if(mymax != newmax){
      ob->set_max_mp(newmax);
      tell_object(ob,"%^BOLD%^%^GREEN%^At your current level, you have "+newmax+" power points.%^RESET%^");
   }
// The above is partially for debugging/checking. We can remove it later if we choose.
   return 1;
}

int pick_human_subrace(string str,object ob) {
    string *subraces = ({ "heartlander","zin'charu","aesatri","attayan","tsarven","morinnen","tonaz'tlacar","senzokuan","maalish" });

    if(!objectp(ob)) { return 0; }
    if((string)ob->query_race() != "human") { return 0; }
    if((string)ob->query("subrace")) { return 0; }
    if(str == "abort") return 1;

    if(!str || member_array(str,subraces) == -1) {
      tell_object(ob,"  %^YELLOW%^Human ethnicities");
      tell_object(ob,"  %^BLUE%^-----------------");
      tell_object(ob,"\n   heartlander\n   zin'charu\n   aesatri\n   attayan\n   tsarven\n   morinnen\n   tonaz'tlacar\n   senzokuan\n   maalish\n" );
	tell_object(ob,"%^RED%^Type <abort> to exit if you need to spend more time before making your choice. ");
       // "Descriptions can be found at the shadowgate.org website. <help advance> will return you here when you are ready.");
      tell_object(ob,"%^BOLD%^Please enter your ethnicity:");
      input_to("pick_human_subrace",ob);
      return 1;
    }

    ob->set("subrace",str);
    tell_object(ob,"%^BOLD%^%^BLUE%^You have selected the "+capitalize(str)+" ethnicity for your character.");
    return 1;
}

int confirm_advance(string str,object ob,int level,string myclass)
{
    if(!objectp(ob)) { return 1; }
    if(!intp(level)) { return 1; }

    if(str != "yes")
    {
        tell_object(ob,"Aborting...");
        return 1;
    }
    tell_object(ob,"%^BOLD%^Confirmed, you may type advance again to "
        "advance in your class.%^RESET%^");
    ob->set("confirmed_level_"+level+"",1);
    ob->set("active_class",myclass);
    return 1;
}

int cmd_advance(string myclass){
   int i,j,k,lottc,train,was_newbie,char_level;
   string *rooms,*dirs,room,dir,*search_paths;
   object ob,newbroom;

   TP->remove_property("adding base class");

   //"no advance" setting had been used here to lock players from
   //advancing in ancient times. It defines highest level player is
   //allowed to be



   if(sizeof(myclass))
           if(regexp(myclass,"[a-z]+ special"))
           {
                   write("%^BOLD%^Trying to set any missing class specials...");
                   pick_psion_discipline("",TP);
                   pick_fighter_style("",TP);
                   pick_warlock_heritage("",TP);
                   pick_sorc_bloodline("",TP);
                   pick_oracle_mystery("",TP);
                   pick_human_subrace("",TP);
                   return 1;
           }

   if(strlen(myclass)) { myclass = replace_string(myclass," ","_"); }

   if(POISON_D->is_poisoned(TP)){
      tell_object(TP,"You should get your poison cured before you advance.");
      return 1;
   }

   if(!myclass){
      if(TP->query("active_class")){
         myclass = TP->query("active_class");
      }else{
         myclass = TP->query_class();
      }
   }

   {
       string file;
       file = DIR_CLASSES+"/"+myclass+".c";
       if(!file_exists(file))
       {
           tell_object(TP,"%^BOLD%^%^RED%^The class %^RESET%^"+myclass+"%^BOLD%^%^RED%^ does not exist.");
           return 1;
       }
       if(file->is_prestige_class())
           if(TP->query_class_level(myclass)>9)
           {
               tell_object(TP,"%^BOLD%^%^RED%^You cannot have more than 10 levels in a prestige class.");
               tell_object(TP,"Use %^ORANGE%^<advance %^ORANGE%^%^ULINE%^CLASSNAME%^RESET%^%^ORANGE%^>%^RESET%^ to advance in another class.");
               return 1;
           }
   }
//Multiclassing code
   if(TP->query("new_class_type")){
      char_level = (int)TP->query_base_character_level();
      if(char_level != 10 &&
         char_level != 20 &&
         char_level != 30 &&
         char_level != 40 &&
         char_level != 50 &&
         char_level != 60 &&
         char_level != 70 &&
         char_level != 80 &&
         char_level != 90 &&
         char_level != 100)
      {
         if(myclass != (string)TP->query("active_class"))
         {
            tell_object(TP,"You may only advance in your active class: "+TP->query("active_class")+"");
            return 1;
         }
      }

      if(!(char_level%10)){
          if(member_array(myclass,TP->query_classes()) == -1)
          {
              if(!can_multiclass(TP,myclass))
              {
                  if(TP->query_property("adding base class")){
                      tell_object(TP,"Please enter a class to be your base class for "+myclass+".");
                      return 1;
                  }
                  tell_object(TP,"You are not allowed to become a "+myclass+"");
                  return 1;
              }
              else
              {
                  TP->set_property("multiclassing",1);
              }
          }
      }

      if(member_array(myclass,TP->query_classes()) != -1){
          if(!(char_level%10)){
            if(!TP->query("confirmed_level_"+char_level)){
               tell_object(TP,"%^B_RED%^%^CYAN%^Are you sure that you do not want to take a new class at this level?  You will not get another chance until level "+(char_level+10)+".%^RESET%^");
               tell_object(TP,"Enter <yes> to confirm that you DO NOT want to add another class, anything else to abort.");
               input_to("confirm_advance",TP,char_level,myclass);
               return 1;
            }
         }
      }
   }
//End multiclassing code

   lottc = this_player()->query_class_level(myclass);
   train = cost(myclass, lottc);

   if(TP->query("new_class_type")){
      if((int)TP->query_adjusted_character_level() == MAX_LEVEL && !TP->query("test_character")){
         tell_object(TP,"%^BOLD%^%^GREEN%^You have reached the pinnacle of your ability. Congratulations. Unfortunately you can learn no more.");
         return 1;
      }
   }else{
      tell_object(TP,"There is something wrong with your classes, please contact a wiz.");
      return 1;
   }

   was_newbie=newbiep(TP);

   if((avatarp(TP)) && (lottc >= 150)) return 1;

   if(!environment(this_player())->query_property("training")){
      write("%^CYAN%^This is not the appropriate place for training!");
      return 1;
   }
   if(TP->query("negative level")){
      tell_object(TP, "%^BOLD%^%^RED%^You have incurred a negative level and must remove it before you are able to advance.");
      return 1;
   }
   if(intp(USER_D->get_scaled_level(TP))){
      tell_object(TP, "%^BOLD%^%^RED%^You have scaled your level down and cannot advance until your level is reset to normal.%^RESET%^");
      return 1;
//Start real advance info
   }else{
      FEATS_D->update_usable(TP);
      if(TP->query("new_class_type")) {
         char_level = (int)TP->query_base_character_level();
      }else{
         char_level = (int)TP->query_lowest_level();
      }
      if(TP->query_property("multiclassing")){
         TP->set_class(myclass);
      }
//      if((char_level%5 == 0) && (int)TP->query("last done") < char_level){
      if(char_level%5 == 0){
         if(ETP->query_property("Specialist") && (string)ETP->query_player() == (string)TPQN){
//            TP->set("last done",char_level);
            if(ADVANCE_D->advance(this_player(),myclass)){
               if(TP->query("new_class_type") && (int)TP->query_base_character_level()%4 == 0
                  && (((int)TP->query("stat_points_gained") * 4) < (int)TP->query_base_character_level())){
                  tell_object(TP,"%^B_RED%^%^CYAN%^You have earned a new stat point, please type <help stats>.%^RESET%^");
               }
               if(TP->query_property("multiclassing")){
                  do_multiclass(TP,myclass);
               }
               add_class_feats(TP,myclass);
               FEATS_D->update_usable(TP);
               initiate_psychic_powers(TP);
               TP->InitInnate();
               TP->use_funds("gold",train);
               if(!TP->query("test_character") && ((string)TP->query("advance place") != "/d/newbie/ooc/trainer")){
                  "daemon/room_d"->remove_room(ETP->query_exit("out"));
                  "daemon/room_d"->remove_room(ETP->query_exit("out")+".c");
                  TP->force_me("out");
                  ob = present("post",ETP);
                  if(objectp(ob)){
                     ob->remove();
                  }
               }
               TP->set("advance place",0);
               "/cmds/avatar/_note.c"->cmd_note("ckpt "+TPQN+" %^BOLD%^%^BLUE%^Met his/her trainer.");
               if (was_newbie != newbiep(TP)){
                  write("%^YELLOW%^You are whisked away to a mysterious location!%^RESET%^");
                  newbroom=find_object_or_load("/d/newbie/ooc/trainer.c");
                  if(!objectp(newbroom)){
                     write("Oops! There has been an error. Please contact a wiz.");
                     return 1;
                  }
                  TP->move(newbroom);
                  write("%^BOLD%^%^GREEN%^Congratulations, you are now a full-fledged player.\nYou may exit through the portal in this "
                     "room when you are ready to adventure into the greater realm of Sundering Shadows!%^RESET%^");
                  TP->force_me("look");
                  while(objectp(present("charactercreationsetterobject", TP))){
                     tell_object(TP, "The powerful object unattaches from you and fades away!");
                     present("charactercreationsetterobject", TP)->remove();
                  }
               }
	         return 1;
            }
	   }else if(char_level > 50){
            if(ADVANCE_D->advance(this_player(),myclass)){
               if(TP->query("new_class_type") && (int)TP->query_base_character_level()%4 == 0
                  && (((int)TP->query("stat_points_gained") * 4) < (int)TP->query_base_character_level())){
                  tell_object(TP,"%^B_RED%^%^CYAN%^You have earned a new stat point, please type <help stats>.%^RESET%^");
               }
               if(TP->query_property("multiclassing")){
                  do_multiclass(TP,myclass);
               }
               add_class_feats(TP,myclass);
               FEATS_D->update_usable(TP);
               initiate_psychic_powers(TP);
               TP->InitInnate();
	           TP->use_funds("gold",train);
               if(was_newbie != newbiep(TP)){
                  write("%^GREEN%^Congratulations, you are now a full-fledged player.\nYou have heard of a gate to the south, "
                     "that leads into foreign lands.  It will provide passage to the next step of your adventure!%^RESET%^");
               }
	         return 1;
	      }
	   }else{
            if(ADVANCE_D->advance(this_player(),myclass)){
               if(TP->query("new_class_type") && (int)TP->query_base_character_level()%4 == 0
                  && (((int)TP->query("stat_points_gained") * 4) < (int)TP->query_base_character_level())){
                  tell_object(TP,"%^B_RED%^%^CYAN%^You have earned a new stat point, please type <help stats>.%^RESET%^");
               }
               if(TP->query_property("multiclassing")){
                  do_multiclass(TP,myclass);
               }
               add_class_feats(TP,myclass);
               FEATS_D->update_usable(TP);
               initiate_psychic_powers(TP);
               TP->InitInnate();
               TP->use_funds("gold",train);
               if(was_newbie != newbiep(TP)){
                  write("%^YELLOW%^You are whisked away to a mysterious location!%^RESET%^");
                  newbroom=find_object_or_load("/d/newbie/ooc/trainer.c");
                  if(!objectp(newbroom)){
                     write("Oops! There has been an error. Please contact a wiz.");
                     return 1;
                  }
                  TP->move(newbroom);
                  write("%^BOLD%^%^GREEN%^Congratulations, you are now a full-fledged player.\nYou may exit through the portal in this "
                     "room when you are ready to adventure into the greater realm of Sundering Shadows!%^RESET%^");
                  TP->force_me("look");
               }
               return 1;
            }
         }
      }else{
         if(ADVANCE_D->advance(this_player(),myclass)){
            if(TP->query("new_class_type") && (int)TP->query_base_character_level()%4 == 0
               && (((int)TP->query("stat_points_gained") * 4) < (int)TP->query_base_character_level())){
               tell_object(TP,"%^B_RED%^%^CYAN%^You have earned a new stat point, please type <help stats>.%^RESET%^");
            }
            if(TP->query_property("multiclassing")){
               do_multiclass(TP,myclass);
            }
            add_class_feats(TP,myclass);
            FEATS_D->update_usable(TP);
            initiate_psychic_powers(TP);
            TP->InitInnate();
            TP->use_funds("gold",train);
            if(was_newbie != newbiep(TP)){
               write("%^YELLOW%^You are whisked away to a mysterious location!%^RESET%^");
               newbroom=find_object_or_load("/d/newbie/ooc/trainer.c");
               if(!objectp(newbroom)){
                  write("Oops! There has been an error. Please contact a wiz.");
                  return 1;
               }
               TP->move(newbroom);
               write("%^BOLD%^%^GREEN%^Congratulations, you are now a full-fledged player.\nYou may exit through the portal in this "
                  "room when you are ready to adventure into the greater realm of Sundering Shadows!%^RESET%^");
               TP->force_me("look");
            }
	      return 1;
         }
      }

      if((int)TP->query_class_level(myclass) == 0) { TP->remove_class(myclass); }
      TP->remove_property("multiclassing");

      if (ETP->query_level() < 6) {
          if (strsrch(base_name(ETP), "/d/newbie/ooc/hub_room") == 0) {
              return 1;
          }
      }

      write("%^BOLD%^You are not yet experienced enough to gain next level of "+myclass+".\n");
      return 1;
   }
}

string pick_room()
{
  int i,level,num;
  string *classes, room,*rooms,*dirs,dir,place,hold1,hold2;

  if(TP->query("test_character")) { return 0; }
  if(TP->query("new_class_type")) { level = (int)TP->query_base_character_level(); }
  else { level = (int)TP->query_lowest_level(); }

  switch(level)
  {
  case 0..5:    num = 5;    break;
  case 6..10:   num = 10;   break;
  case 11..15:  num = 15;   break;
  case 16..20:  num = 20;   break;
  case 21..25:  num = 25;   break;
  case 26..30:  num = 30;   break;
  case 31..35:  num = 35;   break;
  default:      num = 40;   break;
  }

  dirs = PLACES[num];
  dir = dirs[random(sizeof(dirs))];
  rooms = get_dir(dir+"*.c");
  if(!sizeof(rooms)) { pick_room(); }
  room = rooms[random(sizeof(rooms))];
  if(dir[strlen(dir)-1] == '*'){
//    write("here");
    while( dir[strlen(dir)-1] != '/' ){
      dir = dir[0..strlen(dir)-2];
    }
  }
  room = dir+room;
  TP->set("advance place",room);
  return room;
}

void help()
{

    write("
%^CYAN%^NAME%^RESET%^
advance - increase your level
%^CYAN%^SYNOPSIS%^RESET%^
advance [%^ORANGE%^%^ULINE%^CLASS_NAME%^RESET%^]
advance class special
%^CYAN%^DESCRIPTION%^RESET%^
This is the command used to advance your character. Advancement may only occur in a designated training area. You will also need to have enough experience for that next level! Designated training areas include, but are not limited to: churches, rooms with boards
When your character has enough experience to advance to levels 10, 20, 30 and 40 you may instead choose to advance in another class. You will retain all of the abilities of your current class and you will get any new abilities that your new class allows. Only certain class and race combinations are allowed. Please see the individual help files for your race and the class that you would like to become for more information.
%^CYAN%^MULTICLASSING%^RESET%^
If you're multiclassing, abandoning, or are ancient character that has no specific mage school, sorcerer bloodline, warlock heritage, oracle mystery or another class specific flavor set you might use %^ORANGE%^<advance class special>%^RESET%^ to fix missing class special settings.
%^CYAN%^SEE ALSO%^RESET%^
abandon, score, classes
");
}