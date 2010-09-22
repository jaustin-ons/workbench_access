<?php

/**
 * Implements hook_views_data().
 */
function workbench_access_views_data() {
  $data = array();
  $data['workbench_access']['table']['group']  = t('Workbench Access');
  $data['workbench_access']['edit'] = array(
    'title' => t('Edit link'),
    'help' => t('A link to edit the node.'),
    'field' => array(
      'handler' => 'workbench_access_handler_field_edit_node',
      'click sortable' => FALSE,
    ),
  );
  $data['workbench_access']['section'] = array(
    'title' => t('Section'),
    'help' => t('The section to which this node belongs.'),
    'field' => array(
      'handler' => 'workbench_access_handler_field_section',
      'click sortable' => FALSE,
    ),
  );
  $data['workbench_access']['filter'] = array(
    'title' => t('Access filter'),
    'help' => t('Filter nodes by access level.'),
    'filter' => array(
      'handler' => 'workbench_access_handler_filter_access',
    ),
  );
  $data['workbench_access']['table']['join'] = array(
    //...to the node table
    'node' => array(
      'left_field' => 'nid',
      'field' => 'nid',
    ),
  );
  return $data;
}

function workbench_access_views_handlers() {
  return array(
    'info' => array(
      'path' => drupal_get_path('module', 'workbench_access') . '/includes',
    ),
    'handlers' => array(
      'workbench_access_handler_field_edit_node' => array(
        'parent' => 'views_handler_field',
      ),
      'workbench_access_handler_field_section' => array(
        'parent' => 'views_handler_field',
      ),
      'workbench_access_handler_filter_access' => array(
        'parent' => 'views_handler_filter',
      ),
    ),
  );
}