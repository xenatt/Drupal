<?php
function bootstrapjs_libraries_info() {
$libraries['bootstrap'] = array(
    'name' => 'Bootstrap',
    'vendor url' => 'http://getbootstrap.com/',
    'download url' => 'http://getbootstrap.com/getting-started/#download',
    'path' => 'js',
	'version' => '3.10',
    'files' => array(
      'js' => array('js/bootstrap.min.js'),
	  'css' => array('css/bootstrap.min.css'),
    ),
  );
  return $libraries;
}