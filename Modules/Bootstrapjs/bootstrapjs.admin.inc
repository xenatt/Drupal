<?php

/**
 * @file
 * Serves administrative pages for the Bootstrap.js module
 */

function bootstrapjs_admin_settings($form, &$form_state) {
     $json = drupal_http_request('http://api.bootswatch.com/3/');
	 $bjs_themes = drupal_json_decode($json->data);
     //drupal_add_js('var bootswatch = ' .$json->data ,'inline');
	 $l_theme = array( "Default" => "Default","None" => "None");
	 foreach($bjs_themes['themes'] as $l) {
		 $cdn = str_replace('//','http://',$l['cssCdn']);
		 $l_theme[$cdn] = 'Bootswatch ' . $l['name'];
	 } 
  	$form['bootstrapjs_theme'] = array(
  	    '#type' => 'select',
  	    '#title' => t('Bootstrap Themes'),
  	    '#options' => $l_theme,
  	    '#default_value' => variable_get('bootstrapjs_theme'),
  	    '#description' => t('Select Twitter Bootstrap Theme.'),
		'#markup' => '<div id="theme-thumb"></div>'
  	  );
/* 	$form['bootstrapjs_version'] = array(
 	    '#type' => 'select',
 	    '#title' => t('Bootstrap Version'),
 	    '#options' => array(
 	      '3.1.0' => t('Version 3.1.0'),
 	      '3.0.2' => t('3.0.2'),
 	    ),
 	    '#default_value' => variable_get('bootstrapjs_version'),
 	    '#description' => t('Select Twitter Bootstrap version.'),
 	  );
*/
   	$form['bootstrapjs_source'] = array(
   	    '#type' => 'select',
   	    '#title' => t('Bootstrap Version'),
   	    '#options' => array(
   	      'Libraries' => t('Folder all/libraries'),
   	      'CDN' => t('Twitter Boot CDN'),
   	    ),
   	    '#default_value' => variable_get('bootstrapjs_source'),
   	    '#description' => t('Select Twitter Bootstrap Source.'),
   	  );
      return system_settings_form($form);
 }
 
