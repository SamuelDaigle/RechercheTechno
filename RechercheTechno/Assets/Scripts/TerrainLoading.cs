using UnityEngine;
using System.Collections;
using System.Collections.Generic;

public class TerrainLoading : MonoBehaviour
{
    public float Amplitude = 3f;

    private Terrain terrain;
    private float[,] heights;
    private int sizeX;
    private int sizeY;

    private const int MAX_RECURSIVE_LEVEL = 9;

    void Start()
    {
        terrain = Terrain.activeTerrain;
        sizeX = terrain.terrainData.heightmapWidth;
        sizeY = terrain.terrainData.heightmapHeight;
        heights = GetTerrainHeights();
        sizeX--; sizeY--; // for further loops.

        RaiseTerrain();
        CreateMountains();

        SetTerrainHeights(heights);
    }

    private void RaiseTerrain()
    {
        Debug.Log("Raising Terrain..");
        for (int x = 0; x < sizeX; x++)
        {
            for (int y = 0; y < sizeY; y++)
            {
                heights[y, x] = 0;
            }
        }
    }

    private void CreateMountains()
    {
        Debug.Log("Started creating mountains..");
        float min = 0.05f;
        float max = 0.05f;
        SetEmptyHeight(0, 0, Random.Range(min, max));
        SetEmptyHeight(0, sizeY, Random.Range(min, max));
        SetEmptyHeight(sizeX, 0, Random.Range(min, max));
        SetEmptyHeight(sizeX, sizeY, Random.Range(min, max));
        DiamondSquare(0, 0, sizeX, sizeY, 0.001f, MAX_RECURSIVE_LEVEL);
        Debug.Log("Done.");
    }

    private void DiamondSquare(int _left, int _top, int _right, int _bottom, float base_height, int _recursiveLevel)
    {
        if (_recursiveLevel == 0) return;

        // Set the Center point of the Diamond step.
        int xCenter = (int)Mathf.Floor(_left + _right) / 2;
        int yCenter = (int)Mathf.Floor(_top + _bottom) / 2;
        float centerPointHeight = (GetHeight(_left, _top) + GetHeight(_right, _top) + GetHeight(_left, _bottom) + GetHeight(_right, _bottom)) / 4;
        SetEmptyHeight(xCenter, yCenter, centerPointHeight + ((Random.value - 0.5f) * base_height * Mathf.Pow(_recursiveLevel, Amplitude)));

        // Set the four corners of the Square step.
        SetEmptyHeight(xCenter, _top, (GetHeight(_left, _top) + GetHeight(_right, _top)) / 2);
        SetEmptyHeight(xCenter, _bottom, (GetHeight(_left, _bottom) + GetHeight(_right, _bottom)) / 2);
        SetEmptyHeight(_left, yCenter, (GetHeight(_left, _top) + GetHeight(_left, _bottom)) / 2);
        SetEmptyHeight(_right, yCenter, (GetHeight(_right, _top) + GetHeight(_right, _bottom)) / 2);

        // Call smaller regions.
        DiamondSquare(_left, _top, xCenter, yCenter, base_height, _recursiveLevel - 1);
        DiamondSquare(xCenter, _top, _right, yCenter, base_height, _recursiveLevel - 1);
        DiamondSquare(_left, yCenter, xCenter, _bottom, base_height, _recursiveLevel - 1);
        DiamondSquare(xCenter, yCenter, _right, _bottom, base_height, _recursiveLevel - 1);
    }

    private float[,] GetTerrainHeights()
    {
        return terrain.terrainData.GetHeights(0, 0, sizeX, sizeY);
    }

    private void SetTerrainHeights(float[,] _heights)
    {
        terrain.terrainData.SetHeights(0, 0, _heights);
    }

    private float GetHeight(int _x, int _y)
    {
        return heights[_y, _x];
    }

    private void SetEmptyHeight(int _x, int _y, float _value)
    {
        if (heights[_y, _x] == 0)
        {
            heights[_y, _x] = _value;
        }
    }
}
