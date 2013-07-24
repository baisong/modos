<?php

/**
 * @file
 * Page includes for ModOS module.
 */

 /**
  * Tries to run the specified update.
  */
function modos_invoke_update_page($module, $id) {
  if (!$module) {
    return "No module specified";
  }
  if (!$id) {
    return "No update ID specified";
  }
  if (!module_exists($module)) {
    return "Module not enabled: " . $module;
  }
  $module_path = drupal_get_path('module', $module);
  $install_file = "$module_path/$module.install";
  if (file_exists($install_file)) {
    include_once ($install_file);
  }
  $update_function = $module . '_update_' . $id;
//  if (!function_exists($update_function)) {
//    call_user_func_array($update_function);
//    return "Successfully invoked function: " . $update_function;
//  }
//  return "Failed to invoke function: " . $update_function;

  try {
    $update_function();
    return "Successfully invoked function: " . $update_function;
  } catch (Exception $e) {
    return "Failed to invoke function: " . $update_function . '<br/>' . $e->getMessage();
  }
}