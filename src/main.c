#include "declarations/declarations.h"
#include "object/object.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Color {
  u8 r;
  u8 g;
  u8 b;
  u8 a;
};

///@brief example of class usage
class Window {

  u32 width;
  u32 height;
  char *title;
  struct Color backgroundColor;

  struct Color fn(get_color)(class Window *self);
  void fn(new)(class Window *self, u32 width, u32 height, const char *title);
  void fn(set_color)(class Window *self, u8 r, u8 g, u8 b, u8 a);
  void fn(set_width)(class Window *self, u32 width);
  void fn(set_height)(class Window *self, u32 height);
  u32 fn(get_width)(class Window *self);
  u32 fn(get_height)(class Window *self);
  void fn(set_title)(class Window *self, const char *newTitle);
  char *fn(get_title)(class Window *self);
  void fn(destruct)(class Window *self);
};

void set_color extends(Window)(class Window *self, u8 r, u8 g, u8 b, u8 a) {
  self->backgroundColor.r = r;
  self->backgroundColor.g = g;
  self->backgroundColor.b = b;
  self->backgroundColor.a = a;
}

void set_width extends(Window)(class Window *self, u32 width) {

  instanceof (set_width);
  self->width = width;
}

void set_height extends(Window)(class Window *self, u32 height) {
  instanceof (set_height);
  self->height = height;
}

void set_title extends(Window)(class Window *self, const char *newTitle) {
  self->title = strcpy(self->title, newTitle);
}

struct Color get_color extends(Window)(class Window *self) {
  return self->backgroundColor;
}

u32 get_width extends(Window)(class Window *self) { return self->width; }

u32 get_height extends(Window)(class Window *self) { return self->height; }

char *get_title extends(Window)(class Window *self) { return self->title; }

void destruct extends(Window)(class Window *self) { free(self->title); }

/// @brief Methods declared in the body using the
/// "declare" macro are public.
/// Methods are private by default.
void public extends(Window)(class Window *self) {
  declare(self, get_color);
  declare(self, set_color);
  declare(self, set_width);
  declare(self, get_width);
  declare(self, set_height);
  declare(self, get_height);
  declare(self, get_title);
  declare(self, set_title);
  declare(self, destruct);
}

void private extends(Window)(class Window *self) {

  omit(self, get_height);
  omit(self, get_width);
}

void new extends(Window)(class Window *self, u32 width, u32 height,
                         const char *title) {

  public(self);
  private(self);
  self->height = height;
  self->width = width;
  size_t titleLen = strlen(title);
  self->title = (char *)malloc(sizeof(char) * (titleLen + 1));
  self->title = strcpy(self->title, title);
  printf("Window with title %s initialized!\n", self->title);

  return;
}

s32 main(s32 argc, char **argv) {

  (void)argc;
  (void)argv;
  class Window window = {0};

  new (&window, 400, 300, "My window");
  u32 height = window.get_height(&window);
  u32 width = window.get_width(&window);

  printf("Width = %d, Height = %d\n", height, width);
  window.destruct(&window);
  return 0;
}