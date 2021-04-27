#include <std.h>

mixed * arealist = ({});

//sort -t, -nk2
//DO NOT USE COMMA IN THE LIST BELOW, because it breaks sorting
arealist = ({
        ({"Offestry" ,1,6,}),
            ({"Ekibi Caverns (Ekibi Ridge)" ,6,10,}),
            ({"QUEST: Rosiden's Mission (Ebiki Caverns)" ,6,10,}),
            ({"Gobgob (Goblin Fortress)" ,6,10,}),
            ({"Darkwood Forest (Rhapsody)" ,8,10,}),
            ({"Dragon's Den Caverns" ,8,10,}),
            ({"QUEST: Stolen Pipe (Echoes Mountain or Dragon's Den Cavern)" ,8,10,}),
            ({"QUEST: Piaf's Dilemma (Koenig)" ,8,10,}),
            ({"Grasslands/Meadowlands" ,8,10,}),
            ({"Orc Cave (Koenig)" ,8,10,}),
            ({"Echoes Mountains" ,8,12,}),
            ({"Centaur Meadow (Yntala, Darkwood Side)" ,10,12,}),
            ({"QUEST: Riddle Quest (Koenig)" ,10,12,}),
            ({"QUEST: Muileann's Restless Soul (Muileann)" ,10,12,}),
            ({"Cryptkeeper's Lair (Muileann)" ,10,12,}),
            ({"Gentleman's Tower (Muileann)" ,10,12,}),
            ({"Gore's Hoarde" ,10,12,}),
            ({"Kildare Glen" ,10,12,}),
            ({"Muileann (Muileann)" ,10,12,}),
            ({"Piaf's Farm" ,10,12,}),
            ({"Pyramid (Yntala, Darkwood Side)" ,10,12,}),
            ({"Underwater Tunnels (Centaur Meadow)" ,10,12,}),
            ({"Yntala Forest (Tabor)" ,10,12,}),
            ({"Feyren Farm (West of Shadow)" ,10,15,}),
            ({"Nereid's Cove (Koenig)" ,10,15,}),
            ({"Dark Trail (East of Antioch)" ,12,15,}),
            ({"Deep Gnome Cavern (Charu Mountains)" ,12,15,}),
            ({"King's Forest (Slightly southwest of Antioch)" ,12,15,}),
            ({"Spider Nests" ,12,15,}),
            ({"Desert Sun Theatre (Azha)" ,15,20,}),
            ({"QUEST: The Mystery of the Desert Sun Theater (Azha)" ,15,20,}),
            ({"Antioch Ruins (East of Antioch)" ,15,20,}),
            ({"Dry Rum Cove (00 55)",15,20,}),
            ({"Githyanki Fortress (East of Shadow)" ,15,20,}),
            ({"QUEST: Isolate the Githyanki (East of Shadow)" ,15,20,}),
            ({"Purple Worm Lair (Southeast of Antioch)" ,15,20,}),
            ({"Shadowlord's Forest (Deku)",15,20,}),
            ({"Shadowlord's Fortress (Deku)",15,20,}),
            ({"Shadowlord's Graveyard (Deku)",15,20,}),
            ({"Tharis Forest" ,15,20,}),
            ({"The Vale" ,15,20,}),
            ({"The Dark Forest (Bordering The Vale)" ,18,25,}),
            ({"Altar of Fire (Deku)",20,25,}),
            ({"Amazon Forest (Dallyh)",20,25,}),
            ({"Archemond's Mansion (Near Lothwaite)" ,20,25,}),
            ({"QUEST: Sionne's final rest (Near Lothwaite)" ,20,25,}),
            ({"Barrier Mountains (South of Torm)" ,20,25,}),
            ({"Barrow Downs (Dagger Mountains)" ,20,25,}),
            ({"Dagger Marsh" ,20,25,}),
            ({"Drow Underdark (Dagger Mountains)" ,20,25,}),
            ({"QUEST: the Drow temple (Dagger Mountains)" ,20,25,}),
            ({"Firbolg Barrows (In Lothwaite)" ,20,25,}),
            ({"QUEST: The Spirit of Lothwaite (In Lothwaite)" ,20,25,}),
            ({"Gnoll Encampment (Laerad)",20,25,}),
            ({"God's Plains (Laerad)",20,25,}),
            ({"Lizardman Sewers (Laerad)",20,25,}),
            ({"Misty Grove" ,20,25,}),
            ({"Parnelli Forest (Laerad)",20,25,}),
            ({"Sanctuary Ruins (Deku)",20,25,}),
            ({"Sanctuary Sewers (Deku)",20,25,}),
            ({"Sanctuary Tower (Deku)",20,25,}),
            ({"Swamp of Death (Laerad)",20,25,}),
            ({"Wasteland (Laerad)",20,25,}),
            ({"Battlefield (Graez)",20,30,}),
            ({"BlackTongue's Keep (Deku)",20,30,}),
            ({"Coral Reef (Sea 08 62)",20,30,}),
            ({"Derro Tunnels (Dagger Mountains)" ,20,30,}),
            ({"QUEST: Friend of the Stones (Dagger Mountains)" ,20,30,}),
            ({"Graez City",20,30,}),
            ({"Marsh (Graez)",20,30,}),
            ({"Minotaur Maze (Graez)",20,30,}),
            ({"Mountains (Graez)",20,30,}),
            ({"Shadowlord's Mausoleum (Deku)",20,30,}),
            ({"Tonerra Monastery",20,35,}),
            ({"Dino Island (30 20)",25,30,}),
            ({"Dojo (Laerad)",25,30,}),
            ({"QUEST: The Drow Temple (Dagger Mountains)" ,25,30,}),
            ({"Ice Caves (Dagger Mountains)" ,25,30,}),
            ({"Laerad Caverns",25,30,}),
            ({"QUEST: Hansoth's demise",25,30,}),
            ({"Lower Aramanth Island",25,30,}),
            ({"Marsh of Fear" ,25,30,}),
            ({"Ogre Caverns (Dagger Mountains)" ,25,30,}),
            ({"QUEST: Sealing the Gate to the Hells (Dagger Mountains)" ,25,30,}),
            ({"Ovadexel Island (21 46)",25,30,}),
            ({"QUEST: Lucid Dreams (21 46)",25,30,}),
            ({"Plane of Fire" ,25,30,}),
            ({"Tonerra Jungle",25,30,}),
            ({"Tonerra Native Village",25,30,}),
            ({"Assassin Tunnels",30,35,}),
            ({"Attaya Jungle",30,35,}),
            ({"Black Stairway (Crystal Tower)",30,35,}),
            ({"Demongate" ,30,35,}),
            ({"Devil Tunnels",30,35,}),
            ({"Geonslu's Lair (Tonerra)",30,35,}),
            ({"Haunted House (Deku)",30,35,}),
            ({"Ice Island (30 16)",30,45,}),
            ({"Kinaro Underdark (Beneath Kinaro)" ,30,35,}),
            ({"Muln's Lair (Ice Island)" ,30,35,}),
            ({"Oubliette (Crystal Tower)",30,35,}),
            ({"Lava Tubes (Tonerra)",33,42,}),
            ({"QUEST: Shar's Failed Deed (Tonerra)",33,42,}),
            ({"Arkhon's Lair" ,35,40,}),
            ({"Atoyatl Jungle" ,35,50,}),
            ({"Forest on Argentrock Island",35,40,}),
            ({"Batlin's House (Argentrock)",35,50,}),
            ({"Crystal Tower",40,45 ,}),
            ({"Ibrandul's Temple (Tonerra)",40,45,}),
            ({"Shoreline on Argentrock Island",40,45,}),
            ({"Eldebaro Island (07 51)",40,50,}),
            ({"Klauth's Lair",40,50,}),
            ({"Dallyh Marsh (Dallyh)",45,50,}),
            ({"Mysterious Plateau (Aramanth)",45,50,}),
                });

mapping areas = ([]);
areas = ([
             "/d/shadow/city" : "Shadow",
             "/d/shadow/juran/city" : "Juran",
             "/d/dagger/nurval" : "Nurval",
             "/d/shadow/room/muuldaan/rooms/" : "Muul'daan",
             "/d/darkwood/tabor/room/" : "Tabor",
             "/d/azha/town/" : "Azha",
             "/d/darkwood/camps/rooms/town/" : "Synoria",
             "/d/tharis/newtharis/rooms" : "Tharis",
             "/d/antioch/antioch2/rooms" : "Antioch",
             "/d/dagger/tonovi/town" : "Tonovi",
             "/d/dagger/Torm/city" : "Torm",
             "/d/dagger/kinaro/" : "Kinaro",
             "/d/attaya/newseneca/rooms" : "Seneca",
             "/d/deku/town" : "Verbobone",
             "/d/undead/rooms/town" : "Graez",
             "/d/darkwood/room/rhapsody" : "the Rhapsody inn",
             "/d/dagger/exchange" : "the Exchange",
             "/d/player_houses/innaeli/rooms/bsb1" : "the Bloody Scourge inn",
             ]);


int cmd_rumors(string args)
{
    mixed * area;
    int lev = TP->query_base_character_level();
    int allflag = 0;
    int dispflag = 0;
    string color;

    {
        object *peeps, peep;
        string *places = ({}), *searchlist = ({}), fn;
        int i;

        peeps = users();
        if(!sizeof(peeps))
            tell_object(TP,"%^BOLD%^%^CYAN%^There are no rumors of adventurers passing through cities.%^RESET%^\n");
        else
        {
            searchlist = keys(areas);
            foreach(peep in peeps)
            {
                    
                if (peep == TP) {
                    continue;
                }

                if(!objectp(ENV(peep)))
                    continue;
                fn = base_name(environment(peep));
                for(i = 0;i < sizeof(searchlist); i++)
                {
                    if((strsrch(fn,searchlist[i]) != -1) &&
                       (member_array(areas[searchlist[i]],places) == -1))
                        places += ({ areas[searchlist[i]] });
                }
            }

            if(!sizeof(places))
                tell_object(TP,"%^BOLD%^%^CYAN%^There are no rumors of adventurers passing through cities.%^RESET%^\n");
            else
                tell_object(TP, "%^BOLD%^%^CYAN%^There are rumors of %^MAGENTA%^adventurers%^CYAN%^ recently passing through %^YELLOW%^"+implode(places,", ")+".%^RESET%^\n");
        }
    }


    if(args =="all")
        allflag = 1;
    write("%^BOLD%^The next areas might be appropriate to your level:");
    write("%^BOLD%^Levels Area");
    foreach(area in arealist)
    {
        dispflag = 0;
        if(lev >= area[1] && lev <= area[2])
        {
            dispflag = 1;
            color ="%^GREEN%^%^BOLD%^";
        }
        if(area[2] < lev)
            color ="%^ORANGE%^";

        if(area[1] > lev)
            color ="%^RED%^";

        if(allflag||dispflag)
            write("%^CYAN%^"+sprintf("%2d",area[1])+"-"+sprintf("%2d",area[2])+color+"  "+area[0]+"%^RESET%^");
    }


    return 1;
}

void help()
{
    write(
"%^CYAN%^NAME%^RESET%^

rumors - display areas appropriate to your level

%^CYAN%^SYNOPSIS%^RESET%^

rumors [all]

%^CYAN%^DESCRIPTION%^RESET%^

This command prints recommended areas list that fits withing your level range.

It will also display whether there any people in any cities you can roleplay with.

%^CYAN%^SEE ALSO%^RESET%^

gossip, background, score");


}
