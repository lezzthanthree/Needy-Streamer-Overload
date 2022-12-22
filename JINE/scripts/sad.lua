function Initialize()
    -- add a new ame JINE chat here.
        a = {
                "stop crying idiot!!!",
                "youre gonna make me cry too :(",
                "ugh that face pisses me off",
                "im gonna punch you",
                "you wont get out of this by crying!",
                "ugh",
                "i hate that sticker",
                ";-;",
                "spare me the tears.",
                 "dont :( me ill punch you!!!",
            }
end

function Update()
    math.randomseed(os.time())
    math.random(); math.random(); math.random()

-- Randomizes from the JINE chats.
    return a[math.random(1,#a)]
end