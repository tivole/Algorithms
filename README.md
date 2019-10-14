# Prim's Minimum Spanning Tree

In computer science, <b>Prim's</b> (also known as <b>Jarník's</b>) algorithm is a <i>greedy algorithm</i> that finds a <i>minimum spanning tree</i> for a <i>weighted undirected graph</i>. This means it finds a subset of the edges that forms a tree that includes every vertex, where the total weight of all the edges in the tree is minimized. The algorithm operates by building this tree one vertex at a time, from an arbitrary starting vertex, at each step adding the cheapest possible connection from the tree to another vertex.

<p align="center">
  <img src="img/PrimAlgDemo.gif">
</p>


## Description

The algorithm may informally be described as performing the following steps:

1. Initialize a tree with a single vertex, chosen arbitrarily from the graph.
2. Grow the tree by one edge: of the edges that connect the tree to vertices not yet in the tree, find the minimum-weight edge, and transfer it to the tree.
3. Repeat step 2 (until all vertices are in the tree).


## Time complexity

The time complexity of Prim's algorithm depends on the data structures used for the graph and for ordering the edges by weight, which can be done using a <i>priority queue</i>. The following table shows the typical choices:

| Minimum edge weight data structure	     | Time complexity (total)      
| ------------- | ------------- |
| adjacency matrix, searching         | ![adjacency matrix, searching](img/formula_1.svg)      |
| binary heap and adjacency list        | ![binary heap and adjacency list](img/formula_2.svg)  |
| Fibonacci heap and adjacency list        | ![Fibonacci heap and adjacency list](img/formula_3.svg)  |


## Example

| Input Graph	     | Output Graph |      
| ------------- | ------------- |
| ![Input Graph](img/graph_input.png)        | ![Output Graph](img/graph_output.png)  |


## Illustration of graph in program

<p align="center">
  <b>Input Graph</b>
  <br/><br/>
  <img src="img/input.png">
</p>

<p align="center">
  <b>Output Graph</b>
  <br/><br/>
  <img src="img/input.png">
</p>