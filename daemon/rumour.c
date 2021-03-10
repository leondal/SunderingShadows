#include <std.h>
#include <security.h>
#include <daemons.h>
#include "/daemon/rumours/sources.h"
#define SAVE_DIR "/daemon/save/rumours/" 
#define SAVE_FILE "/daemon/save/saved_rumours" 

inherit DAEMON;


string surface;
string detail;
string secret;
string * instigator;
string truename;

string query_surface();
string query_detail();
string query_secret();
string instigator();
string query_truename();

void set_surface(string surf);
void set_detail(string det);
void set_secret(string sec);
void set_instigator(string * inst);
void set_truename(string tn);

string query_surface(){
  return surface;
}

string query_detail(){
  return detail;
}

string query_secret(){
  return secret;
}

string * query_instigator(){
  return instigator;
}

void query_truename(){
  return truename;
}

void set_surface(string surf){
  surface = surf;
}

void set_detail(string det){
  detail = det;
}

void set_secret(string sec){
  secret = sec;
}

void set_instigator(string * inst){
  instigator = inst;
}

void set_truename(string tn){
  truename = tn;
}

void SAVE(string filename){
    seteuid(UID_DAEMONSAVE);
    save_object(filename);
    seteuid(getuid());
    return;
}

void LOAD(string filename){
  seteuid(UID_DAEMONSAVE);
  restore_object(filename,1);
  seteuid(getuid());
}
