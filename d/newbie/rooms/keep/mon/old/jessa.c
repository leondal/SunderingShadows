#include <std.h>
#include <daemons.h>
#include "../../inherit/keep.h"
inherit WEAPONLESS;

string *asked;

void create(){
   ::create();
   set_name("Jessa");
   set_id(({"jessa","Jessa","woman","robed woman","human"}));
   set_short("%^RESET%^%^CYAN%^Jessa, a short %^MAGENTA%^robed %^CYAN%^woman%^RESET%^");
   set_long("%^RESET%^%^CYAN%^Jessa is quite short, but has a spirited look and "
"vibrant energy in her actions.  She is dressed in %^ORANGE%^simple shoes "
"%^CYAN%^and a %^MAGENTA%^long robe%^CYAN%^, with the hilt of a %^RESET%^dagger "
"%^CYAN%^visible in a sheath at her waist.  Her short hair has been cropped "
"just below her ears, swaying in an %^BOLD%^%^BLACK%^ebon wave %^RESET%^%^CYAN%^"
"any time she moves her head.  Her vivid %^BOLD%^azure eyes %^RESET%^%^CYAN%^"
"survey all passersby, watching each with interest.  Perhaps you could attract "
"her attention with a greeting?%^RESET%^");
   set_gender("female");
   set_race("human");
   set_body_type("human");
   set_hd(10,3);
   set_max_level(6);
   set_size(2);
   set_alignment(5);
   set_overall_ac(5);
   set_max_hp(random(10)+70);
   set_hp(query_max_hp());
   set_exp(100);
   set_level(5);
   set_class("mage");
   set_mlevel("mage",5);
   set_guild_level("mage",5);
   set_stats("intelligence", 16);
   set_stats("wisdom", 12);
   set_stats("strength", 13);
   set_stats("charisma", 9);
   set_stats("dexterity", 16);
   set_stats("constitution", 18);
   add_money("electrum",random(50));
   set_spell_chance(90);
   set_spells(({"color spray","burning hands","lightning bolt","magic missile","magic missile"}));
   command("speech utter with quick, clipped words");
   set_spoken("wizish");
   set_emotes(3,({
     "%^MAGENTA%^Jessa cries out%^RESET%^: Foolish, to test my skills!",
     "%^YELLOW%^Arcs of lightning crackle between Jessa's fingertips.%^RESET%^",
     "%^RED%^Jessa's eyes glitter as a flicker of flame appears upon her palm.%^RESET%^",
   }), 1);
   set_new_exp(1, "very low");
}

void catch_say(string msg){
    if(!interactive(TP)) { return; }
   call_out("reply_func",1,msg,TP);
}

void reply_func(string msg, object who){
   string name;
   name = who->query_name();
   if(!msg || !objectp(who)) return;
   if(who->query_quests()) {
     if(member_array("Found the Staff of Davros",who->query_quests()) != -1) {
       if(!random(4)) {
         force_me("say Thanks again for your help!");
         force_me("emoteat "+name+" shoots $N a grin.");
       }
       if(member_array("Found the staff of Davros but fed it to the mass", TP->query_quests()) != -1)
       {
           if(!random(4))
           {
               force_me("say Thanks again for nothing!");
               force_me("emoteat "+name+" smirks at $N.");
           }
       }
       return;
     }
   }
   asked = SAVE_D->query_array("Jessaquest_asked");
   if((strsrch(msg,"staff") != -1 || strsrch(msg,"Staff") != -1 || strsrch(msg,"reward") != -1) && (member_array(name, asked) != -1)){
     force_me("emote nods.\n");
     force_me("say Well, it's pretty simple, I'm seekin' the staff of Davros "
"Kilgore.  It's said he broke it inta pieces, so no-one could have it after he "
"disappeared.");
     force_me("say Likely at least some of them parts are guarded by his "
"creatures, those horrid little imp-like beasts.  Mephits, they're called.  "
"The rest, well, you'll probably just have to search around.");
     force_me("say If ya manage to find the pieces and %^YELLOW%^assemble"
"%^RESET%^ them, bring the complete staff back 'ere to me.  I'll make it worth "
"your time!");
     force_me("emote grins rogueishly.");
     return;
   }
   if((strsrch(msg,"keep") != -1 || strsrch(msg,"Keep") != -1 || strsrch(msg,"avros") != -1) && (member_array(name, asked) != -1)){
     force_me("emote sets her hands on her hips and peers up at the ruined "
"keep.\n");
     force_me("say This here's the ruins of Keep Kilgore.  Was the property of "
"Davros Kilgore and his lineage for however long.");
     force_me("emote waves a hand dismissively, obviously not interested in "
"his ancestry.");
     force_me("say Anyway, he lived here with his wife and daughter for years, "
"'til they got sick and died, and then he just disappeared.  Since then, the "
"only things that live in here are vermin, though some are bigger than your "
"standard rat.");
     force_me("emote winks.");
     force_me("say Mind your step though, some of his old spells and traps are "
"probably still active.");
     return;
   }
   if((strsrch(msg,"family") != -1 || strsrch(msg,"sickness") != -1) && (member_array(name, asked) != -1)){
     force_me("say Ah, and that's the mystery of it all.");
     force_me("emote 's eyes twinkle with curiosity.");
     force_me("say Tales go that his beloved wife and daughter succumbed to a "
"mystery illness.  It's said he tried all sorts of bizarre wizard's experiments "
"to save them, since he didn't trust the gods or their earthly servants to help "
"him.  Eventually they both died, leaving him alone.  And a few weeks later he "
"just vanished, never to be heard from again.");
     force_me("emote lowers her voice.");
     force_me("whisper "+name+" They said he was a bit mad, ya know.");
     return;
   }
   if(member_array(name, asked) != -1) {
     if(!random(2))
       force_me("say Managed ta find it yet?  If there was something you missed"
", you can always ask.  I can tell you about %^RED%^Davros %^RESET%^or the "
"%^RED%^sickness %^RESET%^that came through here years back.  Or if you're just "
"after the %^RED%^reward%^RESET%^, I can tell ya about that too!");
     return;
   }
   if(strsrch(msg,"ello") != -1 || strsrch(msg,"Hi") != -1 || strsrch(msg,"reeting") != -1 || strsrch(msg,"eya") != -1 || strsrch(msg,"alutation") != -1){
     force_me("emoteat "+name+" looks $N over.");
     force_me("say Heya there, stranger.  I'm Jessa, nomad and arcanist of, "
"well, I guess little note so far.  But I'm working on that!");
     force_me("say This here's %^RED%^Keep Kilgore%^RESET%^, or what's left of "
"it.  Used to be a powerful wizard, %^RED%^Davros%^RESET%^, what lived in here "
"with his family.  His wife and daughter died from some strange %^RED%^sickness "
"%^RESET%^many years back, and he disappeared shortly after that.");
     force_me("say Who knows what he left behind though, right?  I'm looking "
"for a %^RED%^staff %^RESET%^he was known to carry, though it's said he broke "
"it up into pieces to stop anyone else getting their hands on it.  I'll "
"%^RED%^reward %^RESET%^you well if you can bring it back to me!");
     force_me("say If you wanna know more about anything I've told you, just "
"tell me what you wanna hear about!");
     force_me("emote grins rogueishly");
     if(member_array(name, asked) == -1)
       SAVE_D->set_value("Jessaquest_asked", name);
     return;
   }   
   switch(random(10)){
     case 0:
       force_me("emote scratches the bridge of her nose absently as she watches "
"you.");
       break;
     case 1:
       force_me("say Best watch your step, who knows what spells and traps "
"Davros left behind in here...");
       break;
     case 2:
       force_me("say Well, I'm sure someone passing by is interested in a "
"reward...");
       break;
     case 3:
       force_me("emote brushes a lock of stray hair out of her face.");
       break;
     case 4:
       force_me("say Well I certainly can't go inside myself.  I'm sure that "
"would end badly.");
       break;
     case 5:
       force_me("emote seems to be sizing up everyone who passes by.");
       break;
     default:
       force_me("emote glances thoughtfully at you, before turning back to "
"study the keep.");
   }
   return;
}

void receive_given_item(object obj){
   object item;
   asked = SAVE_D->query_array("Jessaquest_asked");
   if(!objectp(obj)) return;
   if(member_array("Found the staff of Davros but fed it to the mass", TP->query_quests()) != -1)
   {
       force_me("say Uh... thanks for nothing!");
       force_me("emoteat "+TPQCN+" smirks at $N.");
       return;
   }
   if(member_array("Found the Staff of Davros",TP->query_quests()) != -1)
   {
      force_me("say Uh.  Thanks again, I think?");
      force_me("emoteat "+TP->QCN+" grins to $N.");
      return;
   }
   if(member_array(TPQN, asked) == -1) {
     force_me("say Heya and thanks I guess.  Have we met?");
     return;
   }   
   if(base_name(obj) != OBJ2"staff") {
     force_me("say Well, it's not really what I'm after, but thanks.");
     force_me("emote shrugs.");
     return;
   }   
   force_me("emote turns the staff over in her hands, examining it carefully.");
   obj->remove();
   if(member_array(TPQN, asked) != -1) 
     SAVE_D->remove_name_from_array("Jessaquest_asked2", TPQN);
   if(objectp(obj = present("newbiemassob", TP))) 
   {
       if((int)obj->query_myTask() == 3) obj->advance_task();
       obj->adjust_my_align(25 + random(25));
   }
   force_me("say Here's something for your trouble!");
   force_me("emote pulls out a pouch of gems from her pocket and hands them "
"across, along with a long folded cloak.");
   item = new(OBJ2"pouch");
   item->move(TO);
   new(OBJ2"gem")->move(item);
   new(OBJ2"gem")->move(item);
   new(OBJ2"gem")->move(item);
   force_me("give pouch to "+TPQN);
   item = new(OBJ2"cloak");
   item->move(TO);        
   item->set_size(TP->query_size());
   force_me("give cloak to "+TPQN);
   force_me("say Made that myself, the cloak.  Well, enchanted it anyway.  Take "
"good care of it!");
   tell_object(TP,"You have finished the Quest to find the Staff of Davros!");
   TP->set_quest("Found the Staff of Davros");
   //TP->fix_exp(1000,TP);
   "/cmds/avatar/_note.c"->cmd_note("add "+TPQN+" Found Davros' Staff!");
   return;
}
