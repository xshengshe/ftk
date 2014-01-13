/*This file is generated by luagen.*/
#include "lua_ftk_button.h"
#include "lua_ftk_callbacks.h"

static void tolua_reg_types (lua_State* L)
{
	tolua_usertype(L, "FtkButton");
}

static int lua_ftk_button_create(lua_State* L)
{
	tolua_Error err = {0};
	FtkButton* retv;
	FtkWidget* parent;
	int x;
	int y;
	int width;
	int height;
	int param_ok = tolua_isusertype(L, 1, "FtkWidget", 0, &err) && tolua_isnumber(L, 2, 0, &err) && tolua_isnumber(L, 3, 0, &err) && tolua_isnumber(L, 4, 0, &err) && tolua_isnumber(L, 5, 0, &err);

	return_val_if_fail(param_ok, 0);

	parent = tolua_tousertype(L, 1, 0);
	x = tolua_tonumber(L, 2, 0);
	y = tolua_tonumber(L, 3, 0);
	width = tolua_tonumber(L, 4, 0);
	height = tolua_tonumber(L, 5, 0);
	retv = ftk_button_create(parent, x, y, width, height);
	tolua_pushusertype(L, (FtkButton*)retv, "FtkButton");

	return 1;
}

static int lua_ftk_button_set_clicked_listener(lua_State* L)
{
	tolua_Error err = {0};
	Ret retv;
	FtkWidget* thiz;
	char* listener;
	int param_ok = tolua_isusertype(L, 1, "FtkWidget", 0, &err) && tolua_isstring(L, 2, 0, &err);

	return_val_if_fail(param_ok, 0);

	thiz = tolua_tousertype(L, 1, 0);
	listener = (char*)tolua_tostring(L, 2, 0);
	retv = ftk_button_set_clicked_listener(thiz, lua_ftk_widget_listener_func, listener);
	tolua_pushnumber(L, (lua_Number)retv);

	return 1;
}

int tolua_ftk_button_init(lua_State* L)
{
	tolua_open(L);
	tolua_reg_types(L);
	tolua_module(L, NULL, 0);
	tolua_beginmodule(L, NULL);
	tolua_cclass(L,"FtkButton", "FtkButton", "FtkWidget", NULL);
	tolua_beginmodule(L, "FtkButton");
	tolua_function(L, "Create", lua_ftk_button_create);
	tolua_function(L, "SetClickedListener", lua_ftk_button_set_clicked_listener);
	tolua_endmodule(L);
	tolua_endmodule(L);


	return 1;
}
