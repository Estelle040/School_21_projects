TELEGRAM_BOT_TOKEN=8117450377:AAEOe8pwewYbwFxe5fPXBcVDDXMWhVREETM
TELEGRAM_USER_ID=1754401937
TIME="10"
if [ "$CI_JOB_STATUS" == "success" ]; then
  MESSAGE="Done ✅"
else
  MESSAGE="Error 🚫"
fi
URL="https://api.telegram.org/bot$TELEGRAM_BOT_TOKEN/sendMessage"
TEXT="$1 %0AStatus: ${MESSAGE} %0A%0AProject:+$CI_PROJECT_NAME%0AURL:+$CI_PROJECT_URL/pipelines/$CI_PIPELINE_ID/%0ABranch:+$CI_COMMIT_REF_SLUG"

curl -s --max-time $TIME -d "chat_id=$TELEGRAM_USER_ID&disable_web_page_preview=1&text=$TEXT" $URL > /dev/null
