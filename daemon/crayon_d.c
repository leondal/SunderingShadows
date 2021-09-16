#include <std.h>
#include <daemons.h>
#include <security.h>

inherit DAEMON;
#define SAVE_FILE "/daemon/save/saved_schemes"
#define CAPS "ABCDEFGHIJKLMNOPQRSTUVWXYZ"

#define R "%^RED%^"
#define G "%^GREEN%^"
#define B "%^BLUE%^"
#define C "%^CYAN%^"
#define M "%^MAGENTA%^"
#define Y "%^YELLOW%^"
#define L "%^BOLD%^%^BLACK%^"
#define O "%^ORANGE%^"
#define D "%^BOLD%^"
#define S "%^RESET%^"
#define E "%^RESET%^%^BOLD%^"

string COLORS = ({ "%^RED%^","%^BLUE%^","%^ORANGE%^","%^YELLOW%^","%^GREEN%^","%^BOLD%^%^BLACK%^","%^CYAN%^","%^MAGENTA%^","%^BOLD%^","%^RESET%^" });

// doesn't work as a preprocessor directive with #define for some reason, has me completely baffled -Ares
// will have to add quite a few more words to this
string COMMON = ({  "(wielded", "(worn)", "I", "after", "again", "all", "almost", "also", "although", "and", "anywhere", "are", "around",
                    "assuming", "atop", "back", "be", "because", "been", "before", "begins", "behind", "beside", "besides", "both", "but",
                    "by", "can", "can't", "case", "certain", "contains", "conversely", "could", "each", "early", "either", "empty", "even",
                    "ever", "fact", "feel", "few", "first", "fit", "for", "form", "from", "front", "full", "furthermore", "get", "half",
                    "hand", "hand)", "hand),", "hand).", "hardly", "has", "have", "hear", "hearing", "her", "here", "hers", "herself",
                    "himself", "his", "hit", "how", "however", "i", "if", "impossible", "in", "instant", "instead", "into", "it", "it's",
                    "its", "itself", "just", "keeps", "large", "late", "later", "left", "lest", "like", "likewise", "looks", "lower",
                    "lowers", "made", "many", "matter", "moreover", "much", "multiple", "must", "near", "nearly", "neither","nevertheless",
                    "nonetheless", "nor", "of", "off", "on", "once", "only", "open", "or", "other", "otherwise", "out", "perhaps", "possible",
                    "prone", "provided", "put", "puts", "raise", "raises", "rather", "right", "scarcely", "seem", "seems", "self", "several",
                    "should", "shut", "sight", "since", "small", "snap", "snaps", "so", "some", "soon", "sooner", "still", "such", "sure",
                    "take", "taken", "than", "that", "the", "their", "them", "then", "there", "these", "they", "this", "those", "though",
                    "through", "till", "to", "too", "towards", "type", "uncertain", "undecided", "unless", "until", "various", "very", "way",
                    "well", "what", "when", "whenever", "where", "whereas", "wherever", "whether", "which", "whichever", "while", "who",
                    "whoever", "whole", "whom", "whomever", "whose", "why", "wielded", "will", "with", "worn", "would", "yet", "you", "your",
                    "yourself", "nearby", });


mapping users, schemes;

void create(){
    ::create();
    users = ([]);
    schemes = ([]);
    seteuid(UID_DAEMONSAVE);
    restore_object(SAVE_FILE,1);
    seteuid(getuid());
}

void save_scheme(string user, string scheme_name, mapping scheme) {
    string *usernames, *scheme_names;

    if(!mapp(users) || sizeof(users) < 1) users = ([]);

    if(mapp(users) && sizeof(users) > 0) {
        usernames = keys(users);
        if (member_array(user, usernames) != -1) {
            schemes = users[user];
        }
        else schemes = ([]);
    }
    else {
        users = ([]);
        schemes = ([]);
    }

    if(mapp(schemes) && sizeof(schemes) > 0) {
        scheme_names = keys(schemes);
        if(member_array(scheme, scheme_names) != -1) {
            schemes = m_delete(schemes, scheme_name);
        }
    }

    schemes[scheme_name] = scheme;
    users[user] = schemes;
    SAVE();
}

mapping query_schemes(string user) {
    string *usernames;

    if (!mapp(users) || sizeof(users) < 1) return ([]);
    usernames = keys(users);
    if (member_array(user, usernames) == -1) return ([]);
    schemes = users[user];
    if (!mapp(schemes) || sizeof(schemes) < 1) return ([]);

    return schemes;
}

int remove_scheme(string user, string scheme_name){
    string *usernames, *scheme_names;

    if (!mapp(users) || sizeof(users) < 1) return 0;
    usernames = keys(users);
    if (member_array(user, usernames) == -1) return 0;
    schemes = users[user];
    if (!mapp(schemes) || sizeof(schemes) < 1) return 0;
    scheme_names = keys(schemes);
    if (member_array(scheme_name, scheme_names) ==- 1) return 0;

    schemes = m_delete(schemes, scheme_name);
    users[user] = schemes;
    SAVE();

    return 1;
}

void SAVE(){
    seteuid(UID_DAEMONSAVE);
    save_object(SAVE_FILE);
    seteuid(getuid());
}

// will occasionally need to run better_list() function and replace common above, just filters out duplicate words and sorts alphabetically
string *better_list()
{
    string *better = COMMON;
    better = distinct_array(better);
    better = sort_array(better, "alphabetical_sort",FILTERS_D);
    return better;
}

int is_vowel(string letter)
{
    string *vowels = ({ "a","e","i","o","u" });
    if(!stringp(letter) || !strlen(letter) || (strlen(letter) != 1)) { return 0; }
    if(member_array(letter,vowels) == -1) { return 0; }
    return 1;
}


int num_vowels(string word)
{
    string *letters;
    int vowels,i;
    if(!stringp(word) || !strlen(word)) { return 0; }
    letters = explode(word,"");
    for(i=0;i<sizeof(letters);i++)
    {
        if(!is_vowel(letters[i])) { continue; }
        vowels++;
    }
    return vowels;
}


// for a custom color scheme, you need a mapping with the following stuff in it:
// substitute your own color codes
/*
mapping map             = ([]);
map["back color"]       = "%^BLUE%^";
map["common colors"]    = ({ "%^BLUE%^", "%^RED%^", "%^MAGENTA%^", "%^BOLD%^%^BLACK" });
map["rare colors"]      = ({ "%^ORANGE%^", "%^YELLOW%^", "%^GREEN%^", "%^CYAN%^" });
map["scatter"]          = 4; // tendency to use a lot of colors per word (scale of 1 to 10,  1 is only one color per word, 10 is a different color for every letter of every colored word)
*/
mapping color_scheme(string scheme)
{
    mapping map = ([]);
    string back_color,*common_colors, *rare_colors, *rand_colors=({}), *rand = ({});
    string *possible = ({ R, B, O, Y, G, L, C, M, D, S, D+R, D+B, D+O, D+Y, D+G, D+C, D+M, S+D });
    int scatter;

    rand_colors = ({"dark","dark red","red and black","dark black","very black","dark green","green","light green","rand" });
    if(scheme == "random") { scheme = rand_colors[random(sizeof(rand_colors))]; }

    switch(scheme)
    {
    case "grey":
    case "gray":
        back_color = E;
        common_colors = ({ S, C, B });
        rare_colors = ({ M, L, D });
        scatter = 2;
        break;
    case "crazy":
        back_color = Y;
        common_colors = ({ B, G, Y, C, L, R, M });
        rare_colors = ({ O });
        scatter = 10;
        break;
    case "dark":
        back_color = B;
        common_colors = ({ B,R,M,L });
        rare_colors = ({ O,Y,G,C });
        scatter = 4;
        break;
    case "dark red":
        back_color = R;
        common_colors = ({ B,Y,O,L });
        rare_colors = ({ S,M });
        scatter = 3;
        break;
    case "fire red":
        back_color = R;
        common_colors = ({ B,Y,O });
        rare_colors = ({ M });
        scatter = 2;
        break;
    case "red and black":
        back_color = L;
        common_colors = ({ R });
        rare_colors = ({ D });
        scatter = 3;
        break;
    case "dark black":
        back_color = L;
        common_colors = ({ S,D,B,G });
        rare_colors = ({ C,M,O });
        scatter = 3;
        break;
    case "very black":
        back_color = L;
        common_colors = ({ D,B });
        rare_colors = ({ C,S });
        scatter = 3;
        break;
    case "flat black":
        back_color = L;
        common_colors = ({ B });
        rare_colors = ({ L });
        scatter = 2;
        break;
    case "dark green":
        back_color = G;
        common_colors = ({ G,D,S,Y,L });
        rare_colors = ({ R,B,C });
        scatter = 5;
        break;
    case "green":
        back_color = G;
        common_colors = ({ G,D,S,Y,C });
        rare_colors = ({ R,B,L });
        scatter = 5;
        break;
    case "light green":
        back_color = D+G;
        common_colors = ({ D,S,Y,C });
        rare_colors = ({ R,B,L,M });
        scatter = 6;
        break;
    case "sierra":
        back_color = L;
        common_colors = ({ R, M, L});
        rare_colors = ({S,S+D,M,D+M});
        scatter = 3;
        break;
    case "whisper":
        back_color = C;
        common_colors = ({C});
        rare_colors = ({S+D,D+O,O,D+C,L});
        scatter = 2;
        break;
    case "lightning yellow":
        back_color = Y;
        common_colors = ({ Y, D + Y, L });
        rare_colors = ({ C });
        scatter = 2;
        break;
    case "ice blue":
        back_color = C;
        common_colors = ({ C, D + C, L });
        rare_colors = ({ B });
        scatter = 2;
        break;
    case "acid green":
        back_color = G;
        common_colors = ({ G, D + G, Y });
        rare_colors = ({ C });
        scatter = 2;
        break;
    case "rand":
    default: // completely random, there's no telling what we'll get here
        back_color = possible[random(sizeof(possible))];
        while(sizeof(rand) < (roll_dice(1,3) + 2))
        {
            rand += ({ possible[random(sizeof(possible))] });
            rand = distinct_array(rand);
        }
        common_colors = rand;
        possible -= rand;
        rand = ({});
        while(sizeof(rand) < (roll_dice(1,2) + 2))
        {
            rand += ({ possible[random(sizeof(possible))] });
            rand = distinct_array(rand);
        }
        rare_colors = rand;
        scatter = roll_dice(1,6);
        break;
    }

    map["back color"]    = back_color;
    map["common colors"] = common_colors;
    map["rare colors"]   = rare_colors;
    map["scatter"]       = scatter;

    return map;
}

void db(string str)
{
    return;
}


int is_cap_word(string str)
{
    string first, next;
    if(!stringp(str) || !strlen(str)) { return 0; }
    first = str[0..0];
    if(strlen(str) > 1) { next = str[1..1]; }
    if(member_array(first,explode(CAPS,"")) == -1) { return 0; }
    if(member_array(next,explode(CAPS,"")) !=-1) { return 0; }
    return 1;
}

// returns 0 if it's one of the common words defined above
// they are used as the first filter to determine if the
// word gets special colors
int common_check(string word)
{
    string *bad_end = ({ "ly","ng","ed","ly,","ly.","ng,","ng.","ed,","ed." });
    int length;
    string *end;

    if(!stringp(word) || !strlen(word)) { return 0; }
    word = lower_case(word);
    length = strlen(word);
    if(length < 3) { return 0; }
    if(length > 2)
    {
        end = word[(length-2)..(length-1)];
        if(member_array(end,bad_end) != -1) { return 0; }
    }
    if(member_array(word,COMMON+COLORS) != -1) { return 0; }

    return 1;
}


// checks if a word is one of the specials provided
int special_check(string word, string *special)
{
    word = lower_case(word);
    if(!stringp(word) || !strlen(word)) { return 0; }
    if(!pointerp(special) || !sizeof(special)) { return 0; }
    if(member_array(word,special) != -1) { return 1; }
    return 0;
}


string strip_punctuation(string word)
{
    string *bad = ({ ",","!","@","#","$","%","^","&","*","_","+","=",":",";"," ","." });
    int i;
    for(i=0;i<sizeof(bad);i++)
    {
        word = replace_string(word,bad[i],"");
    }
    return word;
}


// adds a word to the list to get colored, if it's not already in the list
mapping add_word(string word, mapping map)
{
    string *words;
    words = keys(map);

    word = strip_punctuation(word);

    if(!sizeof(words) || (member_array(word, words) == -1))
    {
        map += ([ word : word ]);
        return map;
    }
    return map;
}




// make sure bold, reset and base color don't get counted along with colors
// probably should use a 50/50 chance for bold on a color, then once bold has been used
// on a color once in a word, it should have a higher chance of being used on the same word
string color_word(string word, string *common_colors, string *rare_colors, int scatter, string back_color, int cancel_bold)
{
    string *letters,*to_use=({}),start_color;
    int colors_used,base_chance,num_colors,i,*colors=({}),color,vowels,mod;
    if(!stringp(word) || !strlen(word)) { return word; }

    if(scatter < 1) { scatter = 1; }
    if(scatter > 10) { scatter = 10; }

    letters = explode(word,"");
    base_chance = scatter-1;
    num_colors = 1;

    // determines the amount of colors in the word based on the amount of letters in the word
    // and the scatter setting. Higher scatter is larger chance of lots of color in each word
    for(i=0;i<sizeof(letters);i++)
    {
        if(roll_dice(1,10) > base_chance)
        {
            if(!is_vowel(letters[i])) { base_chance--; }
            continue;
        }
        num_colors++;
    }

    if(!num_colors) { num_colors = 1; }
    // determics which colors are actually selected
    // common colors have about a 60% chance per color to be picked
    // rare colors have about a 20% chance to be picked
    while((sizeof(colors) < num_colors) && (sizeof(colors) < sizeof(letters)) && i < 100)
    {
        if((roll_dice(1,10) > 4) && sizeof(common_colors))
        {
            color = common_colors[random(sizeof(common_colors))];
            common_colors -= ({ color });
            colors += ({ color });
            colors = distinct_array(colors);
            continue;
        }
        else if( (roll_dice(1,10) > 8) && sizeof(rare_colors))
        {
            color = rare_colors[random(sizeof(rare_colors))];
            rare_colors -= ({ color });
            colors += ({ color });
            colors = distinct_array(colors);
            continue;
        }
        i++;
        colors = distinct_array(colors);
        continue;
    }

    if(!sizeof(colors)) { colors = ({ back_color }); }

    // determines if the colors should be bolded or not
    // 50/50 chance
    if(!cancel_bold)
    {
        for(i=0;i<sizeof(colors);i++)
        {
            if(roll_dice(1,10) > 5)
            {
                colors[i] = S + D + colors[i];
            }
            else
            {
                colors[i] = S + colors[i];
            }
        }
    }

    to_use = colors;
    mod = sizeof(to_use);

    // assigns the first color in the word to the first color picked

    start_color = colors[0];
    letters[0] = start_color + letters[0];
    to_use -= ({ start_color });

    // checks if there are a lot of vowels, if there are, we color these first
    vowels = num_vowels(word);

    // this should get ignored completely if there's only one color in the word
    // otherwise color letters based on scatter and size of word and number of vowels in word
    if((sizeof(letters) > 1) && (sizeof(colors) > 1))
    {
        for(i=1;i<sizeof(letters);i++)
        {
            if(sizeof(to_use))
            {
                color = to_use[random(sizeof(to_use))];
                to_use -= ({ color });
            }
            else
            {
                color = colors[random(sizeof(colors))];
            }

            if(vowels >= sizeof(colors))
            {
                if(is_vowel(letters[i]))
                {
                    if(sizeof(to_use) > 0)
                    {
                        letters[i] = color + letters[i];
                    }
                    else
                    {
                        letters[i] = start_color + letters[i];
                    }
                }
            }
            else
            {
                if(scatter + mod > roll_dice(1,10))
                {
                    letters[i] = color + letters[i];
                    mod = sizeof(colors);
                }
                else
                {
                    letters[i] = start_color + letters[i]+"";
                    mod++;
                }
            }
        }
    }

    word = implode(letters,"");
    if(!cancel_bold) word = word + S;
    word = word + back_color;
    return word;
}


int descending_size(string one, string two)
{
    if(strlen(one) == strlen(two)) { return 0; }
    if(strlen(one) > strlen(two)) { return -1; }
    return 1;
}


string color_words(string str, mapping map, mapping scheme, int cancel_bold)
{
    string back_color,*common_colors, *rare_colors,*words,word;
    int scatter,i;

    if(!mapp(scheme) || sizeof(keys(scheme) != 4)) { return str; }

    back_color = scheme["back color"];
    common_colors = scheme["common colors"];
    rare_colors = scheme["rare colors"];
    scatter = scheme["scatter"];


    str = back_color + str;
    if(!cancel_bold) str + S;
    words = keys(map);
    words = sort_array(words,"descending_size");

    for(i=0;i<sizeof(words);i++)
    {
        word = words[i];
        word = color_word(word, common_colors, rare_colors, scatter, back_color, cancel_bold);
        map[words[i]] = word;
    }

    for(i=0;i<sizeof(words);i++)
    {

        str = replace_string(str, words[i], map[words[i]]);
    }

    return str;
}


varargs string color_string(string str, string scheme, string *special, mapping custom, string *exclude, int cancel_bold)
{
    string *sentences,*words,sentence,first_word,final;
    mapping map=([]),color_scheme;
    int i,j;

    if(!stringp(str) || !strlen(str)) { return 0; }
    sentences = explode(str,".");

    for(i=0;i<sizeof(sentences);i++)
    {
        sentence = sentences[i];
        if(!stringp(sentence) || !strlen(sentence)) { continue; }

        words = explode(sentence," ");

        if(sizeof(words) > 0)
        {
            for(j=0;j<sizeof(words);j++)
            {
                if(sizeof(exclude))
                {
                    if(member_array(words[j],exclude) != -1) { continue; }
                }
                if(j == 0)
                {
                    first_word = words[j];
                    if(special_check(first_word, special) || common_check(first_word))
                    {
                        map = add_word(first_word,map);
                        continue;
                    }
                }

                if(special_check(words[j], special) || common_check(words[j]))
                {
                    map = add_word(words[j],map);
                }
            }
        }
    }

    if(!mapp(custom) || (sizeof(keys(custom)) != 4))
    {
        color_scheme = color_scheme(scheme);
    }
    else { color_scheme = custom; }

    final = color_words(str,map,color_scheme,cancel_bold);
    return final;
}
