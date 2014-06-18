#ifndef SHOW_TOPONAV_MAP_H
#define SHOW_TOPONAV_MAP_H

#include <string>
#include <map>
#include <algorithm> //std::find
#include <ros/ros.h>
#include <visualization_msgs/Marker.h>
#include <visualization_msgs/MarkerArray.h>

#include "show_toponav_map.h"
#include "toponav_node.h"
#include "toponav_edge.h"
#include "st_navigation/GotoNodeActionFeedback.h"

/*
 * @file show_toponav_map
 * @brief This class will take care of visualization of the Topological Navigation Map as build in the class TopoNavMap
 * @author Koen Lekkerkerker
 */

class ShowTopoNavMap
{

public:
  ShowTopoNavMap(ros::NodeHandle &n, const TopoNavNode::NodeMap &nodes, const TopoNavEdge::EdgeMap &edges, const TopoNavNode::NodeID &associated_node); //Constructor
  /**
   * Public Methods
   */
  void updateVisualization();

private:
  /**
   * Variables
   */
  ros::NodeHandle &n_;
  const TopoNavNode::NodeMap &nodes_;
  const TopoNavEdge::EdgeMap &edges_;
  const TopoNavNode::NodeID  &associated_node_;

  std::vector<TopoNavNode::NodeID> topo_path_nodes_;
  std::vector<TopoNavEdge::EdgeID> topo_path_edges_;

  visualization_msgs::Marker nodes_marker_template_;
  visualization_msgs::Marker edges_marker_template_;
  visualization_msgs::Marker doors_marker_template_;
  visualization_msgs::MarkerArray toponavmap_ma_;

  ros::Publisher markers_pub_;
  ros::Subscriber movebasetopo_feedback_sub_;

  /**
   * Private Methods
   */
  void visualizeNodes();
  void visualizeEdges();
  void moveBaseTopoFeedbackCB (const st_navigation::GotoNodeActionFeedback feedback);
};

#endif // SHOW_TOPONAV_MAP_H
