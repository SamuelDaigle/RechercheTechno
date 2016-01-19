﻿using UnityEngine;

namespace Assets.Scripts.LevelComponents.Terrains
{
    public class TerrainRestore : MonoBehaviour
    {
        private Terrain terrain;
        private int terrainWidth;
        private int terrainHeight;

        void Start()
        {
            terrain = Terrain.activeTerrain;
            terrainWidth = terrain.terrainData.heightmapWidth;
            terrainHeight = terrain.terrainData.heightmapHeight;
        }

        void Update()
        {
            if (Input.GetKeyDown(KeyCode.P))
            {
                RestoreTerrain();
            }
        }

        public void RestoreTerrain()
        {
            Debug.Log("Restored terrain.");
            float[,] heights = terrain.terrainData.GetHeights(0, 0, terrainWidth, terrainHeight);
            for (int i = 0; i < terrainWidth; i++)
            {
                for (int j = 0; j < terrainHeight; j++)
                {
                    heights[j, i] = 0;
                }
            }
            terrain.terrainData.SetHeights(0, 0, heights);
        }
    }
}