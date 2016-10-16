/*
* Programmer: Edward Moon
* 10/15/16
*/
package cardgame;

import java.awt.image.BufferedImage;
import java.io.File;
import java.io.IOException;
import java.security.SecureRandom;
import javax.imageio.ImageIO;

/**
 *
 * @author Emoon_000
 */
public class DeckOfCards 
{
    private final Card[] deck;
    private int currentCard;    //The Index of the next card to be dealt
    
   
   /**
    * Constructor to build a deck of cards
     * @throws java.io.IOException
    */ 
    
    public DeckOfCards() throws IOException
    {
        
        String[] faces = {"2","3","4","5","6","7","8","9","10","Jack","Queen","King","Ace"};
        String[] suits = {"Spades","Clubs","Diamonds","Hearts"};
        
        deck = new Card[52];
        currentCard = 0;
               
        
        //Information used to extract individual cards from 1 image holing all
        //The Cards
        final int width = 123;
        final int height = 172;
        final int rows = 4;
        final int cols = 13;
        
        
        BufferedImage bigImage = ImageIO.read(new File("card-deck-01.jpg"));
        BufferedImage tempCardImage = null;
        
        
        for (int suit = 0; suit < 4; suit++)
        {
              for (int faceNum = 0; faceNum < 13; faceNum++)
              {
                
                //extract the image
                tempCardImage = bigImage.getSubimage(
                        faceNum*width + (faceNum*9),           //Starting X Coordinate
                        suit*height + (suit*14),               //Starting Y Coordinate
                        width,                                 //Width of the image
                        height);                               //Height of the image
                        
                 
              //Building an array
              deck[(faceNum + (suit*13))] = new Card(
                      suits[suit],            //calls the suits array to get the name of the suit
                      faces[faceNum],         //Calls the faces array to get the face name
                      faceNum+2,              //value of the card as an Int
                      tempCardImage);         //Image of the card
                    
            }
        
        }
    }
    //End of the constructor
    public void displayDeck()
    {
        
        for (Card card : deck)                //Traverses over deck of cards for each position
            System.out.println(card);        //Print card on new line
    }
    
    public void shuffle()
    {
       
        currentCard = 0;
        
        SecureRandom randomNumber = new SecureRandom();
        
       //for each card in the deck, pick another random card and swap them
       for (int first = 0; first < deck.length; first++)
       {
            //select a random card     
           int second = randomNumber.nextInt(52);
           
           //swap the cards
           Card temp = deck[first];
           deck[first] = deck[second];
           deck[second] = temp;
           
       }
       
       
    } //end of method shuffle
    
    /**
     * This will deal a card off the deck and advance the currentCard instance
     * variable
     * @return the top Card on the deck
     */
    public Card dealCard()
    {
        if(currentCard < deck.length)
            return deck[currentCard++];     //returns current card and increment count
        else
            return null;
    }
    
    
    public static void main(String [] args) throws IOException
    {
        
        DeckOfCards theDeck = new DeckOfCards();
        theDeck.displayDeck();
        
        theDeck.shuffle();
        System.out.println("\nAfter shuffling, the deck looks like: ");
        theDeck.displayDeck();
    }
    
    /**
     * This method will shuffle the Card objects in the deck
     */
    
  
    
    
}//end of class
    
    

