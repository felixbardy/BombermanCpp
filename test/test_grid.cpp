#include <gtest/gtest.h>

#include "core/Grid.h"

using namespace BombermanCore;

TEST(Grid_getters, getTile) {
  Grid grid(10,11);

  for (int i = 0; i < 10*11; i++) {
    ASSERT_EQ(
      grid.getTile(i),
      grid.getTile(i%10,i/10)
    ) << "Something is wrong with Tile getters!";
  }

  ASSERT_EQ(
    grid.getHeight(),
    11
  ) << "Dafuk bro? (getHeight is wrong?)";

  ASSERT_EQ(
    grid.getWidth(),
    10
  ) << "Dafuk bro? (getWidth is wrong?)";
}

TEST(Grid_initialisation, borders) {
  Grid grid(10,10);

  for (int x = 0; x < grid.getWidth(); x++) {
    ASSERT_EQ(
      grid.getTile(x,0)->getMask(),
      TileType::UNBREAKABLE | TileContent::NOTHING
    ) << "Top tiles should be empty and unbreakable!";

    ASSERT_EQ(
      grid.getTile(x,10-1)->getMask(),
      TileType::UNBREAKABLE | TileContent::NOTHING
    ) << "Bottom tiles should be empty and unbreakable!";
  }

  for (int y = 0; y < grid.getHeight(); y++) {
    ASSERT_EQ(
      grid.getTile(0,y)->getMask(),
      TileType::UNBREAKABLE | TileContent::NOTHING
    ) << "Leftmost tiles should be empty and unbreakable!";

    ASSERT_EQ(
      grid.getTile(10-1,y)->getMask(),
      TileType::UNBREAKABLE | TileContent::NOTHING
    ) << "Rightmost tiles should be empty and unbreakable!";
  }

}
