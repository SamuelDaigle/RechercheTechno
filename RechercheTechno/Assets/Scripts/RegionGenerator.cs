using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace Assets.Scripts
{
    public class RegionGenerator
    {
        Region[,] regions;
        int terrainSizeX;
        int terrainSizeY;
        public Region[,] GenerateRegions(int _terrainSizeX, int _terrainSizeY)
        {
            regions = new Region[_terrainSizeX, _terrainSizeY];
            terrainSizeX = _terrainSizeX;
            terrainSizeY = _terrainSizeY;
            FloodFill(0, 0, new Mountain(), 60);
            return regions;
        }

        private void FloodFill(int _x, int _y, Region _region, int _percentage)
        {
            if (_percentage <= 0) return;
            if (_x > terrainSizeX || _x < 0 || _y > terrainSizeY || _y < 0) return;
            regions[_x, _y] = _region;
            FloodFill(_x, _y + 1, _region, --_percentage);
            FloodFill(_x, _y - 1, _region, --_percentage);
            FloodFill(_x + 1, _y, _region, --_percentage);
            FloodFill(_x - 1, _y, _region, --_percentage);
        }
    }
}
