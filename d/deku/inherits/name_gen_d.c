#include <std.h>
#include <daemons.h>
#define DN_AR "deku_dead_names_array"
#define MN_AR "deku_missing_names_array"
#define DNAU_AR "deku_dead_names_used_array"
#define MNAU_AR "deku_missing_names_used_array"

#define NAMES ({"aber","ablamar","accolon","adlar","alhandra",\
"almax","alper","alysan","amandis","amidee","andrella","anglides",\
"anneth","annowre","anrod","ansirus","arla","ardel","arian","arlen",\
"arlenda","arlis","arpad","arrness","arthad","aseneth","astra","avenal",\
"bae","bailey","ballard","bedwyr","belinase","belloc","belnoy",\
"bendekar","bernal","bersalles","berwyn","blaise","bodwyn","bret",\
"brianna","brilman","bryman","burlac","burne","cadwyn","calista",\
"calley","callum","calmert","candella","cathloy","cathra","cedras",\
"chantel","charl","claudus","claisant","cobb","coburne","cole",\
"colvin","corbin","corwyn","dafyn","damas","danel","danly","dara",\
"darian","darla","darley","decius","denira","deraks","devereau",\
"devis","dilys","dinadus","dor","dorian","dubricus","dudley","durga",\
"durnsay","dynas","ebb","eckusan","elayne","eliph","elizar","elyas",\
"emher","enide","erbin","erroll","ettard","evaine","fen","fliban",\
"galashin","galen","gar","garath","garlon","gelpas","genievre",\
"gerard","gevies","gilles","greeves","grellyn","gristla","gwenta",\
"gwenelan","gwenned","gwydion","gwydre","gwyon","hacasin","hacmed",\
"harkin","harlonus","helain","helyes","hemisal","hennet","herlew",\
"herm","hervor","hodge","hoel","huber","hydwen","jacasin","jadale",\
"jader","jankin","jarri","jarvis","jerick","jenelle","jess","joachim",\
"jolan","jordanus","jozan","jud","kae","kaywen","kebel","karris",\
"kendall","keriann","kimber","kira","kither","kyanus","lacenor",\
"lamork","leigh","lin","llywellan","londa","loy","luce","lum",\
"lunete","lyge","lyman","lynette","lynores","lyons","lysette",\
"lyzanor","maevis","magh","magoun","maharis","mara","marieka",\
"marly","mathias","mede","megaera","menander","mere","migdalia",\
"miles","mobley","myla","myrr","nadya","naramis","nascen","neanne",\
"neb","nedaph","neith","nessi","neva","nira","nissa","noch","norgalis",\
"noewll","nyfer","obyn","omig","orbri","orm","orph","peta","petrique",\
"plase","ponj","priadan","quint","rafe","reece","regdar","relkin",\
"reswald","ruther","rydel","reyott","sabine","sapphira","seith",\
"sephora","serpe","sigfa","sinnoch","surmal","tabra","taff","tagli",\
"tallis","tam","tangye","tanith","tarlach","tarpeia","tathal",\
"tegyr","tessa","therise","thomas","travers","trig","tulloch",\
"tully","tydd","unwyn","valdis","vardalon","varlay","varn",\
"vayshor","wace","walther","welcar","weldun","wigan","wilton",\
"wledig","woller","wort","wulik","wylie","xavia","ydey","yelda",\
"yon","yvette","ywaine","zander","zahrdahl","agnar","algar",\
"andred","angantyr","asgrim","atli","auda","aurgelmyr","aurus",\
"aylor","balmek","batava","belvar","bethnos","beyla","blaine","blon",\
"bothvar","brueyan","cardon","cardual","colmark","dagmar","dorag",\
"dorin","dormar","dorn","durbar","durifer","durney","duwas","dyall",\
"eja","enton","erac","erall","ercan","eric","esgir","euwas","eyjulf",\
"falco","fech","ferh","finbar","fijar","foriel","framm","fraunk",\
"fumok","galapas","gangleri","geirmund","geirrod","gerar","gloier",\
"gofnyr","gorwinay","gothrom","grennel","griff","grimm","grimnyr",\
"grimslad","grummore","grummer","gulrod","gulnyr","guthorm","gymir",\
"halco","halprek","hamnyr","harvarr","hedrieks","heimyr","heliap",\
"helcar","heth","himlung","hleid","hluahl","hodd","hoff","hreidmar",\
"hrif","hringrim","hrotyr","hrusk","hrund","izhilem","jaer","jarnuk",\
"jemrik","jodmar","jormun","kogyr","kord","krelar","laufney","lorac",\
"lucan","lutor","macsen","magnus","magnyr","mal","malgrim","manasen",\
"marrok","maros","martel","mellard","melnyr","merla","minadus",\
"murfils","naegel","narbeth","naripaul","narivissal","narr",\
"nartach","ndils","neson","norvi","ogmi","ogmore","ormund","ossan",\
"ost","otar","pharien","pharnos","phiden","prellis","quanzar",\
"rannos","rathyen","raynor","reaf","relmar","roake","rostenoc"})

#define MNAMES ({"parlee","parwyn","pelltar","peren","raede",\
"rahasia","raniel","remaelde","rentar","reuel","rhaine","rianneth",\
"rinya","roadyn","runir","selcar","seledra","selwyn","seriade",\
"shanna","sharlea","shay","silenna","silevran","soveliss",\
"taleraed","tarbenay","taratar","taulured","telmar","terari",\
"thaniel","thaedras","twyll","uel","vadania","veasse","venye",\
"verraine","wendelain","ysberyl","yslar","zelmar","ahtva","annikko",\
"aolor","apnee","arn","balto","birzoon","bitha","bramo","cirilli",\
"cline","crayloon","cuirboly","dak","eckel","ensu","erb","erkenwald",\
"finla","furduch","gormadoc","gostegottl","gundigoot","gwaylar",\
"halanan","hallap","hamarka","hensu","hewett","hoch","hoose",\
"igsenki","ikitur","jaroo","juutar","kantelleki","kasma","kutar",\
"kyliki","lakajan","larimo","lelmose","lotch","lynen","malesacar",\
"miep","mirge","moczama","myroc","nebin","nizam","noj","norbor",\
"notar","nuados","osomo","oyun","pello","penabwa","piletti",\
"pinker","poot","quonzar","ramne","redef","sahir","samoinan",\
"sahtwyrn","spah","spugnor","suram","swa","tahir","tamatar",\
"tamora","tamoinen","thrang","uani","uli","unferth","unqin",\
"verhoo","veter","vlodge","voynan","wilf","yarol","yipwyg",\
"zupesh","zygur","achim","albie","alton","amabelle","asham",\
"ashford","astin","barthony","beasley","beaswell","bertik",\
"bertrad","blasco","bredon","bree","briley","burgis","burke",\
"canty","carruthers","chandry","chibald","cibber","cottington",\
"crowley","cubbardy","dee","dekker","dendy","dobb","drayton",\
"dudney","dugal","dunleary","dyer","eldren","ellyot","eucken",\
"fashi","fenton","fenwark","gascoyn","gentry","giles","googe",\
"gosson","hesselwhite","hobb","hobbin","hoby","hodkin",\
"holquiss","jaq","jenkin","joop","joost","kelsoe","kemble",\
"kent","ketta","lane","leese","lidda","linshey","linton",\
"lodge","lollard","ludwedge","lyly","lynwerd","maere","map",\
"marlow","marston","martobee","mendel","merrick","merridee",\
"misha","mosely","moss","murr","nashe","niles","nivers",\
"norbe","nython","orlane","otem","parse","pence","penge",\
"plunkett","pomme","pons","poole","quettery","quillan","quince",\
"quinn","reene","reeve","reswald","ruskin","seldon","sime",\
"spence","syler","talbot","tananger","taqi","tarby","tarquin",\
"tasse","taum","tavi","tella","tew","thame","thorne","tibbs",\
"tichbourne","tyman","tyndal","valens","vaughn","vicars","wade",\
"warwyck","wat","watters","wim","wyatt","agar","akaros","arrakk",\
"augh","bree","bruegar","dahk","derkk","devdas","dgul","drood",\
"druuk","eagol","edals","ekk","franch","fukel","gaaki","gar",\
"garlak","ghorn","gnarsh","gnarsht","gobar","gogar","grai",\
"gremog","grigri","grimslade","grinkel","gronz","gugal","guzud",\
"gynk","hargul","harll","hogar","honzu","hoog","hool","hordar",\
"horrach","hoygh","huagh","huru","jhanzur","jutor","jzets",\
"kalip","karash","kol","korgul","krell","krusk","lagazi","lorzak",\
"lubash","lugh","mimerk","mord","murook","nizam","nogu","nyarl",\
"omotar","ohr","ohtar","ootah","orngart","ordich","oth","parih",\
"puyet","puyetto","raorr","rendar","rheen","sark","scrag","sorgh",\
"taing","tanglar","tarak","targ","tawar","thar","thoin","toemor",\
"tomph","toop","trood","tulmark","tupacu","tzens","ubada","udhgar",\
"ugarth","ungar","ungvar","urzad","vaath","vanchu","vtam","whudu",\
"wogg","wogar","wrnach","wung","wykks","xar","xtec","yark",\
"yazar","yetto","yurk","zarx","zotl","zuboko","aberdil","avenigart",\
"breitheim","beilunn","creegan","druskedan","duril","fadenhiem"})

inherit DAEMON;
void make_name(string array,string arraytwo);

void make_dead_name_list() {
    int x, y;
    y = sizeof(SAVE_D->query_array(DN_AR));
    if(y < 25) {
        for(x = 0;x < 25 - y;x++) {
            make_name(DN_AR,DNAU_AR);
        }
    }
}

void make_missing_name_list() {
    int x, y;
    y = sizeof(SAVE_D->query_array(MN_AR));
    if(y < 25) {
        for(x = 0;x < 25 - y;x++) {
            make_name(MN_AR,MNAU_AR);
        }
    }
}

void make_name(string str, string strtwo) {
    string first_name, last_name,name;
    switch(random(2)) {
        case 0: 
            first_name = NAMES[random(sizeof(NAMES))];
            last_name = MNAMES[random(sizeof(MNAMES))];
            break;
        case 1:
            first_name = MNAMES[random(sizeof(MNAMES))];
            last_name = NAMES[random(sizeof(NAMES))];
            break;
    }
    name = first_name + " " + last_name;
    if(member_array(name,SAVE_D->query_array(DN_AR)) != -1 
    || member_array(name,SAVE_D->query_array(MN_AR)) != -1 
    || member_array(name,SAVE_D->query_array(MNAU_AR)) != -1 
    || member_array(name,SAVE_D->query_array(DNAU_AR)) != -1) {
    return make_name(str,strtwo);
    }
    SAVE_D->set_value(strtwo,name);
    return SAVE_D->set_value(str,name);
}

void remove_name(string name) {
    if(member_array(name,SAVE_D->query_array(DN_AR)) != -1) {
        SAVE_D->remove_name_from_array(DN_AR,name);
        make_dead_name_list();
    }
    if(member_array(name,SAVE_D->query_array(MN_AR)) != -1) {
        SAVE_D->remove_name_from_array(MN_AR,name);
        make_missing_name_list();
    }
}

void add_name(string array, string arraytwo, string name) {
    if(member_array(name,SAVE_D->query_array(DN_AR)) != -1 
    || member_array(name,SAVE_D->query_array(MN_AR)) != -1 
    || member_array(name,SAVE_D->query_array(DNAU_AR)) != -1 
    || member_array(name,SAVE_D->query_array(MNAU_AR)) != -1) {
    return;
    }
    SAVE_D->set_value(arraytwo,name);
    return SAVE_D->set_value(array,name);
}

void clear_names(string array) {
    return SAVE_D->remove_array(array);
}
