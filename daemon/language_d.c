//Language_d.c
// changed to use the langs.h rather than have it's own list of valid languages
// last change was 7/18/02 *Styx* 9/17/06
// added in undercommon, giant and beast. Nienne 02/08.

#include <std.h>
#include <daemons.h>
#include <langs.h>

#define qp   +tp->QP+

#define CONSTS ({"b","c","d","f","g","h","j","k","l","m","n","p","q","r","s","t","v","w","x","z"})
#define VOWELS ({"a","e","i","o","u","y"})
#define HARDCONSTS ({"b","c","d","f","g","j","k","l","m","p","q","r","s","t","v","x","z","kr","th","ch","sh"})
#define HARDVOWELS ({"e","i","o","u","ou","oo"})
#define SOFTCONSTS ({"b","c","d","f","h","l","m","n","qu","r","s","t","v","w","fr","tr"})
#define SOFTVOWELS ({"a","e","i","o","u","ei","ea","ia"})

inherit DAEMON;

string seed  = "m1KeeLnUp0T70bKqJe2BMUhkdL6Xd9kgA3iM3IQ6QvrH3es07RiPVtK26Z9/fOUS";
int shift = 0;

set_seed(string ss)
{
    shift = 0;
    seed = ss;
}

int random_(int x)
{
    int res;

    if (!sizeof(seed)) {
        res = efun::random(x);
    } else {
        shift++;
        shift = shift > sizeof(seed) ? 0 : shift;
        res = seed[shift] % x;
    }

    return res;
}

varargs string fakeWord(string lang, int l){
   string word = ({});
   int i,j,a;

   switch(lang)
   {
   case "common":
   case "undercommon":
      j = random(4)+4;
      if(a = random(2))
         word = CONSTS[random(sizeof(CONSTS))];
      else
         word = VOWELS[random(sizeof(VOWELS))];
      for (i= 2;i<=j;i++){
         if((i%2 && a) || (!i%2 && !a))
           word += CONSTS[random(sizeof(CONSTS))] ;
         else
           word += VOWELS[random(sizeof(VOWELS))];
      }
      break;
   case "elven":
      j = random(3)+5;
      if(a = random(3))
         word = SOFTCONSTS[random(sizeof(SOFTCONSTS))];
      else
         word = VOWELS[random(sizeof(VOWELS))];
      for (i= 2;i<=j;i++){
         if(i%2 == a){
            word += SOFTCONSTS[random(sizeof(SOFTCONSTS))];
         }
         else{
            word += SOFTVOWELS[random(sizeof(SOFTVOWELS))];
         }
      }
      break;
   case "drow":
      j = random(4)+4;
      if(a = random(3))
         word = CONSTS[random(sizeof(CONSTS))];
      else
         word = VOWELS[random(sizeof(VOWELS))];
      for (i=2;i<=j;i++){
         if(i%2 != a){
            word += HARDCONSTS[random(sizeof(HARDCONSTS))];
            if(random(2)) word += HARDCONSTS[random(sizeof(HARDCONSTS))];
         }
         else
           word += VOWELS[random(sizeof(VOWELS))];
      }
      break;
   case "ogrish":
   case "ogre-magi":
      j = random(3)+2;
      a = random(2);
      word = HARDCONSTS[random(sizeof(HARDCONSTS))];
      for (i= 2;i<=j;i++){
         if(i%2 == a)
           word += HARDCONSTS[random(sizeof(HARDCONSTS))] ;
         else
           word += HARDVOWELS[random(sizeof(HARDVOWELS))];
      }
      break;
   case "gnollish":
   case "bugbear":
   case "orcish":
   case "wemic":
   case "beastman":
   case "beast":
      j = random(4)+3;
      if(a = random(3))
         word = CONSTS[random(sizeof(CONSTS))];
      else
         word = VOWELS[random(sizeof(VOWELS))];
      for (i= 2;i<=j;i++){
         if(i%2 == a){
            word += HARDCONSTS[random(sizeof(HARDCONSTS))];
            if(random(2)) word += HARDCONSTS[random(sizeof(HARDCONSTS))];
         }
         else{
            word += VOWELS[random(sizeof(VOWELS))];
            if(!random(3)) word += HARDVOWELS[random(sizeof(HARDVOWELS))];
         }
      }
      break;
   case "hobgoblin":
   case "goblin":
      j = random(4)+3;
      if(a = random(2))
         word = CONSTS[random(sizeof(CONSTS))];
      else
         word = VOWELS[random(sizeof(VOWELS))];
      for (i= 2;i<=j;i++){
         if(i%2 == a)
           word += CONSTS[random(sizeof(CONSTS))];
         else
           word += VOWELS[random(sizeof(VOWELS))];
      }
      break;
   case "halfling":
      j = random(5)+3;
      if(a = random(2))
         word = CONSTS[random(sizeof(CONSTS))];
      else
         word = SOFTVOWELS[random(sizeof(SOFTVOWELS))];
      for (i= 2;i<=j;i++){
         if(i%2 == a)
            word += SOFTCONSTS[random(sizeof(SOFTCONSTS))] ;
         else{
            word += SOFTVOWELS[random(sizeof(SOFTVOWELS))];
            if(!random(3)) word += SOFTVOWELS[random(sizeof(SOFTVOWELS))];
         }
      }
      break;
   case "firbolg":
   case "giant":
      j = random(4)+3;
      if(a = random(2))
         word = HARDCONSTS[random(sizeof(HARDCONSTS))];
      else
         word = VOWELS[random(sizeof(VOWELS))];
      for (i= 2;i<=j;i++){
         if(i%2 == a){
            word += HARDCONSTS[random(sizeof(HARDCONSTS))];
            if(!random(4)) word += CONSTS[random(sizeof(CONSTS))];
         }
         else
           word += HARDVOWELS[random(sizeof(HARDVOWELS))];
      }
      break;
   case "draconic":
      j = random(4)+3;
      if(a = random(2))
         word = CONSTS[random(sizeof(CONSTS))];
      else
         word = VOWELS[random(sizeof(VOWELS))];
      for (i= 2;i<=j;i++){
         if(i%2 == a)
            word += CONSTS[random(sizeof(CONSTS))];
         else{
            word += VOWELS[random(sizeof(VOWELS))];
            if(!random(3)) word += VOWELS[random(sizeof(VOWELS))];
         }
      }
      break;
   case "gnomish":
      j = random(4)+5;
      if(a = random(2))
         word = CONSTS[random(sizeof(CONSTS))];
      else
         word = VOWELS[random(sizeof(VOWELS))];
      for (i= 2;i<=j;i++){
         if(i%2 == a)
            word += CONSTS[random(sizeof(CONSTS))];
         else{
            word += VOWELS[random(sizeof(VOWELS))];
            if(!random(3)) word += VOWELS[random(sizeof(VOWELS))];
         }
      }
      break;
   case "dwarvish":
      j = random(3)+3;
      a = random(2);
      word = HARDCONSTS[random(sizeof(HARDCONSTS))];
      for (i= 2;i<=j;i++){
         if(i%2 == a)
           word += SOFTCONSTS[random(sizeof(SOFTCONSTS))] ;
         else
           word += HARDVOWELS[random(sizeof(HARDVOWELS))];
      }
      break;
   case "yuan-ti":
      j = random(4)+3;
      a = random(2);
      word = CONSTS[random(sizeof(CONSTS))];
      for (i= 2;i<=j;i++){
         if(i%2 == a)
           word += SOFTCONSTS[random(sizeof(SOFTCONSTS))] ;
         else
           word += SOFTVOWELS[random(sizeof(SOFTVOWELS))];
      }
      break;
   default:
     j = l?l:random(6)+3;
      if(a = random(2))
         word = CONSTS[random(sizeof(CONSTS))];
      else
         word = VOWELS[random(sizeof(VOWELS))];
      for (i= 2;i<=j;i++){
         if(i%2 == a)
           word += CONSTS[random(sizeof(CONSTS))] ;
         else
           word += VOWELS[random(sizeof(VOWELS))];
      }
      break;
   }
   return word;
}

string query_animal_emotes(string words,object tp)
{
    int size;
    string emote_length,emote,*emotes=({}),race;
    object shape;

    if(!stringp(words) || words == "" || words == " ") { return 0; }

    size = sizeof(explode(words," "));

    if(size < 5)                { emote_length = "small"; }
    if(size >= 5 && size < 15)  { emote_length = "medium"; }
    if(size >= 15)              { emote_length = "large"; }

    if(objectp(shape = tp->query_property("shapeshifted")))
    {
        race = (string)shape->query_shape_race();
    }
    else
    {
        race = (string)tp->query_race();
    }

    switch(emote_length)
    {

    case "small": // long emotes

        switch(race)
        {

        case "wolf":

            emotes = ({
                "growls quietly",
                "shakes "qp" head",
                "wags "qp" tail",
            });

            break;

        case "bear":

            emotes = ({
                "bellows loudly",
                "paws the ground",
                "opens "qp" mouth widely",
            });

            break;

        case "cat":

            emotes = ({
                "extends "qp" claws",
                "swats at the air",
                "flicks "qp" tail",
            });

            break;

        case "elemental":

            emotes = ({
                "sinks towards the ground",
                "freezes in place",
                "sways to one side",
            });

            break;

        case "draconic":

            emotes = ({
                "drums "qp" claws on the ground",
                "rumbles quietly",
                "flaps "qp" wings",
            });

            break;

        case "small animal":

            emotes = ({
                "sits up and squeeks",
                "chirps excitedly",
                "thumps "qp" rear foot on the ground",
            });

            break;

        case "large animal":

            emotes = ({
                "snorts loudly",
                "cants "qp" head to one side",
                "drags "qp" front foot on the ground",
            });

            break;

        default:

            emotes = ({ "makes some growling and chittering sounds" });
            break;
        }

        break;



    case "medium": // medium emotes for short sentences

        switch(race)
        {

        case "wolf":

            emotes = ({
                "yips and quirks "qp" to the side",
                "lowers "qp" head and growls",
                "flips "qp" tail side to side",
            });

            break;

        case "bear":

            emotes = ({
                "opens "qp" maw and scratches the ground",
                "snorts loudly and claws at the ground",
                "shifts "qp" weight back and forth",
            });

            break;

        case "cat":

            emotes = ({
                "slinks "qp" head slowly down towards the ground",
                "raises "qp" tail and stands up tall",
                "rumbles a throaty growl deep in "qp" throat",
            });

            break;

        case "elemental":

            emotes =({
                "raises "qp" arms into the air and fans them out",
                "twirls in a quick circle",
                "crouches and shakes slowly to and fro",
            });

            break;

        case "draconic":

            emotes = ({
                "emits a quick series of reverberating growls",
                "shakes "qp" scales and quickly twists "qp" head",
                "straightens "qp" neck and glowers ahead",
            });

            break;

        case "small animal":

            emotes = ({
                "chatters quickly while shuffling "qp" feet",
                "chirps excitedly",
                "darts in a small circle",
            });

            break;

        case "large animal":

            emotes = ({
                "stamps the ground hard",
                "paws at the ground then snorts",
                "shakes "qp" head quickly back and forth",
            });

            break;

        default:

            emotes = ({ "makes some growling and chittering sounds" });
            break;
        }

        break;



    case "large": // large emotes

        switch(race)
        {

        case "wolf":

            emotes = ({
                "paces in a series of quick circles then stops, shaking "qp" head to and fro before scratching the ground and whining",
                "sits on "qp" haunches and licks "qp" paw for a moment before quickly hopping to "qp" feet and letting out an excited yip",
                "trots in a jagged line and then slinks low on "qp" stomach, almost crawling, then emits a low, throaty growl",
            });

            break;

        case "bear":

            emotes = ({
                "stands on "qp" hind legs and roars before dropping back onto all fours and swaying side to side",
                "quickly stamps on the ground with both front legs before twisting "qp" head far to one side, and then the other",
                "charges forwards and then stops abruptly, lowering "qp" head with a loud growl before swaying side to side",
            });

            break;

        case "cat":

            emotes = ({
                "emits a terrifying howl and then growls before spinning in a series of quick circles and flicking "qp" tail",
                "extends "qp" claws and digs a ragged gash at the ground before sitting back on "qp" hanuches and lazily lapping "qp" paw"
                "sits high up on "qp" haunches and extends one claw into the air, slowly swatting at nothing before dropping back onto all fours",
            });

            break;

        case "elemental":

            emotes = ({
                "flattens into nearly a two dimensional image before swelling back to normal size then holding very still",
                "rocks side to side, moving "qp" entire body with a wavelike motion before spinning twice and stopping",
                "steps quickly backwards and then forwards before straightening and growing taller for a moment",
            });

            break;

        case "draconic":

            emotes = ({
                "snaps "qp" maw of razor sharp teeth closed in a sudden rush and then straightens "qp" neck before "qp" whole body shudders",
                "emits a long, low rumble from deep within "qp" chest before extending "qp" wings wide and then folding them back by "qp" side",
                "flaps "qp" wings and momentarily climbs into the air, turning an circle before effortlessly settling back to the ground",
            });

            break;

        case "small animal":

            emotes = ({
                "jumps high into the air and lands at a dead sprint, turning a series of fast circles before stopping instantly and looking straight ahead",
                "rapidly begins digging at the ground before stopping and looking up as "qp" ears twitch forward then to the sides",
                "twitches "qp" nose and raises "qp" small hands to "qp" mouth, chittering loudly before darting in a quick circle and sitting on "qp" haunches",
            });

            break;

        case "large animal":

            emotes = ({
                "snorts loudly and rushes off in a broad circle, tail flipping about this way and that before "+tp->QS+" comes to a halt and looks straight ahead",
                "sits back on "qp" haunches and bellows loudly before climbing onto "qp" feet and stamping a single front leg hard against the ground",
                "plods slowly forwards and stops before turning to the side and running in a slow circle and shaking "qp" head",
            });

            break;

        default:

            emotes = ({ "makes some growling and chittering sounds." });
            break;
        }

        break;
    }

    emote = emotes[random(sizeof(emotes))];

    return emote;
}

string animal_translate(string str,string lang, object player)
{
    int prof, i,j, thing,wrong,right;
    string *words, ret = "",speech,describe;

    if(!objectp(player)) { return str; }

    prof = (int)player->query_lang(lang);

    if(prof == 100)
    {
        return str;
    }

    words = explode(str," ");

    for(i=0;i<sizeof(words);i++)
    {
        if(random(100) > prof)
        {
            wrong++;
        }
        else
        {
            ret += words[i]+" ";
            right++;
	        thing++;
        }
    }

    if(strlen(ret) > 1) // get rid of the blank space at the end, important for how it's handled in user.c
    {
        ret = ret[0..(strlen(ret) - 2)];
    }

    return ret;
}


varargs string translate(string str, string lang, object player,int reading)
{
    int prof, i,j, thing,read_time;
    string *words, ret = "";

    if (!objectp(player)) {
        return str;
    }

    if (lang == "wizish") {
        return str;
    }

    prof      = (int)player->query_lang(lang);
    read_time = (int)player->query_property("last_time_read");

    if(objectp(player))
    {
        if(player->query_property("verstandnis")) return str;
    }

    if(prof >= 100)
    {
        if(player != TP || query_verb() == "read")
        {
            if(!functionp(str)) { if(str[0..0] == " ") return " ("+lang+")"+str; }
            return " ("+lang+") "+evaluate(str);
        }
        else
        {
            return str;
        }
    }

    words = explode(str," ");
    j = sizeof(words);

    for(i=0;i<j;i++)
    {
        if(random(100) > prof)
        {
	        words[i] = fakeWord(lang);
        }
        else
        {
	        thing++;
        }
        ret+= words[i] + " ";
    }

    if(prof > 0)
    {
        if(!reading)
        {
            player->add_grammar(lang,thing*2);
        }
        else if(time() > read_time)
        {
            player->add_grammar(lang,thing*2);
            player->remove_property("last_time_read");
            player->set_property("last_time_read",time() + 300); // five minute delay
        }
    }

    if(prof > 50)
    {
        if(ret[0..0] == " ") return " ("+lang+")"+ret;
        else return " ("+lang+") "+ret;
    }
    else
    {
        return ret;
    }
}
