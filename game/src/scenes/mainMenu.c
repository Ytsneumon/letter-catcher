#include "mainMenu.h"
#include "../main.h"
#include "../types.h"
#include "common.h"
#include "raylib.h"

void drawTitle() {
  const char title[15] = "LETTER CATCHER";
  Vector2 titleDimensions = MeasureTextEx(font, title, font.baseSize, 4);
  Vector2 ribbonPosition = {(GetScreenWidth() / 2) - (titleDimensions.x / 2), 30};

  float marginX = 15.0f;
  float marginY = 10.0f;
  Rectangle ribbonDestiny = {round(ribbonPosition.x - marginX), ribbonPosition.y - marginY, titleDimensions.x + marginX * 2, titleDimensions.y + marginY * 2};
  DrawTextureNPatch(ribbonTexture, ribbonNPatchInfo, ribbonDestiny, (Vector2){0, 0}, 0.0f, WHITE);
  DrawTextEx(font, title, ribbonPosition, font.baseSize, 4, BLACK);
}

void drawLanguageSelection(Bounty *bounty, Language language) {
  Vector2 ribbonDimensions = {250.0, 200.0};
  Vector2 ribbonPosition = {(GetScreenWidth() / 2) - (ribbonDimensions.x / 2), 150};

  float marginX = 15.0f;
  float marginY = 10.0f;
  Rectangle ribbonDestiny = {round(ribbonPosition.x - marginX), ribbonPosition.y - marginY, ribbonDimensions.x + marginX * 2, ribbonDimensions.y + marginY * 2};
  DrawTextureNPatch(ribbonTexture, ribbonNPatchInfo, ribbonDestiny, (Vector2){0, 0}, 0.0f, WHITE);
  Vector2 esFlagPosition = {ribbonPosition.x + 120, ribbonPosition.y + 20};
  DrawTexture(esFlag, esFlagPosition.x, esFlagPosition.y, WHITE);
  Vector2 deFlagPosition = {ribbonPosition.x + 120, ribbonPosition.y + 120};
  DrawTexture(deFlag, deFlagPosition.x, deFlagPosition.y, WHITE);
  Rectangle markerDestiny;
  bounty->bounds.x = ribbonPosition.x + 40;
  if (language == ES) {
    markerDestiny = (Rectangle){esFlagPosition.x - 13, esFlagPosition.y - 10, 122, 86};
    bounty->bounds.y = esFlagPosition.y + 30;
  } else {
    markerDestiny = (Rectangle){deFlagPosition.x - 13, deFlagPosition.y - 10, 122, 86};
    bounty->bounds.y = deFlagPosition.y + 30;
  }
  drawBounty(bounty);
  drawSpriteNPatch(markerSprite, markerDestiny, markerNPatchInfo);
}

void drawMainMenu(GameState gameState) {
  BeginDrawing();

  ClearBackground(RAYWHITE);

  drawBackground();
  drawTitle();
  drawLanguageSelection(gameState.bounty, gameState.language);

  EndDrawing();
}