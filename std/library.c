// library.c
//////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////
/// This is the code for the library inherit.  The inherit works   ///
/// with only a few lines of code changed to the base file for     ///
/// the full functionality of the library.  It includes the old    ///
/// research command made by Grendel to look up backgrounds for    ///
/// players.  Below is the list of all the necessary variables     ///
/// functions that must be set in order for the library to work.   ///
/// It's important to note that public and private libraries each  ///
/// behave differently.  Public libraries are just that, big       ///
/// libraries designed to be used by a lot of people.  Private     ///
/// libraries are more like a book shelf in a person's home.       ///
/// Created by -Ares 4/1/06                                        /// 
//////////////////////////////////////////////////////////////////////
/*////////////////////////////////////////////////////////////////////

  ** 1 sets the library public, 0 sets it private.
  set_public_library(int num);

  ** sets the deposit multiplier to num.  This number is multiplied
  ** by the character's level to determine what the deposit is for
  ** checking out a book
  set_deposit(int num);

  ** This is the most important part.  This sets the name of the 
  ** library, and that sets everything from the directory that the
  ** books save to and the name displayed in several of the lists
  ** DO NOT use any strange characters in the library name.  Use only 
  ** simple english words.  Don't use any periods or slashes or anything
  ** else besides UNDERSCORES and abc's.  A library must be made with this 
  ** name before it will work.  Go to an existing library and use the
  ** <make library> command, or use the library daemon to make one.
  ** IE make library The_Shadow_Public_Library
  set_library_name(string name);


  ** This function is designed to be overridden, that is no call to the 
  ** super.  This function will be called any time a player tries to use
  ** a private library when they are not on the allowed list.  It can 
  ** be anything from calling guards, to simply returning 1 and letting 
  ** the player have the book
  int not_allowed_func(object player);

  ** This function is designed to be overridden.  It gets called when a 
  ** player tries to use a public library when they're restricted from 
  ** doing so.
  int restricted_func(object player);
*/

#include <std.h>
#include <daemons.h>
#include <security.h>
#define AVA_D           "/daemon/avatar_d.c"
inherit CVAULT;

int FLAG, PublicLibrary, DepositMultiplier;
string LibraryName;

// used to display all the user interfaces with books, librarians, etc
int display_stuff(string str);
// to check out a book from a public library
void check_out_book(string str);
// returns a book that has been previously checked out
void return_book(string str);
// makes a new library, for wizards only
void make_library(string str);
// removes a librarian or a book, currently high mortal librarians can remove
// other librarians, and any librarian can remove a book
void remove_something(string str);
// used with input_to with remove_something so a prompt is necessary before 
// someone removes the only copy of a book from the library
void delete_book(string str,string *info);
// adds a new book to the library foregoing the review process.  This is for
// immortals and librarians only
void put_book_in_library(string str);
// this increments the book in question by 1, it also costs 2500 gold in fees
// for making a copy of said book
int stock_book(string str);
// this is for taking books from a private(non-public) library, since check out
// only works for public libraries.
int take_the_book(string str);
// this is used to return a book to a private library that had been previously
// taken.
int replace_the_book(string str);
// this is used by the original author of a book, or an immortal, to overwrite
// the save file of a book with a new copy.  Useful for adding chapters to 
// backgrounds, or more information, etc.
int update_the_book(string str);
// this submits a book for review for librarians or immortals to read and decide
// if they are of suitable content to be placed in the library for people to read
int submit_book(string str);
// used with input_to so the player can enter a seperate alias for themselves
// that they submit the book under.  Real name is tracked in the log to smite
// DMFS that want to abuse the system.
int submit_the_book(string str,object book,object player);
// used by imms or librarians to retrive a submitted book for review
int review_book(string str);
// if the reviewed book meets standards, then this will approve it and place it 
// on the shelves of the library
int approve_book(string str);
// if the books fails to meet standards, poorly written, etc, it can be denied
// and the author can pick it up to make revisions.
int deny_book(string str);
// this is used by the authors of denied books, so they can retrieve them to 
// make the necessary corrections
int retrieve_book(string str);
// this creates a copy of said book without taking it from the shelves, it can
// only be used by immortals
int spawn_book(string str);
// this restricts players from using public libraries, useful for people with
// bounties, etc.
int restrict_player(string str);
// unrestricts player from said library
int unrestrict_player(string str);
// this allows players to use private libraries, unlike public ones, the private
// libraries must allow anyone they want to have access, by default, they will not
int allow_player(string str);
// unallows players who were previously allowed
int unallow_player(string str);
// this bans players from using ANY library function, public or private.  This is
// OOC, and to be used for DMFS that cause problems
int ban_player(string str);
// unbans said DMF after rehibilitation :P
int unban_player(string str);
// this takes a string and returns the title and author, internal function
string *title_and_author(string str);
// used to set the deposit multiplier for checking out books.  This number
// is multiplied by the character's level to determine what it costs for
// them to check out the book.  If it's returned before the due date, they
// get back their deposit.
void set_deposit(int multiplier);
// sets the name of the library.  This *MUST* be a real library, else it will
// not work
void set_library_name(string name);
// sets if the library is public or not 1 for public, 0 for private.  The two
// libraries have vastly different behavior, see the header.
void set_public_library(int num);
// returns library name, internal function
string query_library_name();
// returns 1 if it's a public library, internal function
int query_public_library();
// returns the deposit multiplier, internal function
int query_deposit();
// returns 1 if the book exists, internal function
int book_exists(string title,string author);
// returns 1 if the player is a librarian, internal function
int is_librarian();
// returns 1 if the player is banned, internal function
int is_banned(object player);
// used to return a lowercase array, internal function
string lower_map(string str);
// used to sort an array alphabetically, interal function
string sort_alpha(string one, string two);
// returns 1 if the player is allowed, internal function
int is_allowed(object player);
// returns 1 if the player is restricted, internal function
int is_restricted(object player);
// returns 1 if the player is not allowed, internal function
int not_allowed_func(object player);
// returns 1 if the player is restricted, internal function
int restricted_func(object player);
// checks to see if the player is a valid object, and various other checks
// see header
int check_interactions(object player);
// backwards compatiable with the current libraries, so people can still 
// research backgrounds
int get_background(string str);
// internal functions
int not_public(object player,int num);
int not_private(object player,int num);
int not_librarian(object player,int num);
// returns the help file
int help(string str);

void create(){
    ::create();
    set_long("Towering oaken shelves reach the ceiling of this vast room, waiting to be"
        "filled with innumerable books. Clean tables dot the wide expanse of the "
        "floor, as do cushioned chairs where readers can comfortably sit. The sky "
        "blue carpeting softens the sounds of footsteps and is kept free of debris.  "
        "A large oaken desk is positioned near the double doors that open into the "
        "room. From here, visitors to the library can check books out to take along "
        "with them on their travels.");
    set_smell("default", "It smells clean and tidy.");
    set_listen("default", "It is silent, as a library should be.");
    set_deposit(1);
    set_library_name("Inherit");
    set_public_library(1);
    set_property("indoors",1);
    set_property("light",2);
    seteuid(UID_DAEMONSAVE);
}

void init(){
    ::init();
    add_action("display_stuff","list");
    add_action("check_out_book","check");
    add_action("return_book","return");
    add_action("make_library","make");
    add_action("remove_something","remove");
    add_action("put_book_in_library","put");
    add_action("stock_book","restock");
    add_action("take_the_book","take");
    add_action("replace_the_book","replace");
    add_action("update_the_book","update");
    add_action("submit_book","submit");
    add_action("review_book","review");
    add_action("approve_book","approve");
    add_action("deny_book","deny");
    add_action("retrieve_book","retrieve");
    add_action("spawn_book","spawn"); 
    add_action("restrict_player","restrict");
    add_action("unrestrict_player","unrestrict");
    add_action("allow_player","allow");
    add_action("unallow_player","unallow");
    add_action("ban_player","ban");
    add_action("unban_player","unban");
    add_action("get_background","research");
    add_action("get_help","help");
}

void reset(){
    object *people;
    int i;
    ::reset();
    if(!FLAG){
        if(base_name(TO) == LIBRARY){
            LIBRARY_D->clean_lists();
        }
        LIBRARY_D->restock_books(query_library_name());
        FLAG = 1;
    }
}

int display_stuff(string str){    
    string *array,holder;
    mapping tmp;    
    int i;

    if(!stringp(str)) { return 0; }

    switch(lower_case(str)){
    case "books":

        tmp = LIBRARY_D->get_books(query_library_name());
        if(!mapp(tmp)){ 
            tell_object(TP,"%^BOLD%^There are currently no books in the library.%^RESET%^");
            return 1; 
        }
        array = keys(tmp);
        array = sort_array(array,"sort_alpha",TO);
        write("\n%^BOLD%^%^BLUE%^ %^RESET%^%^BOLD%^Copies%^BOLD%^%^BLUE%^   %^RESET%^%^BOLD%^Author%^BOLD%^%^BLUE%^ =-=-=-=-=-=-=-=-= %^RESET%^%^BOLD%^Title%^BOLD%^%^BLUE%^ =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-%^RESET%^\n");
        for(i=0;i<sizeof(array);i++){
            holder = tmp[array[i]]["copies"];
            if((int)tmp[array[i]]["copies"] == 0 || (int)tmp[array[i]]["copies"] == "0"){
                holder = "0";
            }
            write("%^CYAN%^"+arrange_string(" ",3)+""+arrange_string(holder,7)+"%^RESET%^"+arrange_string(tmp[array[i]]["author alias"],25)+""+tmp[array[i]]["title"]+"%^RESET%^");
        }
        write("\n%^BOLD%^%^BLUE%^-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-%^RESET%^");
        break;

    case "librarians":

        if(!is_librarian()) { return not_librarian(TP,1); }
        tmp = LIBRARY_D->get_librarians(query_library_name());
        if(!mapp(tmp)){
            tell_object(TP,"%^BOLD%^There are currently no librarians for the library.%^RESET%^");            
            return 1; 
        }
        array = values(tmp);
        array = map_array(array,"lower_map",TO);
        array = sort_array(array,"sort_alpha",TO);
        holder = "Librarians for "+replace_string(capitalize(query_library_name()),"_"," ")+"";
        write("\n%^RESET%^%^BOLD%^"+holder+"\n");
        for(i=0;i<sizeof(array);i++){
            write("%^BOLD%^"+arrange_string(" ",3)+""+capitalize(array[i])+"");
        }
        i = strlen(holder);
        holder = arrange_string(" ",i);
        write("\n%^BOLD%^%^BLUE%^"+replace_string(holder," ","=")+"%^RESET%^");
        break;

    case "checked out":

        if(!query_public_library()) { return not_public(TP,1); }
        tmp = LIBRARY_D->get_checked_out(query_library_name());
        if(!mapp(tmp)){ 
            tell_object(TP,"%^BOLD%^There are currently no books checked out.%^RESET%^");
            return 1; 
        }
        array = keys(tmp);        
        write("\n%^BOLD%^%^BLUE%^- %^RESET%^%^BOLD%^Due Date%^BOLD%^%^BLUE%^ -=-=-=-=-=-=-=-=-=%^RESET%^%^BOLD%^ Title%^BOLD%^%^BLUE%^ -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-%^RESET%^\n"); 
        for(i=0;i<sizeof(array);i++){
            write("%^CYAN%^  "+arrange_string(ctime(tmp[array[i]]["due date"]),24)+"%^RESET%^    "+capitalize(tmp[array[i]]["title"]));
        }
        write("\n%^BOLD%^%^BLUE%^-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-%^RESET%^"); 
        break;

    case "submitted":

        if(!query_public_library()) { return not_public(TP,1); }
        tmp = LIBRARY_D->get_submitted(query_library_name());
        if(!mapp(tmp)){ 
            tell_object(TP,"%^BOLD%^There have been no books submitted for review.%^RESET%^");
            return 1; 
        }
        array = keys(tmp);
        write("%^BOLD%^%^BLUE%^-=-=- %^RESET%^BOLD%^Author%^BOLD%^%^BLUE%^ -=-=-=-=-=-=-=%^RESET%^%^BOLD%^ Title %^BOLD%^%^BLUE%^-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-%^RESET%^\n");
        for(i=0;i<sizeof(array);i++){
            write(" "+arrange_string(tmp[array[i]]["author alias"],25)+""+tmp[array[i]]["title"]+"");
            write("  %^BOLD%^Submitted By: %^RESET%^"+arrange_string(capitalize(tmp[array[i]]["player alias"]),20)+" %^BOLD%^On: %^CYAN%^"+tmp[array[i]]["date"]+"%^RESET%^\n");
        }
        write("%^BOLD%^%^BLUE%^-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-%^RESET%^");
        break;

    case "denied":

        if(!query_public_library()) { return not_public(TP,1); }
        tmp = LIBRARY_D->get_denied(query_library_name());
        if(!mapp(tmp)){ 
            tell_object(TP,"%^BOLD%^No books have been denied.%^RESET%^");
            return 1; 
        }
        array = keys(tmp);
        write("%^BOLD%^%^BLUE%^-=-=- %^RESET%^BOLD%^Author%^BOLD%^%^BLUE%^ -=-=-=-=-=-=-=%^RESET%^%^BOLD%^ Title %^BOLD%^%^BLUE%^-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-%^RESET%^\n");
        for(i=0;i<sizeof(array);i++){
            write(" "+arrange_string(tmp[array[i]]["author alias"],25)+""+tmp[array[i]]["title"]+"");
            write("  %^BOLD%^Submitted By: %^RESET%^"+arrange_string(capitalize(tmp[array[i]]["submitted by"]),20)+" %^BOLD%^On: %^CYAN%^"+tmp[array[i]]["date"]+"%^RESET%^\n");
        }
        write("%^BOLD%^%^BLUE%^-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-%^RESET%^");
        break;
        
    case "allowed":

        if(query_public_library()) { return not_private(TP,1); }
        tmp = LIBRARY_D->get_allowed(query_library_name());
        if(!mapp(tmp)){ 
            tell_object(TP,"%^BOLD%^There are currently no people allowed to use the library.%^RESET%^");
            return 1; 
        }
        array = values(tmp);
        array = map_array(array,"lower_map",TO);
        array = sort_array(array,"sort_alpha",TO);
        holder = "People allowed to use "+replace_string(capitalize(query_library_name()),"_"," ")+"";
        write("\n%^RESET%^%^BOLD%^"+holder+"\n");
        for(i=0;i<sizeof(array);i++){
            write("%^BOLD%^"+arrange_string(" ",3)+""+capitalize(array[i])+"");
        }
        i = strlen(holder);
        holder = arrange_string(" ",i);
        write("\n%^BOLD%^%^BLUE%^"+replace_string(holder," ","=")+"%^RESET%^");
        break;

    case "restricted":

        if(!query_public_library()) { return not_public(TP,1); }
        tmp = LIBRARY_D->get_restricted(query_library_name());
        if(!mapp(tmp)){ 
            tell_object(TP,"%^BOLD%^There are currently no people restricted from using the library.%^RESET%^");
            return 1; 
        }
        array = values(tmp);
        array = map_array(array,"lower_map",TO);
        array = sort_array(array,"sort_alpha",TO);
        holder = "People restricted from using "+replace_string(capitalize(query_library_name()),"_"," ")+"";
        write("\n%^RESET%^%^BOLD%^"+holder+"\n");
        for(i=0;i<sizeof(array);i++){
            write("%^BOLD%^"+arrange_string(" ",3)+""+capitalize(array[i])+"");
        }
        i = strlen(holder);
        holder = arrange_string(" ",i);
        write("\n%^BOLD%^%^BLUE%^"+replace_string(holder," ","=")+"%^RESET%^");
        break;

    case "banned":

        if(!avatarp(TP)) { return 1; }
        array = LIBRARY_D->get_banned();
        if(!pointerp(array)){ 
            tell_object(TP,"%^BOLD%^There are currently no players banned.%^RESET%^");
            return 1; 
        }
        array = map_array(array,"lower_map",TO);
        array = sort_array(array,"sort_alpha",TO);
        holder = "Players currently OOC banned from using libraries.";
        write("\n%^RESET%^%^BOLD%^"+holder+"\n");
        for(i=0;i<sizeof(array);i++){
            write("%^BOLD%^"+arrange_string(" ",3)+""+capitalize(array[i])+"");
        }
        i = strlen(holder);
        holder = arrange_string(" ",i);
        write("\n%^BOLD%^%^BLUE%^"+replace_string(holder," ","=")+"%^RESET%^");
        break;

    default :
        return 0;
    }
    return 1;
}


void check_out_book(string str){
    string title,author,info,*stuff;
    int deposit;

    if(!query_deposit())        { return 1; }
    if(!query_public_library()) { return not_public(TP,1); }
    if(!check_interactions(TP)) { return 1; }

    if(sscanf(str,"out %s",info) != 1) { return 0; }

    stuff = title_and_author(info);
    title = stuff[0];
    author = stuff[1];
    deposit = query_deposit();
    deposit = (int)TP->query_level() * deposit;

    LIBRARY_D->check_out_book(query_library_name(),title,author,TP,deposit);
    return 1;
}

void return_book(string str)
{
    string what;
    object book;
    int which;
    
    if(!stringp(str))           { tell_object(TP,"Return what?\n"); return 1; }
    if(!query_public_library()) { return not_public(TP,1); }

    if(sscanf(str,"book %d",which) == 1) {}
    else if(sscanf(str,"%s",what) == 1) {}

    if(!which) { book = present("book",TP); }
    else { book = present("book "+which,TP); }
    if(!objectp(book)) { tell_object(TP,"You don't have that.\n"); return 1; }

    LIBRARY_D->return_book_to_library(query_library_name(),book,TP);
    return 1;
}

void make_library(string str)
{
    string *info;
    if(!stringp(str)) { return 1; }
    info = explode(str," ");

    switch(info[0])
    {
    case "library":

        if(!wizardp(TP)) 
        { 
            tell_object(TP,"This command is for wizards only."); 
            return 1; 
        }
        if(sizeof(info) > 2)
        {
            tell_object(TP,"The library name must contain no spaces, "
                "use underscores instead.\n");
            return 1;
        }
        LIBRARY_D->make_library(info[1]);
        tell_object(TP,"Making library "+info[1]+".\n");
        return 1;

    case "librarian":

        if(!check_interactions(TP)) { return 1; }
        if(!is_librarian()) { return not_librarian(TP,1); }

        if((string)TP->query_position() == "high mortal" || avatarp(TP))
        {
            if(sizeof(info) != 3) 
            { 
                tell_object(TP,"%^BOLD%^Usage: make librarian name alias%^RESET%^\n");
                return 1; 
            }
            LIBRARY_D->make_librarian(query_library_name(),info[1],info[2],TP);
            tell_object(TP,"Making librarian "+info[1]+" with alias "+info[2]+".\n");
            return 1;
        }
        tell_object(TP,"You are not authorized to make another librarian.");
        return 1;

    default:
        return 0;
    }
    return 0;

}

void remove_something(string str)
{
    string *info;
    if(!stringp(str)) { return 1; }
    if(!check_interactions(TP)) { return 1; }
    info = explode(str," ");

    switch(info[0])
    {
    case "librarian":

        if(!is_librarian()) { return not_librarian(TP,1); }
        
        if((string)TP->query_position() != "high mortal" && !avatarp(TP))
        {
            tell_object(TP,"You are not authorized to remove a librarian.");
            return 1;
        }
        LIBRARY_D->remove_librarian(query_library_name(),info[1],TP);
        tell_object(TP,"Removing "+info[1]+" from "+query_library_name()+"'s "
            "list of librarians.\n");
        return 1;

    case "book":

        if(!is_librarian()) 
        {
            tell_object(TP,"You must be a librarian to remove a book from "
                "the library.");
            return 1;
        }
        info -= ({ info[0] });
        info = title_and_author(implode(info," "));
        if(sizeof(info) != 2 || info[0] == "" || info [1] == "") 
        { 
            tell_object(TP,"%^BOLD%^Usage: %^CYAN%^<remove book>%^RESET%^%^BOLD%^ "
                "A Fool's Errand by Spiffy McQuick%^RESET%^\n");
            return 1; 
        }
        write("Are you sure you want to completely remove "+info[0]+" by "
            ""+info[1]+" from the library?");
        write("Enter <yes> to confirm, <no> or <**> to abort");
        input_to("delete_book",info);
        return 1;

    default:
        return 0;
    }
    return 0;
}

void delete_book(string str,string *info)
{
    if(!stringp(str))           { return 1; }
    if(!pointerp(info))         { return 1; }
    if(str == "no" || str == "**")
    {
        tell_object(TP,"Aborting...\n");
        return 1;
    }

    if(LIBRARY_D->remove_book_from_library(query_library_name(),info[0],info[1],TP))
    {
        tell_object(TP,"You have removed the only copy of "+info[0]+" by "+info[1]+" "
            "from the library, it is now in your inventory.\n");
        return 1;
    }
    tell_object(TP,"That book is not in the library, be sure to check spelling.");
    return 1;
}

void put_book_in_library(string str)
{
    string name,title,what,*tmp;
    object book;
    int which;

    if(!stringp(str))           { return 1; }
    if(!check_interactions(TP)) { return 1; }
    if(!is_librarian()){
       if(sscanf(str,"book %d in library",which) != 1){
           return 0;
        }else if(sscanf(str,"%s in library",what) == 1){
           return 0;
        }else{
           tell_object(TP,"You are not authorized to add books to this "
               "library.\n");
           return 1;
        }
    }

    if(sscanf(str,"book %d in library",which) == 1) {}
    else if(sscanf(str,"%s in library",what) == 1) {}
    else { return 0; }

    if(which) { book = present("book "+which+"",TP); }
    else { book = present("book",TP); }
    if(!objectp(book)) { tell_object(TP,"You don't have that."); return 1; }
    if(base_name(book) != "/d/common/obj/misc/book") { return 0; }

    name = (string)book->query_author_alias();
    if(!stringp(name) || name == "") { tell_object(TP,"That book has no author set."); return 1; }
    title = (string)book->query_book_title();
    if(!stringp(title) || title == "") { tell_object(TP,"That book has no title set."); return 1; }

    if(LIBRARY_D->put_book_in_library(query_library_name(),book,TP))
    {
        tell_object(TP,"You add the book "+title+" by "+name+" in the library.\n");
    }
    else { tell_object(TP,"That book is either already in the library, or the wrong type."); }
    return 1;
}

int stock_book(string str)
{
    string *info;
    int books;
    if(!stringp(str))           { return 1; }
    if(!is_librarian())         { return not_librarian(TP,1); }
    if(!check_interactions(TP)) { return 1; }
    info = explode(str," ");
    if(info[0] != "book") 
    { 
        tell_object(TP,"%^BOLD%^Usage: %^CYAN%^<restock book>%^RESET%^%^BOLD%^ "
            "A Fool's Errand by Spiffy McQuick\n%^RESET%^"); 
        return 1;
    }
    info -= ({ info[0] });
    info = title_and_author(implode(info," "));
    if(!book_exists(info[0],info[1]))
    {
        tell_object(TP,"The book "+info[0]+" by "+info[1]+" is not "
            "in "+query_library_name()+" to restock.");
        return 1;
    }
    if(!TP->query_funds("gold",2500))
    {
        tell_object(TP,"You cannot afford the 2500 gold cost to restock the book.");
        return 1;
    }
    books = LIBRARY_D->add_book(query_library_name(),info[0],info[1],1);
    TP->use_funds("gold",2500);
    tell_object(TP,"You restock "+info[0]+" by "+info[1]+" for 2500 gold coins.");
    return 1;
}

int take_the_book(string str)
{
    string title,author,info,*tmp;
    if(!stringp(str))                   { return 0; }
    tmp = explode(str," ");
    if(lower_case(tmp[0]) != "book")    { return 0; }
    if(!check_interactions(TP))         { return 1; }
    if(query_public_library())          { return not_private(TP,1); }
    tmp -= ({ tmp[0] });
    info = implode(tmp," ");
    tmp = title_and_author(info);
    title = tmp[0];
    author = tmp[1];    

    if(!book_exists(title,author))
    {
        tell_object(TP,"The book "+title+" by "+author+" is not in the library.\n");
        return 1;
    }
    LIBRARY_D->take_book(query_library_name(),title,author,TP);
    tell_object(TP,"You take the book "+title+" by "+author+" from the library.\n");
    return 1;
}

int replace_the_book(string str)
{
    string what;
    object book;
    int which;

    if(!stringp(str))           { return 1; }
    if(!check_interactions(TP)) { return 1; }
    if(query_public_library())  { return not_private(TP,1); }

    if(sscanf(str,"book %d",which) == 1) {}
    else if(sscanf(str,"%s",what) == 1) {}

    if(!which) { book = present("book",TP); }
    else { book = present("book "+which,TP); }
    if(!objectp(book)) { tell_object(TP,"You don't have that.\n"); return 1; }

    tell_object(TP,"You put "+book->query_book_title()+" by "+book->query_author_alias()+" back "
        "in the library.");
    LIBRARY_D->replace_book(query_library_name(),book,TP);
    return 1;
}

int update_the_book(string str)
{
    string what;
    object book;
    int which;

    if(!stringp(str))           { return 0; }
    if(!check_interactions(TP)) { return 1; }

    if(sscanf(str,"book %d",which) == 1) {}
    else if(sscanf(str,"%s",what) == 1) { if(lower_case(what) != "book") return 0; }

    if(!which) { book = present("book",TP); }
    else { book = present("book "+which,TP); }
    if(!objectp(book)) { tell_object(TP,"You don't have that.\n"); return 1; }
    
    if(!avatarp(TP) && (string)book->query_author_name() != (string)TP->query_true_name())
    {
        tell_object(TP,"Only the original author of the book can update it.");
        return 1;
    }
    if(LIBRARY_D->update_book(query_library_name(),book,TP))
    {
        tell_object(TP,"You update the book.");
        return 1;
    }
    return 1;
}

int submit_book(string str)
{
    string what;
    object book;
    int which;

    if(!stringp(str))           { return 0; }
    if(!check_interactions(TP)) { return 1; }
    if(!query_public_library()) { return not_public(TP,1); }
    if(sscanf(str,"book %d",which) == 1) {}
    else if(sscanf(str,"%s",what) == 1) 
    { 
        if(lower_case(what) != "book") { return 0; } 
    }
    if(!which) { book = present("book",TP); }
    else { book = present("book "+which,TP); }
    if(!objectp(book)) { tell_object(TP,"You don't have that.\n"); return 1; }

    write("Please enter the alias you wish to submit your entry under.  "
        "This is the name the librarians will see when they review the book, "
        "it is seperate from the author alias used on the book itself.  This "
        "should be a name you are known as IC.");
    write("Enter <none> or <**> to abort.");
    input_to("submit_the_book",book,TP);
    return 1;
}

int submit_the_book(string str,object book,object player)
{
    string name, title;
    if(!stringp(str))           { return 1; }
    if(!objectp(book))          { return 1; }
    if(!interactive(player))    { return 1; }
    if(!query_public_library()) { return not_public(TP,1); }

    name = (string)book->query_author_alias();
    if(!stringp(name) || name == "") { tell_object(player,"That book has no author set."); return 1; }
    title = (string)book->query_book_title();
    if(!stringp(title) || title == "") { tell_object(player,"That book has no title set."); return 1; }

    tell_object(player,"Your book "+title+" by "+name+" has been submitted "
        "to "+query_library_name()+" for review.  Please check back in a "
        "few days to see if it has been accepted or not.");
    LIBRARY_D->submit_book_to_library(query_library_name(),str,book,player);
    return 1;
}

int review_book(string str)
{
    string title,author,info,*stuff;
    if(!stringp(str))                   { return 0; }
    if(sscanf(str,"book %s",info) != 1) { return 0; }
    if(!check_interactions(TP))         { return 1; }
    if(!query_public_library())         { return not_public(TP,1); }
    if(!is_librarian() && !avatarp(TP)) { return not_librarian(TP,1); }
    stuff = title_and_author(info);
    title = stuff[0];
    author = stuff[1];
    LIBRARY_D->review_book(query_library_name(),title,author,TP);
    return 1;
}

int approve_book(string str)
{
    string what;
    object book;
    int which;

    if(!stringp(str))           { return 1; }
    if(!check_interactions(TP)) { return 1; }
    if(!query_public_library()) { return not_public(TP,1); }
    if(!is_librarian() && !avatarp(TP)) { return not_librarian(TP,1); }

    if(sscanf(str,"book %d",which) == 1) {}
    else if(sscanf(str,"%s",what) == 1) {}

    if(!which) { book = present("book",TP); }
    else { book = present("book "+which,TP); }
    if(!objectp(book)) { tell_object(TP,"You don't have that.\n"); return 1; }

    if(LIBRARY_D->approve_book(query_library_name(),book,TP))
    {
        tell_object(TP,"You have approved the book for the library, "
            "it will now be available on the shelves.\n");
        return 1;
    }
    return 1;
}

int deny_book(string str)
{
    string what;
    object book;
    int which;

    if(!stringp(str))           { return 1; }
    if(!check_interactions(TP)) { return 1; }
    if(!query_public_library()) { return not_public(TP,1); }
    if(!is_librarian() && !avatarp(TP)) { return not_librarian(TP,1); }

    if(sscanf(str,"book %d",which) == 1) {}
    else if(sscanf(str,"%s",what) == 1) {}

    if(!which) { book = present("book",TP); }
    else { book = present("book "+which,TP); }
    if(!objectp(book)) { tell_object(TP,"You don't have that.\n"); return 1; }

    if(LIBRARY_D->deny_book(query_library_name(),book,TP))
    {
        tell_object(TP,"You have denied the book.  It will be left "
            "in the denied book shelf until the author recovers it.");
        return 1;
    }
    return 1;
}

int retrieve_book(string str)
{
    string title,author,info,*tmp;
    if(!check_interactions(TP))      { return 1; }
    if(!stringp(str))                { return 1; }
    if(!query_public_library())      { return not_public(TP,1); }
    tmp = explode(str," ");
    if(lower_case(tmp[0]) != "book") 
    { 
        tell_object(TP,"%^BOLD%^Usage: %^CYAN%^<retrieve book>%^RESET%^%^BOLD%^ "
            "A Fool's Errand by Spiffy McQuick\n%^RESET%^");
        return 1; 
    }
    tmp -= ({ tmp[0] });
    info = implode(tmp," ");
    tmp = title_and_author(info);
    title = tmp[0];
    author = tmp[1];
    if(LIBRARY_D->retrieve_book(query_library_name(),title,author,TP))
    {
        tell_object(TP,"You retrieve your book.  Talk to the librarian to "
            "find out what changes are necessary before it is approved.\n");
        return 1;
    }
    return 1;
}

int spawn_book(string str)
{
    string title,author,info,*tmp;
    if(!avatarp(TP))                 { return 1; }
    tmp = explode(str," ");
    if(lower_case(tmp[0]) != "book") 
    { 
        tell_object(TP,"Usage: %^CYAN%^<spawn book>%^RESET%^%^BOLD%^ "
            "A Fool's Errand by Spiffy McQuick.\n");
        return 1; 
    }
    tmp -= ({ tmp[0] });
    info = implode(tmp," ");
    tmp = title_and_author(info);
    title = tmp[0];
    author = tmp[1];
    LIBRARY_D->spawn_book(query_library_name(),title,author,TP);
    tell_object(TP,"Spawning...\n");
    return 1;
}

int restrict_player(string str)
{
    string real_name,*names;
    mapping restricted;
    if(is_banned(TP))           { return 1; }
    if(!objectp(TP))            { return 1; }
    if(!is_librarian())         { return not_librarian(TP,1); }
    if(!stringp(str))           { return 1; }
    if(!query_public_library()) { return not_public(TP,1); }
    
    restricted = LIBRARY_D->get_restricted(query_library_name());
    names = keys(restricted);
    real_name = LIBRARY_D->get_real_name(str,TP);
    if(!real_name || real_name == "") { tell_object(TP,"Restrict who?\n"); return 1; }
    
    LIBRARY_D->restrict_player_from_library(query_library_name(),str,TP);
    tell_object(TP,""+str+" has been restricted from "+query_library_name()+".\n");
    return 1;
}

int unrestrict_player(string str)
{
    string real_name,*names;
    mapping restricted;
    if(is_banned(TP))           { return 1; }
    if(!objectp(TP))            { return 1; }
    if(!is_librarian())         { return not_librarian(TP,1); }
    if(!stringp(str))           { tell_object(TP,"Unrestrict who?\n"); return 1; }
    if(!query_public_library()) { return not_public(TP,1); }
    
    restricted = LIBRARY_D->get_restricted(query_library_name());
    names = keys(restricted);
    real_name = LIBRARY_D->get_real_name(str,TP);
    if(!real_name || real_name == "") { return 1; }
    if(member_array(real_name,names) == -1)
    {
        tell_object(TP,""+str+" is not restricted from "+query_library_name()+".\n");
        return 1;
    }
    
    LIBRARY_D->unrestrict_player_from_library(query_library_name(),str,TP);
    tell_object(TP,""+str+" has been unrestricted from "+query_library_name()+".\n");
    return 1;
}

int allow_player(string str)
{
    string real_name,*names;
    mapping allowed;
    if(is_banned(TP))           { return 1; }
    if(!objectp(TP))            { return 1; }
    if(!stringp(str))           { return 1; }
    if(!is_librarian())         { return not_librarian(TP,1); }
    if(query_public_library())  { return not_private(TP,1); }

    allowed = LIBRARY_D->get_allowed(query_library_name());
    names = keys(allowed);
    real_name = LIBRARY_D->get_real_name(str,TP);
    if(!real_name || real_name == "") { tell_object(TP,"Allow who?\n"); return 1; }
    
    LIBRARY_D->allow_player_for_library(query_library_name(),str,TP);
    tell_object(TP,""+str+" has been allowed to "+query_library_name()+".\n");
    return 1;
}

int unallow_player(string str)
{
    string real_name,*names;
    mapping allowed;
    if(is_banned(TP))           { return 1; }
    if(!objectp(TP))            { return 1; }
    if(!stringp(str))           { return 1; }
    if(!is_librarian())         { return not_librarian(TP,1); }
    if(query_public_library())  { return not_private(TP,1); }

    allowed = LIBRARY_D->get_allowed(query_library_name());
    names = keys(allowed);
    real_name = LIBRARY_D->get_real_name(str,TP);
    if(!real_name || real_name == "") { tell_object(TP,"Unallow who?\n"); return 1; }
    if(member_array(real_name,names) == -1)
    {
        tell_object(TP,""+str+" is not allowed for "+query_library_name()+".\n");
        return 1;
    }
    
    LIBRARY_D->unallow_player_for_library(query_library_name(),str,TP);
    tell_object(TP,""+str+" has been unallowed from "+query_library_name()+".\n");
    return 1;
}

int ban_player(string str)
{
    if(!objectp(TP)) { return 1; }
    if(!stringp(str)) { return 1; }
    if(!avatarp(TP)) { return 1; }

    LIBRARY_D->ban_player_from_libraries(str,TP);
    tell_object(TP,"Banning player "+str+" from all libraries.  This is "
        "an OOC action that prevents use of ALL libraries.  If you meant "
        "this IC, see restrict, or unallow.  <unban player> can remove "
        "the ban.");
    return 1;
}

int unban_player(string str)
{
    string *names;
    if(!objectp(TP)) { return 1; }
    if(!stringp(str)) { return 1; }
    if(!avatarp(TP)) { return 1; }
    
    names = LIBRARY_D->get_banned();
    if(member_array(str,names) == -1)
    {
        tell_object(TP,""+str+" isn't banned.\n");
        return 1;
    }
    LIBRARY_D->unban_player_from_libraries(str,TP);
    tell_object(TP,"Unbanning "+str+".\n");
    return 1;
}

// seperates the 'by' out of a string and returns the title and author
// useful if there is more than one 'by' in the title, it only removes
// the last instance of 'by'
string *title_and_author(string str)
{
    int i,j=0;
    string author,title,*tmp,*author_arr=({}),*title_arr=({});
    if(!stringp(str)) { return 0; }
    tmp = explode(str," ");
    i = sizeof(tmp);
    while(i)
    {
        i--;
        if(tmp[i] == "by" && !j) { j = 1; continue; }
        if(!j)
        {            
            author_arr += ({ tmp[i] }); continue;
        }
        title_arr += ({ tmp[i] });        
    }
    tmp = author_arr;
    author_arr = ({});
    i = sizeof(tmp);
    while(i)
    {
        i--;
        author_arr += ({ tmp[i] });
    }
    tmp = title_arr;
    title_arr = ({});
    i = sizeof(tmp);
    while(i)
    {
        i--;
        title_arr += ({ tmp[i] });
    }
    author = implode(author_arr," ");
    title  = implode(title_arr, " ");
    return ({ title, author });
}

void set_deposit(int multiplier)
{
    if(!intp(multiplier)) { return; }
    DepositMultiplier = multiplier;
    return;
}

void set_library_name(string name)
{
    if(!stringp(name)) { return; }
    LibraryName = name;
    return;
}

void set_public_library(int num)
{
    if(!intp(num)) { return; }
    PublicLibrary = num;
    return;
}

string query_library_name()
{
    if(LibraryName) { return LibraryName; }
    return 0;
}

int query_public_library()
{
    if(PublicLibrary) { return 1; }
    return 0;
}

int query_deposit()
{
    if(DepositMultiplier) { return DepositMultiplier; }
    return 0;
}

int book_exists(string title,string author)
{
    if(LIBRARY_D->book_file_exists(query_library_name(),title,author)) { return 1; }
    return 0;
}

int is_librarian()
{
    if(!LIBRARY_D->check_librarian(query_library_name(),TP)) { return 0; }
    return 1;
}

int is_banned(object player)
{
    if(avatarp(TP)) { return 0; }
    if(member_array(player->query_true_name(),LIBRARY_D->get_banned()) != -1) { return 1; }
    return 0;
}

string lower_map(string str) { return lower_case(str); }

string sort_alpha(string one, string two) {
    return FILTERS_D->alphabetical_sort(one,two);
}

int is_allowed(object player)
{
    mapping allowed;
    string *names;
    allowed = LIBRARY_D->get_allowed(query_library_name());
    if(!mapp(allowed)) { return 0; }
    names = keys(allowed);
    if(!pointerp(names)) { return 0; }
    if(member_array(player->query_true_name(),names) != -1) { return 1; }
    return 0;
}

int is_restricted(object player)
{
    mapping restricted;
    string *names;
    restricted = LIBRARY_D->get_restricted(query_library_name());
    if(!mapp(restricted)) { return 0; }
    names = keys(restricted);
    if(!pointerp(names)) { return 0; }
    if(member_array(player->query_true_name(),names) != -1) { return 1; }
    return 0;
}

int not_allowed_func(object player)
{
    tell_object(player,"You are not allowed to use this library.");
    return 0;
}

int restricted_func(object player)
{
    tell_object(player,"You are restricted from using this library.");
    return 0;
}

int check_interactions(object player)
{
    if(!objectp(player))        { return 0; }
    if(!interactive(player))    { return 0; }
    if(avatarp(player))         { return 1; }
    if(is_banned(player))       
    { 
        tell_object(player, "You are banned from using libraries, "
            "contact an immortal to learn why.\n");
        return 0; 
    }
    if(is_librarian())          { return 1; }  
    if(!query_public_library())
    {
        if(!is_allowed(player)) { return not_allowed_func(player); }
        return 1;
    }
    if(is_restricted(player))   { return restricted_func(player); }    
    return 1;
}

int get_background(string str)
{
    string bkgrnd, avat,name;
    int isava, ispl;
    if(!objectp(TP))            { return 1; }
    if(!query_public_library()) { return 1; }
    if(!str) 
    { 
        tell_object(TP, "%^BOLD%^Whose background do you want to research?%^RESET%^\n");
        return 1;
    }
    str=lower_case(str);
    if(!avatarp(TP)) 
    {
        name = TP->realName(str);
        if(!stringp(name) || name == "") name = str;
        str = name;
    }
    if(user_exists(str))                { ispl = 1; }   
    if(!ispl && AVA_D->is_persona(str)) {  isava = 1; }
    if(!ispl && !isava) { return notify_fail("That person does not exist in this reality.\n"); }
    if(ispl)
    {
        if(!file_exists("/d/save/background/"+str+".txt"))
        {
            tell_object(TP, "%^BOLD%^That person does not have a background on record yet.");
            return 1;
        }
        tell_object(TP, "%^BOLD%^You wander off and quickly find the scroll containing the background.");
        TP->force_me("pose sitting in a chair reading one of the library's scrolls.");
        bkgrnd = read_file("/d/save/background/"+str+".txt",6);
        TP->more(explode(bkgrnd,"\n"));
        return 1;
    }
    if(isava)
    {
        avat = ((string *)AVA_D->query_avatar_of_persona(str))[0];
        if(!file_exists("/avatar/"+avat+"/"+str+".txt"))
        {
            tell_object(TP, "%^BOLD%^That person does not have a background on record yet.");
            return 1;
        }
        tell_object(TP, "%^BOLD%^You wander off and quickly find the scroll containing the background.");
        TP->force_me("pose sitting in a chair reading one of the library's scrolls.");
        write("%^BOLD%^"+capitalize(str)+"'s Background Information%^RESET%^\n");
        bkgrnd = read_file("/avatar/"+avat+"/"+str+".txt",6);
        TP->more(explode(bkgrnd,"\n"));
        return 1;
    }
    return notify_fail("Error, contact a wiz.\n");
}

int not_public(object player,int num)
{
    tell_object(player,"%^BOLD%^You can only do this at a public library.%^RESET%^\n");
    return num;
}

int not_private(object player,int num)
{
    tell_object(player,"%^BOLD%^You can only do this in a private library.%^RESET%^\n");
    return num;
}

int not_librarian(object player,int num)
{
    tell_object(player,"%^BOLD%^You can only do this if you are a librarian here.%^RESET%^\n");
    return num;
}

int get_help(string str)
{
    if(!objectp(TP))    { return 0; }
    if(!str)
    {
        tell_object(TP,"Did you mean <help library>?\n");
        return 1;
    }

    switch(lower_case(str))
    {
    case "library":

        write("   Libraries are places where books can be stored and viewed later.  "
              "Much like real libraries, they come in all shapes and sizes.  Some "
              "are very large and contain thousands of tomes, and some are simple "
              "small book shelves that private citizens keep in their homes.  The "
              "libraries on Shadowgate reflect these two contrasting ideas in that "
              "public libraries and private libraries act very differently.  Some "
              "commands that are available in public libraries will not be available "
              "in private libraries and vice versa.  Following is a list of functions "
              "that are available in both public and private libraries.  Type help "
              "<topic name> for a more detailed explanation of each topic.");
        if(is_librarian())
        {
            write("    %^BOLD%^Additional information for librarians:%^RESET%^\n"
                  "In addition to having more commands pertaining to the operation of "
                  "the library itself, you are responsible for any questionable "
                  "information that you add to the library.  Every book that is added "
                  "to the library is logged by time and date and the person who added "
                  "it.  Please be careful not to allow quest like information to be "
                  "accidentally or intentionally added to library books.");
        }
        write("  %^ORANGE%^<list books>%^RESET%^%^%^ORANGE%^%^ULINE%^RESET%^RESET%^%^");
        write("  %^ORANGE%^<update book>%^RESET%^%^%^ORANGE%^%^ULINE%^RESET%^RESET%^%^");
        write("  %^ORANGE%^<research>%^RESET%^%^%^ORANGE%^%^ULINE%^RESET%^RESET%^%^");
        if(is_librarian())
        {   
            write("
\t%^CYAN%^Librarian only commands...%^RESET%^");
            write(
"
  %^ORANGE%^<list librarians>%^RESET%^
  %^ORANGE%^<remove %^ORANGE%^%^ULINE%^BOOK_TITLE%^RESET%^%^ORANGE%^ by %^ORANGE%^%^ULINE%^AUTHOR%^RESET%^%^ORANGE%^>%^RESET%^
  %^ORANGE%^<remove librarian>%^RESET%^
  %^ORANGE%^<put %^ORANGE%^%^ULINE%^BOOK%^RESET%^%^ORANGE%^ in library>%^RESET%^
  %^ORANGE%^<restock %^ORANGE%^%^ULINE%^BOOK_TITLE%^RESET%^%^ORANGE%^ by %^ORANGE%^%^ULINE%^AUTHOR%^RESET%^%^ORANGE%^>%^RESET%^
  %^ORANGE%^<make librarian>%^RESET%^
");
        }
        if(avatarp(TP))
        {
            write("\t%^MAGENTA%^Avatar only commands...%^RESET%^");
            write(
"
  %^ORANGE%^<ban %^ORANGE%^%^ULINE%^NAME%^RESET%^%^ORANGE%^>%^RESET%^
  %^ORANGE%^<unban %^ORANGE%^%^ULINE%^NAME%^RESET%^%^ORANGE%^>%^RESET%^
  %^ORANGE%^<spawn %^ORANGE%^%^ULINE%^BOOK_TITLE%^RESET%^%^ORANGE%^ by %^ORANGE%^%^ULINE%^AUTHOR%^RESET%^%^ORANGE%^>%^RESET%^
  %^ORANGE%^<list banned>%^RESET%^
");
        }
        if(wizardp(TP))
        {
            write("\t%^RED%^Wizard only commands...%^RESET%^");
            write("  %^ORANGE%^<make library>%^RESET%^");
        }
        write("\n%^RED%^Important:  %^CYAN%^See also <help public library> and "
            "<help private library> for commands specific to each.%^RESET%^");
        break;

    case "public library":

      write(
"
Public libraries are those larger libraries who have a library staff and many volumes which can be checked out by the public. There are both small and large public libraries, but on Shadowgate all public libraries have the same functions. Type help <topic name> for a more detailed explanation of each topic.
  %^ORANGE%^<check out %^ORANGE%^%^ULINE%^BOOK_TITLE%^RESET%^ by %^ORANGE%^%^ULINE%^AUTHOR%^RESET%^>%^RESET%^
  %^ORANGE%^<return %^ORANGE%^%^ULINE%^BOOK%^RESET%^>%^RESET%^
  %^ORANGE%^<submit %^ORANGE%^%^ULINE%^BOOK%^RESET%^>%^RESET%^
  %^ORANGE%^<retrieve %^ORANGE%^%^ULINE%^BOOK_TITLE%^RESET%^ by %^ORANGE%^%^ULINE%^AUTHOR%^RESET%^>%^RESET%^
  %^ORANGE%^<list checked out>%^RESET%^
  %^ORANGE%^<list submitted>%^RESET%^
  %^ORANGE%^<list denied>%^RESET%^
  %^ORANGE%^<list restricted>%^RESET%^
");
        if(is_librarian())
        {
            write("\t%^CYAN%^Librarian only commands...%^RESET%^");
            write(
"
  %^ORANGE%^<review %^ORANGE%^%^ULINE%^BOOK_TITLE%^RESET%^%^ORANGE%^ by %^ORANGE%^%^ULINE%^AUTHOR%^RESET%^%^ORANGE%^>%^RESET%^
  %^ORANGE%^<approve %^ORANGE%^%^ULINE%^BOOK_TITLE%^RESET%^%^ORANGE%^ by %^ORANGE%^%^ULINE%^AUTHOR%^RESET%^%^ORANGE%^>%^RESET%^
  %^ORANGE%^<deny %^ORANGE%^%^ULINE%^BOOK_TITLE%^RESET%^%^ORANGE%^ by %^ORANGE%^%^ULINE%^AUTHOR%^RESET%^%^ORANGE%^>%^RESET%^
  %^ORANGE%^<restrict %^ORANGE%^%^ULINE%^NAME%^RESET%^%^ORANGE%^>%^RESET%^
  %^ORANGE%^<unrestrict %^ORANGE%^%^ULINE%^NAME%^RESET%^%^ORANGE%^>%^RESET%^
");              
        }
        break;

    case "private library":

        write("    Private libraries can be anything from the expansive "
              "personal collection possessed by an arch-mage to the few books "
              "that an individual might keep on a small shelf at the side of their "
              "favorite chair.  They are not always staffed so well as public "
              "libraries, and in Shadowgate they all have the same functions "
              "which are different from those of public libraries.  Type help "
              "<topic name> for a more detailed explanation of each topic.");
        write("\t%^BOLD%^<list allowed>%^RESET%^");
        write("\t%^BOLD%^<take book title by author>%^RESET%^");
        write("\t%^BOLD%^<replace book>%^RESET%^");
        if(is_librarian())
        {
            write("\t%^CYAN%^Librarian only commands...%^RESET%^");
            write("\t%^BOLD%^<allow player>%^RESET%^");
            write("\t%^BOLD%^<unallow player>%^RESET%^");
        }
        break;

    case "list books":

        write("\n\tUsage: list books\n");
        write("<list books> will return a list of all the books currently "
            "in the library.  It returns three columns of information.  The "
            "first column is how many copies of that particular book are "
            "currently on the library shelves.  The second column lists "
            "the alias of the author who wrote the book and the third column "
            "lists the book's title.  <list books> works in both public and "
            "private libraries.");
        break;

    case "update book":

        write("\n\tUsage: update book, update book 2\n");
        write("<update book> is the command that the original author "
            "should use to update the content of one of their books.  "
            "This command will update the original copy of the book "
            "to the new one.  <book> must be a book in your inventory "
            "that is also in the library.  <update book> works in both "
            "public and private libraries.");

        break;

    case "research":

        write("\n\tUsage: research jeff, research jen\n");
        write("<research> is the command to read backgrounds.  It will "
            "display the background of the player listed if you have "
            "that player recognized and the player has a background on "
            "file.  <research> only works in public libraries.");
        break;

    case "list librarians":

        write("\n\tUsage: list librarians\n");
        write("<list librarians> returns an alphabetical list of the "
            "librarians for the library.  This list is of the aliases "
            "that they were added by when they were made into a librarian.  "
            "It may or may not be the name you have them recognized as.  "
            "Only librarians for the library can see this information, "
            "and is it available at both public and private libraries.");
        break;

    case "remove book":

        write("\n\tUsage: remove book A Fool's Errand by Spiffy McQuick\n");
        write("<remove book> is the command used to delete a book from the "
            "library.  It will remove the last copy of the selected book and "
            "place it in your inventory.  This command is available only to "
            "librarians and works in both public and private libraries.  "
            "Capitalization and spelling are important.  The author and "
            "title must be EXACT before the book can be removed.");
        break;

    case "remove librarian":

        write("\n\tUsage: remove librarian Fred\n");
        write("<remove librarian> is used to remove a librarian "
            "from the list of approved librarians for the library.  "
            "This should only be used in appropriate IC instances and "
            "generally only with immortal approval in public libraries.  "
            "This command is available only to librarians and works in "
            "both public and private libraries.");
        break;

    case "put book in library":

        write("\n\tUsage: put book in library, put book 2 in library\n");
        write("<put book in library> is the command used to add new books "
            "to the library.  This is seperate from <approve book> and "
            "should NOT be used for books that have been submitted to the "
            "library for review.  This command is available only to "
            "librarians and works in both public and private libraries.");
        break;

    case "restock book":

        write("\n\tUsage: restock book A Fool's Errand by Spiffy McQuick\n");
        write("<restock book> is used to increase the amount of copies that "
            "the library carries of a particular volume.  There is a cost "
            "of 2500 gold coins for every volume restocked for parchment, "
            "ink and materials.  As with other commands, the spelling of "
            "the book title and author alias must be EXACT before it will "
            "work.  <restock book> is for librarians only and works in both "
            "public and private libraries.");
        break;

    case "ban player":

        write("\n\tUsage: ban player dumbass\n");
        write("<ban player> is an OOC punishment for abusing the library "
            "system.  It is ONLY for OOC punishment, and not for IC "
            "restrictions.  It will block a player from using all libraries "
            "everywhere.");
        break;

    case "unban player":

        write("\n\tUsage: unban player reformeddumbass\n");
        write("<unban player> removes the OOC ban on said player and "
            "allows them to use the libraries again.");
        break;

    case "spawn book":

        write("\n\tUsage: spawn book A Fool's Errand by Spiffy McQuick\n");
        write("<spawn book> is used to create a book from the library "
            "without taking a copy off of the shelves.  This is useful for "
            "immortals who want to take copies to other libraries, or to "
            "just browse over the information inside without having to check "
            "the book out.");
        break;

    case "list banned":

        write("\n\tUsage: list banned\n");
        write("<list banned> returns a list of all the players that have "
            "been banned from using the libraries.  This command is for "
            "immortals only.");
        break;

    case "make library":

        write("\n\tUsage: make library Torm_Public_Library\n");
        write("<make library> will create a new library with the "
            "name specified.  BE CAREFUL with spelling and "
            "capitalization as this creates files on the hard "
            "drive which have to be removed manually to delete.  "
            "DO NOT use spaces, use underscores.");
        break;

    case "check out book":

        write("\n\tUsage: check out <title> by <author>\n");
        write("\n\tExample: check out A Fool's Errand by Spiffy McQuick\n");
        write("<check out book> is the command used to check out a book from "
            "a public library.  It can be used by anyone who isn't restricted "
            "from using the library.  Capitalization and spelling are important "
            "with this command.  The author alias and book title must match "
            "EXACTLY before it will work.  Color however, is not important.  "
            "Upon checking out a book, you will be charged a deposit.  The "
            "deposit is dependent on the library and your level.  If you "
            "return the book before its due date, you will get your deposit "
            "back, else the library will keep the money for restocking fees.  "
            "In the event that a book is lost due to pkill or adventuring "
            "mishap, you will not be able to check out another one until the "
            "library restocks the one you lost.  This will happen at the date "
            "it was due.  You are still free to check out books from different "
            "libraries however.  You are NOT ALLOWED to modify library books.  "
            "If the book is returned modified, you will not recieve your deposit "
            "back.  If you are the original author, and wish to update the "
            "contents of the book, see <update book>.");
        break;

    case "return book":

        write("\n\tUsage: return book, return book 2\n");
        write("<return book> is the command used to return a book that you "
            "have previously checked out.  If you have modified the book in "
            "ANY way since it was checked out, you will not get your deposit "
            "back.  If you are the original author and wish to update the "
            "book, see <update book>");
        break;

    case "submit book":

        write("\n\tUsage: submit book, submit book 2\n");
        write("<submit book> is the command used to submit a book of your "
            "own to the library for review.  The librarian will read over "
            "your book and decide if it meets the standards of their library.  "
            "If it does, they will accept the book and it will be placed on "
            "the shelves of the library for others to see.  If it does not "
            "It will be denied and placed back on a seperate shelf for you "
            "to make revisions or take elsewhere.  Note, books that contain "
            "blatant OOC abuse will be referred to immortals.  Don't do it.");
        break;

    case "retrieve book":

        write("\n\tUsage: retrieve book A Fool's Errand by Spiffy McQuick\n");
        write("<retrieve book> is the command used to retrieve a book that "
            "has been denied at the library.  It could have been denied for "
            "a number of reasons, you should see one of the librarians for "
            "an explaination.");
        break;

    case "list checked out":

        write("\n\tUsage: list checked out\n");
        write("<list checked out> returns a list of all the books from the "
            "library that are currently checked out.  It displays the date "
            "the book is due back at the library, and the title of the book.  "
            "This is useful if you can't find a copy of your favorite book, "
            "the library will restock the book by the due date if it is not "
            "returned.");
        break;

    case "list submitted":

        write("\n\tUsage: list submitted\n");
        write("<list submitted> returns a list of all the books that are "
            "currently up for review by the librarians.  It shows who "
            "submitted the book, the date and time it was submitted along "
            "with the title of the book and the author's alias. (Not "
            "necessiarily the same person who submitted it)  This command "
            "is for librarians only and only works in public libraries.  "
            "See <review book> for information on how to review the book "
            "and place it on the shelves of the library.");
        break;

    case "list denied":

        write("\n\tUsage: list denied\n");
        write("<list denied> returns a list of all the books that have "
            "been submitted to the library, reviewd by a librarian and "
            "denied.  They can be denied for many reasons including "
            "inappropriate content, bad grammar, IC politics, etc.  "
            "If you want to know the specific reason why your book "
            "was denied, contact one of the librarians.  See <retrieve book> "
            "if you want to recover a book that has been denied.");
        break;

    case "list restricted":

        write("\n\tUsage: list restricted\n");
        write("<list restricted> returns a list of all the players "
            "who have been restricted from using said public library.  "
            "This is an IC restriction placed because of IC events.  "
            "Contact a librarian to see about having the restriction "
            "lifted.  Different libraries will treat restricted people "
            "differently.  Some places you might recieve a stern glance "
            "for trying to use the library if you are restricted, while "
            "other places may escort you out of the library by force.");
        break;
  
    case "review book":

        write("\n\tUsage: review book A Fool's Errand by Spiffy McQuick\n");
        write("<review book> is the command used to review books that "
            "have been submitted by prospective authors.  This command is "
            "available to librarians only.  It is the responsibility of "
            "the librarian who reviews the book to check for OOC abuse "
            "and that the content of the book is up to the standard of their "
            "library.  If the book meets the standards then the librarian "
            "can <approve book> to have it placed on the shelves for people "
            "to use.  If the book does not meet the standards ICly for the "
            "library, then the librarian can <deny book>.  OOC abuse should "
            "be reported to an immortal, and NOT denied.  An accidental "
            "slip is not the same as abuse, keep this in mind, but it is "
            "ALWAYS better safe than sorry, so ask an immortal if there is "
            "any doubt.");
        break;

    case "approve book":

        write("\n\tUsage: approve book, approve book 2\n");
        write("<approve book> is the command used to approve a "
            "submitted book to the library if it meets all of the "
            "IC standards of said library and is free of OOC abuse.  "
            "This command is available to librarians only, and all "
            "librarians will be responsible for the material in the "
            "books that they have approved.");
        break;

    case "deny book":

        write("\n\tUsage: deny book, deny book 2\n");
        write("<deny book> is the command used to deny a book which "
            "does not meet the standards of the library it has been "
            "submitted to, or the librarian doesn't like the author.  "
            "IC political climate, etc.  If the book contains OOC abuse "
            "it must be brought to the attention of the immortans and "
            "NOT denied.  Just hang on to the book and contact an imm. "
            "If the book is denied do to the fact that it does not meet "
            "the standards, then the librarian can contact the person who "
            "submitted the book to let them know the reason why the book "
            "was denied.  Also, they could insert another page into the "
            "back of the book explaining the details of why it was "
            "denied.  The possibilities are endless.");
        break;

    case "restrict player":

        write("\n\tUsage: restrict player fred, restrict player hal\n");
        write("<restrict player> is the command used to restrict a player "
            "from using the library for IC reasons.  It can be used for "
            "people who continually forget to return their books by the "
            "due date, or for people who have poor relations with the city, "
            "etc.  This command is for librarians only.");
        break;

    case "unrestrict player":

        write("\n\tUsage: unrestrict player fred, unrestrict player hal\n");
        write("<unrestrict player> is the command used to remove a player "
            "from the restricted list at a library.  This could be because "
            "the player no longer has a bad relation with the library, etc.");
        break;

    case "list allowed":

        write("\n\tUsage: list allowed\n");
        write("<list allowed> brings up a list of all players allowed "
            "to use the private library.  Private libraries are different "
            "than public libraries, in that every person who the owner wishes "
            "to be able to use the private library must be allowed.  Much "
            "the same as public libraries, people who try to use private "
            "libraries they are not allowed to use might find alarms going "
            "off or traps sprung, guards called, etc.");
        break;

    case "take book":

        write("\n\tUsage: take book A Fool's Errand by Spiffy McQuick\n");
        write("<take book> is the command to take a book from a private "
            "library.  Capitalization and spelling are important, the author "
            "alias and the book title must match EXACTLY or it will not "
            "work.  This command is for those who have been allowed to "
            "use the specific private libary only.  If someone tries to "
            "take a book and they are not allowed, they may find themselves "
            "caught in a trap, or being rushed by guards.  Or they might "
            "simply take the book unnoticed.");
        break;

    case "replace book":

        write("\n\tUsage: replace book, replace book 2\n");
        write("<replace book> is the command used to return a book "
            "to the shelves of a private library.");
        break;

    case "allow player":

        write("\n\tUsage: allow player fred, allow player hal\n");
        write("<allow player> is the command used to allow people to "
            "use a private library.  All people who use a private library "
            "must be allowed else they will trigger any traps or alarms that "
            "the owner has put into place.  Only librarians for the specific "
            "private library can allow players.");
        break;

    case "unallow player":

        write("\n\tUsage: unallow player fred, unallow player hal\n");
        write("<unallow player> is the command used to remove a player "
            "from the allowed list at a private library.  This can be "
            "because the librarian no longer likes the player, they have "
            "done damage to the library, etc.  Only librarians at the "
            "library can use this command.");
        break;

    case "make librarian":

        write("\n\tUsage: make librarian name alias\n");
        write("<make librarian> makes a new librarian for the "
            "library with the alias specified.  The librarians are "
            "responsible for all books in their libraries, and are "
            "able to use many more of the library functions.");
        break;

    default :
        return 0;
    }

    return 1;

}
