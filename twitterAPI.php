<?php  
session_start();  
require_once("twitteroauth/twitteroauth/twitteroauth.php"); //Path to twitteroauth library you downloaded in step 3  
  
$twitteruser = "w3resource"; //user name you want to reference  
$notweets = 2; //how many tweets you want to retrieve  
$consumerkey = "sqrzNfTYAhdKKFe8i0jkbmfJc";  
$consumersecret = "UY4UiIjYTuB4Z09Kh5ZeC8nA1M9rPT9VNNutZa8wPivVCj6SoV";   
$accesstoken = "217674868-6jGUXSmNd1ldEgPm19Ms0sOVd1NWHlqOPOvDjD1Z";   
$accesstokensecret = "KehU1HYSmeo5JrNhlWbPrqXPaVWJMr2gi72UINuaDAufQ";   
  
function getToken($cons_key, $cons_secret, $oauth_token, $oauth_token_secret) {  
  $connection = new TwitterOAuth($cons_key, $cons_secret, $oauth_token, $oauth_token_secret);  
  return $connection;  
}  
  
$connection = getToken($consumerkey, $consumersecret, $accesstoken, $accesstokensecret);  
  
$tweets = $connection->get("https://api.twitter.com/1.1/statuses/user_timeline.json?screen_name=".$twitteruser."&count=".$notweets);  
  
echo json_encode($tweets);  
//echo $tweets; //testing remove for production     
?>  