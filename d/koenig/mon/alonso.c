#include <std.h>
inherit MONSTER;

void create()
{
   ::create();
   set_name("alonso");
   set_id(({"alonso","farmer","Alonso"}));
   set_short("Alonso, a farmer");
   set_long(
      "Alonso is a simple farmer who supports his family by "+
      "tending to the cornfields south of his home.  He is a "+
      "young man with short dirty blonde hair, which is usually "+
      "covered in a hat when he's outdoors.  His face and arms have "+
      "a deep tan that stands in stark contrast to his brilliant "+
      "green eyes and crisp white shirt.  He wears plain cotton breeches "+
      "tucked into thick work boots.  He has a ready smile and a "+
      "twinkle in his eyes."
      );
   set_alignment(4);
   set_gender("male");
   set_race("human");
   set_body_type("human");
   set_hd(10,4);
   set_stats("strength",18);
   set_stats("constitution",14);
   set_stats("intelligence",12);
   set_stats("wisdom",14);
   set_stats("charisma",16);
   set_stats("dexterity",12);
   set_class("fighter");
   set_mlevel("fighter",10);
   set_hp(125);
   set_max_hp(125);
   set_property("full attacks",1);
   set_exp(100);
}

void catch_say(string msg){
   call_out("reply_func",1,msg,TP);
}
#define TRUST ({"gnome", "dwarf", "halfling","human","elf","half-elf","pegataur"})
#define DISTRUST ({"drow", "half-drow", "orc", "half-orc", "goblin", "hobgoblin", "bugbear", "ogre", "half-ogre", "gnoll", "ogre-mage", "kobold","minotaur","yuan-ti"})
#define STRANGE ({"beastman","firbolg","wemic","voadkyn","beastkin","saurian","centaur","satyr"})

void reply_func(string msg, object who){
   string race;
   string name;
   race = who->query_race();
   name = who->query_name();
   if((strsrch(msg,"ello") != -1 || strsrch(msg,"Hi") != -1 ||
      strsrch(msg,"reeting") != -1 || strsrch(msg,"Hey") != -1 || strsrch(msg,"Hail") != -1)){
      if(member_array(race, TRUST) != -1) {
         force_me("say Oh, hello there.  Welcome to my home.");
         force_me("smile "+name);
         force_me("say Did you need something?");
         return;
      }
      if(member_array(race, DISTRUST) !=-1) {
         force_me("eye "+name);
         force_me("say What are you doing in my house, you filthy "+race+"?");
         force_me("emote steps between you and the hallway.");
         if(!present("knife",TO)){
            force_me("emote grabs a knife from the kitchen counter.");
            new("/d/common/obj/weapon/knife.c")->move(TO);
            force_me("wield knife");
         }
         force_me("say Get out, now!");
         force_me("kill "+name);
         return;
      }
      if(member_array(race, STRANGE) !=-1) {
         force_me("emote 's eyes widen as he takes a step back.");
         force_me("say What are you doing in my house?");
         return;
      }
   }
   if((strsrch(msg,"ashlyn") != -1 || strsrch(msg,"Ashlyn") != -1 ||
      strsrch(msg,"aughter") != -1 || strsrch(msg,"child") != -1 || strsrch(msg,"children") != -1)){
      if(member_array(race, TRUST) != -1) {
         force_me("say My daughter Ashlyn?  She's doing well...growing all the time.");
         force_me("smile");
         force_me("say You know how children are...she's curious and "+
            "into everything, but she's learning fast.  She enjoys helping "+
            "her mother and me.");
         return;
      }
      if(member_array(race, DISTRUST) !=-1) {
         force_me("growl");
         force_me("say What do you know about her?");
         force_me("emote steps toward you with a wild gleam in his eyes.");
         if(!present("knife",TO)){
            force_me("emote grabs a knife from the kitchen counter.");
            new("/d/common/obj/weapon/knife.c")->move(TO);
            force_me("wield knife");
         }
         force_me("say If you have harmed her, you will not see another day!");
         force_me("kill "+name);
         return;
      }
      if(member_array(race, STRANGE) !=-1) {
         force_me("emoteat "+name+" narrows his eyes and looks at $N suspiciously.");
         force_me("say Why do you ask about her?");
         return;
      }
   }
   if((strsrch(msg,"field") != -1 || strsrch(msg,"fields") != -1 ||
      strsrch(msg,"farm") != -1 || strsrch(msg,"corn") != -1)){
      if(member_array(race, TRUST) != -1) {
         force_me("say I manage the cornfields just south of here.");
         force_me("smile with pride");
         force_me("say There wasn't anything there until that night...wow, "+
            "what a night that was!  With the ritual and all, I mean.");
         force_me("emoteat "+name+" looks at $N curiously.");
         force_me("say Have you heard that story?");
         return;
      }
      if(member_array(race, DISTRUST) !=-1) {
         force_me("snarl");
         force_me("say You'd better keep your filthy claws away from my fields!");
         force_me("emote steps toward you with a wild gleam in his eyes.");
         if(!present("knife",TO)){
            force_me("emote grabs a knife from the kitchen counter.");
            new("/d/common/obj/weapon/knife.c")->move(TO);
            force_me("wield knife");
         }
         force_me("kill "+name);
         return;
      }
      if(member_array(race, STRANGE) !=-1) {
         force_me("emote raises an eyebrow.");
         force_me("say Yeah, I farm those cornfields south of here.  Quite a "+
            "story how they came to be...why do you ask?");
         return;
      }
   }
   if((strsrch(msg,"story") != -1 || strsrch(msg,"ritual") != -1 ||
      strsrch(msg,"tell") != -1 || strsrch(msg,"ask") != -1)){
      if(member_array(race, TRUST) != -1 || member_array(race,STRANGE) != -1) {
         force_me("emote thinks a moment.");
         force_me("say Well, mind you, I only came in at the end, so I didn't "+
            "see all of what happened, but I've heard it from good friends of mine.");
         force_me("smile quietly");
         force_me("say See, at one time, there was nothing there at all.  I mean, "+
            "a long time ago, there were fields there as far as the eye could see.  "+
            "There was a small village of farmers, too, and they all worked together "+
            "and it seems like life must've been pretty good.");
         force_me("emote pauses a moment and sighs.");
         force_me("say But then...the orcs came.");
         force_me("emote grows quiet and takes a seat on the couch.");
         return;
      }
      if(member_array(race, DISTRUST) !=-1) {
         force_me("growl");
         force_me("say Leave now, filthy "+race+"!");
         force_me("emote steps toward you with a wild gleam in his eyes.");
         if(!present("knife",TO)){
            force_me("emote grabs a knife from the kitchen counter.");
            new("/d/common/obj/weapon/knife.c")->move(TO);
            force_me("wield knife");
         }
         force_me("kill "+name);
         return;
      }
   }
   if((strsrch(msg,"orc") != -1 || strsrch(msg,"after") != -1 || strsrch(msg,"next") != -1 || strsrch(msg,"continue") != -1 || strsrch(msg,"Orc") != -1)){
      if(member_array(race, TRUST) != -1 || member_array(race,STRANGE) != -1) {
         force_me("emote blinks and clears his throat.");
         force_me("say Oh, well...the orcs began attacking the village, burning "+
            "the fields.  The people began to starve.  They asked the nearby "+
            "towns for help, but none would come.");
         force_me("emote frowns.");
         force_me("say The orcs finally came in droves.  They wipes out the "+
            "whole village - women, children, it didn't matter.  They chased "+
            "the last of the survivors into those cornfields...and a huge, "+
            "bloody battled claimed the last villagers there.");
         force_me("emote shakes his head slowly.");
         force_me("say No one really knows what happened, but somehow..."+
            "horrible as it is to say, the spirits of the farmers and "+
            "their families was bound to the land.  Nothing would ever "+
            "grow there again, and it became a haven for vermin...and orcs.");
         force_me("emote licks his lips and sighs before he continues.");
         call_out("part1",20);
         return;
      }
      if(member_array(race, DISTRUST) !=-1) {
         force_me("growl");
         force_me("say Leave now, filthy "+race+"!");
         force_me("emote steps toward you with a wild gleam in his eyes.");
         if(!present("knife",TO)){
            force_me("emote grabs a knife from the kitchen counter.");
            new("/d/common/obj/weapon/knife.c")->move(TO);
            force_me("wield knife");
         }
         force_me("kill "+name);
         return;
      }
   }
}

int part1()
{
        force_me("say For years, the fields lay in ruin.  The only thing "+
           "containing the...blight...on the land was a series of carvings "+
           "that were set into the outer fenceposts by clerics of five related "+
           "faiths - Callamir, Jarmila, Kreysneothosies, Nimnavanon, and Lysara.");
        force_me("say The rituals they performed contained the blight, but "+
           "they could not find the cause, nor a way to release it.");
        force_me("emote finally gives a small smile.");
        force_me("say Eventually, though, there was someone who found the answer...");
        call_out("part2",20);
        return 1;
}

int part2()
{
        force_me("say You see, I said that the souls were trapped there, but "+
           "that's only because I know now what caused it.  It wasn't until some "+
           "very bright minds worked together that this mystery was solved, though.");
        force_me("say It was a ranger, naturally, that first had an inkling of "+
           "what might lay on the land.  I do not know his name, though...he was a "+
           "wanderer, and I never had the pleasure of meeting him.");
        force_me("emote smiles quietly and his eyes brighten.");
        force_me("say He spoke with a good man, though...  "+
           "His name is Tengri, and he's the one who gave me the job of farming those fields.  "+
           "But before that could happen, there was a lot to be done.");
        force_me("emote glances into the fire and grows thoughtful before he continues.");
        call_out("part3",20);
        return 1;
}

int part3()
{
        force_me("say All of it is a bit over my head, but I'll tell it to you "+
           "as it was told to me.");
        force_me("say After a lot of research and talking to all the right people, "+
           "Tengri learned of a ritual that might help free the land.  He had to collect "+
           "a lot of strange things.  I don't recall all of them, but I do remember he said "+
           "something about morning dew...and an apple seed...and some phoenix feathers.");
        force_me("emote shrugs slightly.");
        force_me("say He worked hard to gather all these things, then he and a priest "+
           "called Ramius performed a holy ritual to bless the "+
           "apple seed.  They came then to the fields at the last light of day and planted "+
           "the seed.");
        force_me("emote smiles with a faraway look.");
        call_out("part4",20);
        return 1;
}

int part4()
{
        force_me("say As the last rays of the sun were striking the ground, a "+
           "high priestess named Selve called down the rains to cleanse the "+
           "ground.  Her prayers were answered, and as the rains came, a beam of "+
           "sunlight struck the ground.");
        force_me("emote 's eyes widen.");
        force_me("say They say that then spirits rose up out of the ground, flying "+
           "all over the place!  The last spirit was a little girl...she looked at them "+
           "and then turned and floated away...");
        force_me("emote glances down the hallway with a sad smile.");
        call_out("part5",20);
        return 1;
}

int part5()
{
        force_me("say After that day, things began to grow in the field.  The wards "+
           "are no longer needed, but we've kept the fenceposts as a reminder of what "+
           "happened.");
        force_me("emote smiles.");
        force_me("say And that apple tree...well, it grows the sweetest "+
           "apples you'll ever taste.");
        force_me("say Tengri said they needed someone to tend the fields...and "+
           "this is where my family's been ever since.  There's really nothing more "+
           "to tell than that.  That Tengri, though...he's a good man.");
        return 1;
}